/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Core\xlCoreGCN.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x800055A0 -> 0x80005D10
*/

#include "types.h"

// size = 0x8081, address = 0x800D4980
u8 gTgPcTPL[32897];

// size = 0x4, address = 0x801818C0
static s32 gnCountArgument;

// size = 0x4, address = 0x801818C4
static char** gaszArgument;

// size = 0x4, address = 0x801818C8
static void* DefaultFifo;

typedef struct __anon_0x242 {
    /* 0x0 */ u8 pad[128];
} __anon_0x242; // size = 0x80

// size = 0x4, address = 0x801818CC
static struct __anon_0x242* DefaultFifoObj;

typedef enum __anon_0x2A9 {
    VI_TVMODE_NTSC_INT = 0,
    VI_TVMODE_NTSC_DS = 1,
    VI_TVMODE_NTSC_PROG = 2,
    VI_TVMODE_PAL_INT = 4,
    VI_TVMODE_PAL_DS = 5,
    VI_TVMODE_EURGB60_INT = 20,
    VI_TVMODE_EURGB60_DS = 21,
    VI_TVMODE_MPAL_INT = 8,
    VI_TVMODE_MPAL_DS = 9,
    VI_TVMODE_DEBUG_INT = 12,
    VI_TVMODE_DEBUG_PAL_INT = 16,
    VI_TVMODE_DEBUG_PAL_DS = 17,
} __anon_0x2A9;

typedef enum __anon_0x3F6 {
    VI_XFBMODE_SF = 0,
    VI_XFBMODE_DF = 1,
} __anon_0x3F6;

typedef struct _GXRenderModeObj {
    /* 0x00 */ enum __anon_0x2A9 viTVmode;
    /* 0x04 */ u16 fbWidth;
    /* 0x06 */ u16 efbHeight;
    /* 0x08 */ u16 xfbHeight;
    /* 0x0A */ u16 viXOrigin;
    /* 0x0C */ u16 viYOrigin;
    /* 0x0E */ u16 viWidth;
    /* 0x10 */ u16 viHeight;
    /* 0x14 */ enum __anon_0x3F6 xFBmode;
    /* 0x18 */ u8 field_rendering;
    /* 0x19 */ u8 aa;
    /* 0x1A */ u8 sample_pattern[12][2];
    /* 0x32 */ u8 vfilter[7];
} __anon_0x4AA; // size = 0x3C

// size = 0x3C, address = 0x801401E0
static struct _GXRenderModeObj rmodeobj;

// size = 0x4, address = 0x801818D0
static void* gpHeap;

// size = 0x4, address = 0x801818D4
static void* gArenaHi;

// size = 0x4, address = 0x801818D8
static void* gArenaLo;

typedef struct _GXTexObj {
    /* 0x0 */ u32 dummy[8];
} __anon_0x773; // size = 0x20

// size = 0x80, address = 0x8014021C
struct _GXTexObj g_texMap[4];

// size = 0x4, address = 0x801818DC
struct _GXRenderModeObj* rmode;

// size = 0x4, address = 0x80181760
s32 __OSCurrHeap;

// size = 0x4, address = 0x80181DD4
void* DemoFrameBuffer1;

// size = 0x4, address = 0x80181DCC
void* DemoCurrentBuffer;

// size = 0x4, address = 0x80181DD0
void* DemoFrameBuffer2;

typedef enum _GXTexWrapMode {
    GX_CLAMP = 0,
    GX_REPEAT = 1,
    GX_MIRROR = 2,
    GX_MAX_TEXWRAPMODE = 3,
} __anon_0x907;

typedef enum _GXTexFilter {
    GX_NEAR = 0,
    GX_LINEAR = 1,
    GX_NEAR_MIP_NEAR = 2,
    GX_LIN_MIP_NEAR = 3,
    GX_NEAR_MIP_LIN = 4,
    GX_LIN_MIP_LIN = 5,
} __anon_0x970;

typedef struct __anon_0xA01 {
    /* 0x00 */ u16 height;
    /* 0x02 */ u16 width;
    /* 0x04 */ u32 format;
    /* 0x08 */ char* data;
    /* 0x0C */ enum _GXTexWrapMode wrapS;
    /* 0x10 */ enum _GXTexWrapMode wrapT;
    /* 0x14 */ enum _GXTexFilter minFilter;
    /* 0x18 */ enum _GXTexFilter magFilter;
    /* 0x1C */ f32 LODBias;
    /* 0x20 */ u8 edgeLODEnable;
    /* 0x21 */ u8 minLOD;
    /* 0x22 */ u8 maxLOD;
    /* 0x23 */ u8 unpacked;
} __anon_0xA01; // size = 0x24

typedef enum _GXTlutFmt {
    GX_TL_IA8 = 0,
    GX_TL_RGB565 = 1,
    GX_TL_RGB5A3 = 2,
    GX_MAX_TLUTFMT = 3,
} __anon_0xBF4;

typedef struct __anon_0xC5C {
    /* 0x0 */ u16 numEntries;
    /* 0x2 */ u8 unpacked;
    /* 0x3 */ u8 pad8;
    /* 0x4 */ enum _GXTlutFmt format;
    /* 0x8 */ char* data;
} __anon_0xC5C; // size = 0xC

typedef struct __anon_0xD28 {
    /* 0x0 */ struct __anon_0xA01* textureHeader;
    /* 0x4 */ struct __anon_0xC5C* CLUTHeader;
} __anon_0xD28; // size = 0x8

typedef struct _GXColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} __anon_0xD99; // size = 0x4

typedef union DoubleLongLong {
    /* 0x0 */ f64 f;
    /* 0x0 */ s64 i;
} __anon_0x1030;

// size = 0x3C, address = 0x8013E254
struct _GXRenderModeObj GXEurgb60Hz480IntDf;

// Erased
static void xlCoreInit(struct _GXRenderModeObj* mode) {
    // Parameters
    // struct _GXRenderModeObj* mode; // r31

    // References
    // -> struct _GXRenderModeObj* rmode;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer1;
    // -> static void* DefaultFifo;
    // -> static struct __anon_0x242* DefaultFifoObj;
    // -> s32 __OSCurrHeap;
    // -> static struct _GXRenderModeObj rmodeobj;
    // -> struct _GXRenderModeObj GXEurgb60Hz480IntDf;
}

// Range: 0x80005CD4 -> 0x80005D10
s32 xlCoreReset() {
    // References
    // -> static void* gArenaHi;
    // -> static void* gArenaLo;
    // -> static void* gpHeap;
    // -> s32 __OSCurrHeap;
}

// Range: 0x80005C54 -> 0x80005CD4
static void xlCoreInitRenderMode(struct _GXRenderModeObj* mode) {
    // Parameters
    // struct _GXRenderModeObj* mode; // r1+0x8

    // References
    // -> static struct _GXRenderModeObj rmodeobj;
    // -> struct _GXRenderModeObj* rmode;
    // -> struct _GXRenderModeObj GXEurgb60Hz480IntDf;
}

// Range: 0x80005B7C -> 0x80005C54
static void xlCoreInitMem() {
    // Local variables
    void* arenaLo; // r1+0x8
    void* arenaHi; // r1+0x8
    u32 fbSize; // r3

    // References
    // -> void* DemoFrameBuffer2;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer1;
    // -> struct _GXRenderModeObj* rmode;
    // -> static void* gArenaHi;
    // -> static void* gArenaLo;
}

// Range: 0x80005920 -> 0x80005B7C
static void xlCoreInitGX() {
    // Local variables
    u8 newFilter[7]; // r1+0x18

    // References
    // -> void* DemoCurrentBuffer;
    // -> struct _GXRenderModeObj* rmode;
}

// Erased
static void xlCoreInitVI() {
    // References
    // -> struct _GXRenderModeObj* rmode;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer1;
}

// Range: 0x80005918 -> 0x80005920
s32 xlCoreGetArgumentCount() {
    // References
    // -> static s32 gnCountArgument;
}

// Range: 0x800058E4 -> 0x80005918
s32 xlCoreGetArgument(s32 iArgument, char** pszArgument) {
    // Parameters
    // s32 iArgument; // r1+0x0
    // char** pszArgument; // r1+0x4

    // References
    // -> static char** gaszArgument;
    // -> static s32 gnCountArgument;
}

// Range: 0x800058DC -> 0x800058E4
s32 xlCoreHiResolution() {}

// Erased
static s32 xlCoreEnableFPExceptions() {
    // Local variables
    f64 control; // r1+0x8
    union DoubleLongLong d; // r1+0x8
}

// Erased
static s32 xlCoreGetUpper24MB(void* ppBuffer) {
    // Parameters
    // void* ppBuffer; // r1+0x0
}

// Range: 0x80005674 -> 0x800058DC
s32 main(s32 nCount, char** aszArgument) {
    // Parameters
    // s32 nCount; // r1+0x8
    // char** aszArgument; // r1+0xC

    // Local variables
    s32 nSize; // r31
    void* pHeap; // r27
    s32 nSizeHeap; // r3
    struct __anon_0xD28* tdp; // r1+0x8
    struct _GXColor black; // r1+0x10
    u32 i; // r26

    // References
    // -> s32 __OSCurrHeap;
    // -> static void* gpHeap;
    // -> struct _GXTexObj g_texMap[4];
    // -> u8 gTgPcTPL[32897];
    // -> struct _GXRenderModeObj* rmode;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer1;
    // -> static void* DefaultFifo;
    // -> static struct __anon_0x242* DefaultFifoObj;
    // -> static char** gaszArgument;
    // -> static s32 gnCountArgument;
}

// Range: 0x800055A0 -> 0x80005674
void xlCoreBeforeRender() {
    // References
    // -> struct _GXRenderModeObj* rmode;
}
