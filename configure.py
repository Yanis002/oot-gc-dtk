#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

### Game versions

# Note: update ``.vscode/c_cpp_properties.json``'s defines
# when updating this list

VERSIONS = [
    "mq-j",  # 0
    "mq-u",  # 1
    "mq-e",  # 2
    "ce-j",  # 3
    "ce-u",  # 4
    "ce-e",  # 5
]

DEFAULT_VERSION = VERSIONS.index("mq-j")

### Script's arguments

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.lower,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
    default=True,
)
parser.add_argument(
    "--no-asm",
    action="store_true",
    help="don't incorporate .s files from asm directory",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
    default=True,
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)

args = parser.parse_args()

### Create new project configuration

config = ProjectConfig()
config.version = args.version.lower()
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.debug = args.debug
config.generate_map = args.map
config.sjiswrap_path = args.sjiswrap

if not is_windows():
    config.wrapper = args.wrapper

if args.no_asm:
    config.asm_dir = None

### Tool versions

config.binutils_tag = "2.42-1"
config.compilers_tag = "20231018"
config.dtk_tag = "v0.8.2"
config.sjiswrap_tag = "v1.1.1"
config.wibo_tag = "0.6.11"

### Project

config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"

### Flags (same as zeldaret/oot-gc)

config.asflags = [
    "-mgekko",
    "-I include",
    "-I libc",
    f"-I build/{config.version}/include",
]

config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-warn off"
]

# ``-DMQ_J=0 -DMQ_U=1, ...``
version_defines = " ".join(f"-D{version.replace('-', '_').upper()}={i}" for i, version in enumerate(VERSIONS))

cflags_base = [
    "-Cpp_exceptions off",
    "-proc gekko",
    "-fp hardware",
    "-fp_contract on",
    "-enum int",
    "-align powerpc",
    "-nosyspath",
    "-RTTI off",
    "-str reuse",
    "-multibyte",
    "-O4,p",
    "-inline auto",
    "-nodefaults",
    "-msgstyle gcc",

    # includes and macros
    "-i include",
    "-i libc",
    f"-i build/{config.version}/include",
    f"{version_defines}",
    f"-DVERSION={version_num}",
    f"-DDOLPHIN_REV={2002 if version_num == VERSIONS.index('mq-j') else 2003}",
]

# Debug flags
if config.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# SIM flags
cflags_sim = [
    *cflags_base,
    "-inline auto,deferred",
]

# Dolphin SDK/Libraries flags
cflags_dolphin = [
    *cflags_base,
]

# Metrowerks library flags (TBD)
cflags_runtime = [
    *cflags_base,
    "-msgstyle gcc",
    # "-use_lmw_stmw on",
    # "-str reuse,pool,readonly",
    # "-gccinc",
    # "-common off",
    "-inline auto,deferred",
]

# Set linker version to use
config.linker_version = "GC/1.1"

### Helper functions

# for SIM objects (the emulator files)
def SIM(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    if lib_name == "Core" and version_num != VERSIONS.index("ce-e") and version_num != VERSIONS.index("mq-e"):
        # MQ/CE PAL contains extra files
        objects.pop(3) # "emulator/xlText.c"
        objects.pop(5) # "emulator/xlFile.c"

    return {
        "lib": lib_name,
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "host": False,
        "objects": objects,
    }

# Helper function for THP objects inside the emulator folders
def THP(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": config.linker_version,
        "cflags": cflags_dolphin,
        "host": False,
        "objects": objects,
    }

# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin,
        "host": False,
        "objects": objects,
    }

# Helper function for libraries sharing the same informations
def GenericLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_runtime,
        "host": False,
        "objects": objects,
    }

### Link order

Matching = True
NonMatching = False

config.warn_missing_config = True
config.warn_missing_source = False

config.libs = [
    SIM(
        "Core",
        [
            Object(Matching, "emulator/xlCoreGCN.c"),
            Object(Matching, "emulator/xlPostGCN.c"),
            Object(Matching, "emulator/xlFileGCN.c"),
            Object(Matching, "emulator/xlText.c"),
            Object(Matching, "emulator/xlList.c"),
            Object(Matching, "emulator/xlHeap.c"),
            Object(Matching, "emulator/xlFile.c"),
            Object(Matching, "emulator/xlObject.c"),
        ]
    ),
    SIM(
        "Fire",
        [
            Object(NonMatching if version_num == VERSIONS.index("ce-e") or version_num == VERSIONS.index("mq-e") else Matching, "emulator/simGCN.c"),
            Object(Matching, "emulator/movie.c"),
        ]
    ),
    THP(
        "THP",
        [
            # NOTE: these files should be in the THP lib
            Object(Matching, "emulator/THPPlayer.c"),
            Object(Matching, "emulator/THPAudioDecode.c"),
            Object(Matching, "emulator/THPDraw.c"),
            Object(Matching, "emulator/THPRead.c", cflags=[*cflags_dolphin, "-inline auto,deferred"]),
            Object(Matching, "emulator/THPVideoDecode.c"),
        ]
    ),
    SIM(
        "Fire",
        [
            Object(NonMatching, "emulator/mcardGCN.c"),
            Object(Matching, "emulator/codeGCN.c"),
            Object(NonMatching, "emulator/soundGCN.c"),
            Object(NonMatching, "emulator/frame.c"),
            Object(Matching, "emulator/system.c"),
            Object(NonMatching, "emulator/cpu.c"),
            Object(Matching, "emulator/pif.c"),
            Object(Matching, "emulator/ram.c"),
            Object(Matching, "emulator/rom.c"),
            Object(Matching, "emulator/rdp.c"),
            Object(Matching, "emulator/rdb.c"),
            Object(NonMatching, "emulator/rsp.c"),
            Object(Matching, "emulator/mips.c"),
            Object(Matching, "emulator/disk.c"),
            Object(Matching, "emulator/flash.c"),
            Object(Matching, "emulator/sram.c"),
            Object(Matching, "emulator/audio.c"),
            Object(Matching, "emulator/video.c"),
            Object(Matching, "emulator/serial.c"),
            Object(Matching, "emulator/library.c"),
            Object(Matching, "emulator/peripheral.c"),
            Object(NonMatching, "emulator/_frameGCNcc.c"),
            Object(NonMatching, "emulator/_buildtev.c"),
        ],
    ),
    DolphinLib(
        "base",
        [
            Object(NonMatching, "dolphin/base/PPCArch.c"),
        ],
    ),
    DolphinLib(
        "os",
        [
            Object(Matching, "dolphin/os/OS.c"),
            Object(Matching, "dolphin/os/OSAlarm.c"),
            Object(Matching, "dolphin/os/OSAlloc.c"),
            Object(Matching, "dolphin/os/OSArena.c"),
            Object(Matching, "dolphin/os/OSAudioSystem.c"),
            Object(Matching, "dolphin/os/OSCache.c"),
            Object(Matching, "dolphin/os/OSContext.c"),
            Object(Matching, "dolphin/os/OSError.c"),
            Object(Matching, "dolphin/os/OSFont.c"),
            Object(Matching, "dolphin/os/OSInterrupt.c"),
            Object(Matching, "dolphin/os/OSLink.c"),
            Object(Matching, "dolphin/os/OSMessage.c"),
            Object(Matching, "dolphin/os/OSMemory.c"),
            Object(Matching, "dolphin/os/OSMutex.c"),
            Object(Matching if version_num > VERSIONS.index("mq-j") else NonMatching, "dolphin/os/OSReboot.c"),
            Object(Matching, "dolphin/os/OSReset.c"),
            Object(Matching, "dolphin/os/OSResetSW.c"),
            Object(Matching, "dolphin/os/OSRtc.c"),
            Object(Matching, "dolphin/os/OSSync.c"),
            Object(Matching, "dolphin/os/OSThread.c"),
            Object(Matching, "dolphin/os/OSTime.c"),
            Object(Matching, "dolphin/os/__start.c"),
            Object(Matching, "dolphin/os/__ppc_eabi_init.c"),
        ],
    ),
    DolphinLib(
        "exi",
        [
            Object(NonMatching, "dolphin/exi/EXIBios.c"),
            Object(NonMatching, "dolphin/exi/EXIUart.c"),
        ],
    ),
    DolphinLib(
        "si",
        [
            Object(NonMatching, "dolphin/si/SIBios.c"),
            Object(NonMatching, "dolphin/si/SISamplingRate.c"),
        ],
    ),
    DolphinLib(
        "vi",
        [
            Object(NonMatching, "dolphin/vi/vi.c"),
        ],
    ),
    DolphinLib(
        "db",
        [
            Object(NonMatching, "dolphin/db/db.c"),
        ],
    ),
    DolphinLib(
        "mtx",
        [
            Object(NonMatching, "dolphin/mtx/mtx.c", cflags=[*cflags_base, "-fp_contract off"]),
            Object(NonMatching, "dolphin/mtx/mtxvec.c"),
            Object(NonMatching, "dolphin/mtx/mtx44.c"),
        ],
    ),
    DolphinLib(
        "gx",
        [
            Object(NonMatching, "dolphin/gx/GXInit.c"),
            Object(NonMatching, "dolphin/gx/GXFifo.c"),
            Object(NonMatching, "dolphin/gx/GXAttr.c"),
            Object(NonMatching, "dolphin/gx/GXMisc.c"),
            Object(NonMatching, "dolphin/gx/GXGeometry.c"),
            Object(NonMatching, "dolphin/gx/GXFrameBuf.c"),
            Object(NonMatching, "dolphin/gx/GXLight.c"),
            Object(NonMatching, "dolphin/gx/GXTexture.c"),
            Object(NonMatching, "dolphin/gx/GXBump.c"),
            Object(NonMatching, "dolphin/gx/GXTev.c"),
            Object(NonMatching, "dolphin/gx/GXPixel.c"),
            Object(NonMatching, "dolphin/gx/GXTransform.c"),
            Object(NonMatching, "dolphin/gx/GXPerf.c"),
        ],
    ),
    DolphinLib(
        "pad",
        [
            Object(NonMatching, "dolphin/pad/Padclamp.c"),
            Object(NonMatching, "dolphin/pad/Pad.c"),
        ],
    ),
    DolphinLib(
        "dvd",
        [
            Object(NonMatching, "dolphin/dvd/dvdlow.c"),
            Object(NonMatching, "dolphin/dvd/dvdfs.c"),
            Object(NonMatching, "dolphin/dvd/dvd.c"),
            Object(NonMatching, "dolphin/dvd/dvdqueue.c"),
            Object(NonMatching, "dolphin/dvd/dvderror.c"),
            Object(NonMatching, "dolphin/dvd/dvdidutils.c"),
            Object(NonMatching, "dolphin/dvd/dvdFatal.c"),
            Object(NonMatching, "dolphin/dvd/fstload.c"),
        ],
    ),
    DolphinLib(
        "demo",
        [
            Object(NonMatching, "dolphin/demo/DEMOInit.c"),
            Object(NonMatching, "dolphin/demo/DEMOPuts.c"),
            Object(NonMatching, "dolphin/demo/DEMOFont.c"),
            Object(NonMatching, "dolphin/demo/DEMOPad.c"),
            Object(NonMatching, "dolphin/demo/DEMOStats.c"),
        ],
    ),
    DolphinLib(
        "ai",
        [
            Object(NonMatching, "dolphin/ai/ai.c"),
        ],
    ),
    DolphinLib(
        "ar",
        [
            Object(NonMatching, "dolphin/ar/ar.c"),
        ],
    ),
    DolphinLib(
        "dsp",
        [
            Object(NonMatching, "dolphin/dsp/dsp.c"),
            Object(NonMatching, "dolphin/dsp/dsp_debug.c"),
            Object(NonMatching, "dolphin/dsp/dsp_task.c"),
        ],
    ),
    DolphinLib(
        "card",
        [
            Object(NonMatching, "dolphin/card/CARDBios.c"),
            Object(NonMatching, "dolphin/card/CARDUnlock.c"),
            Object(NonMatching, "dolphin/card/CARDRdwr.c"),
            Object(NonMatching, "dolphin/card/CARDBlock.c"),
            Object(NonMatching, "dolphin/card/CARDDir.c"),
            Object(NonMatching, "dolphin/card/CARDCheck.c"),
            Object(NonMatching, "dolphin/card/CARDMount.c"),
            Object(NonMatching, "dolphin/card/CARDFormat.c"),
            Object(NonMatching, "dolphin/card/CARDOpen.c"),
            Object(NonMatching, "dolphin/card/CARDCreate.c"),
            Object(NonMatching, "dolphin/card/CARDRead.c"),
            Object(NonMatching, "dolphin/card/CARDWrite.c"),
            Object(NonMatching, "dolphin/card/CARDDelete.c"),
            Object(NonMatching, "dolphin/card/CARDStat.c"),
            Object(NonMatching, "dolphin/card/CARDRename.c"),
            Object(NonMatching, "dolphin/card/CARDNet.c"),
        ],
    ),
    DolphinLib(
        "thp",
        [
            Object(NonMatching, "dolphin/thp/THPDec.c"),
            Object(NonMatching, "dolphin/thp/THPAudio.c"),
        ],
    ),
    DolphinLib(
        "tex",
        [
            Object(NonMatching, "dolphin/tex/texPalette.c"),
        ],
    ),
    GenericLib(
        "metrotrk",
        [
            Object(NonMatching, "metrotrk/mainloop.c"),
            Object(NonMatching, "metrotrk/nubevent.c"),
            Object(NonMatching, "metrotrk/nubinit.c"),
            Object(NonMatching, "metrotrk/msg.c"),
            Object(NonMatching, "metrotrk/msgbuf.c"),
            Object(NonMatching, "metrotrk/serpoll.c"),
            Object(NonMatching, "metrotrk/usr_put.c"),
            Object(NonMatching, "metrotrk/dispatch.c"),
            Object(NonMatching, "metrotrk/msghndlr.c"),
            Object(NonMatching, "metrotrk/support.c"),
            Object(NonMatching, "metrotrk/mutex_TRK.c"),
            Object(NonMatching, "metrotrk/notify.c"),
            Object(NonMatching, "metrotrk/flush_cache.c"),
            Object(NonMatching, "metrotrk/mem_TRK.c"),
            Object(NonMatching, "metrotrk/__exception.c"),
            Object(NonMatching, "metrotrk/targimpl.c"),
            Object(NonMatching, "metrotrk/dolphin_trk.c"),
            Object(NonMatching, "metrotrk/mpc_7xx_603e.c"),
            Object(NonMatching, "metrotrk/main_TRK.c"),
            Object(NonMatching, "metrotrk/dolphin_trk_glue.c"),
            Object(NonMatching, "metrotrk/targcont.c"),
        ]
    ),
    GenericLib(
        "runtime",
        [
            Object(NonMatching, "runtime/__mem.c"),
            Object(NonMatching, "runtime/__va_arg.c"),
            Object(NonMatching, "runtime/global_destructor_chain.c"),
            Object(NonMatching, "runtime/runtime.c"),
        ]
    ),
    GenericLib(
        "libc",
        [
            Object(NonMatching, "libc/abort_exit.c"),
            Object(NonMatching, "libc/ansi_files.c"),
            Object(NonMatching, "libc/ansi_fp.c", extra_cflags=["-inline noauto"]),
            Object(NonMatching, "libc/buffer_io.c"),
            Object(NonMatching, "libc/critical_regions.ppc_eabi.c"),
            Object(NonMatching, "libc/ctype.c"),
            Object(NonMatching, "libc/direct_io.c"),
            Object(NonMatching, "libc/errno.c"),
            Object(NonMatching, "libc/mbstring.c", extra_cflags=["-inline noauto"]),
            Object(NonMatching, "libc/mem.c"),
            Object(NonMatching, "libc/mem_funcs.c"),
            Object(NonMatching, "libc/misc_io.c"),
            Object(NonMatching, "libc/printf.c"),
            Object(NonMatching, "libc/scanf.c"),
            Object(NonMatching, "libc/string.c"),
            Object(NonMatching, "libc/strtoul.c"),
            Object(NonMatching, "libc/uart_console_io.c"),
            Object(NonMatching, "libc/float.c"),
            Object(NonMatching, "libc/wchar_io.c"),
            Object(NonMatching, "libc/e_asin.c"),
            Object(NonMatching, "libc/e_pow.c"),
            Object(NonMatching, "libc/fminmaxdim.c"),
            Object(NonMatching, "libc/s_ceil.c"),
            Object(NonMatching, "libc/s_copysign.c"),
            Object(NonMatching, "libc/s_floor.c"),
            Object(NonMatching, "libc/s_frexp.c"),
            Object(NonMatching, "libc/s_ldexp.c"),
            Object(NonMatching, "libc/w_pow.c"),
            Object(NonMatching, "libc/hyperbolicsf.c"),
            Object(NonMatching, "libc/log10f.c"),
            Object(NonMatching, "libc/trigf.c"),
            Object(NonMatching, "libc/math_inlines.c"),
            Object(NonMatching, "libc/common_float_tables.c"),
        ]
    ),
    GenericLib(
        "debugger",
        [
            Object(NonMatching, "debugger/AmcExi2Stubs.c"),
            Object(NonMatching, "debugger/DebuggerDriver.c"),
            Object(NonMatching, "debugger/odenotstub.c"),
        ]
    ),
]

### Execute mode

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    config.progress_each_module = args.verbose
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
