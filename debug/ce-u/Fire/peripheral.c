/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\peripheral.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x80097818 -> 0x80097E18
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x83DF4; // size = 0x10

// size = 0x10, address = 0x800F24C4
struct _XL_OBJECTTYPE gClassPeripheral;

typedef struct __anon_0x83EEC {
    /* 0x00 */ void* pHost;
    /* 0x04 */ s32 nStatus;
    /* 0x08 */ s32 nSizeGet;
    /* 0x0C */ s32 nSizePut;
    /* 0x10 */ s32 nLatency1;
    /* 0x14 */ s32 nLatency2;
    /* 0x18 */ s32 nRelease1;
    /* 0x1C */ s32 nRelease2;
    /* 0x20 */ s32 nSizePage1;
    /* 0x24 */ s32 nSizePage2;
    /* 0x28 */ s32 nAddressRAM;
    /* 0x2C */ s32 nAddressROM;
    /* 0x30 */ s32 nWidthPulse1;
    /* 0x34 */ s32 nWidthPulse2;
} __anon_0x83EEC; // size = 0x38

typedef enum __anon_0x84334 {
    SOT_NONE = -1,
    SOT_CPU = 0,
    SOT_PIF = 1,
    SOT_RAM = 2,
    SOT_ROM = 3,
    SOT_RSP = 4,
    SOT_RDP = 5,
    SOT_MIPS = 6,
    SOT_DISK = 7,
    SOT_FLASH = 8,
    SOT_SRAM = 9,
    SOT_AUDIO = 10,
    SOT_VIDEO = 11,
    SOT_SERIAL = 12,
    SOT_LIBRARY = 13,
    SOT_PERIPHERAL = 14,
    SOT_RDB = 15,
    SOT_COUNT = 16,
} __anon_0x84334;

typedef enum __anon_0x845B5 {
    SM_NONE = -1,
    SM_RUNNING = 0,
    SM_STOPPED = 1,
} __anon_0x845B5;

typedef struct __anon_0x8461E {
    /* 0x0 */ s32 nSize;
    /* 0x4 */ s32 nOffsetRAM;
    /* 0x8 */ s32 nOffsetROM;
    /* 0xC */ s32 (* pCallback)();
} __anon_0x8461E; // size = 0x10

typedef enum __anon_0x846CF {
    SRT_NONE = -1,
    SRT_MARIO = 0,
    SRT_WAVERACE = 1,
    SRT_MARIOKART = 2,
    SRT_STARFOX = 3,
    SRT_ZELDA1 = 4,
    SRT_ZELDA2 = 5,
    SRT_1080 = 6,
    SRT_PANEL = 7,
    SRT_MARIOPARTY1 = 8,
    SRT_MARIOPARTY2 = 9,
    SRT_MARIOPARTY3 = 10,
    SRT_DRMARIO = 11,
    SRT_UNKNOWN = 12,
} __anon_0x846CF;

typedef struct __anon_0x84822 {
    /* 0x00 */ void* pFrame;
    /* 0x04 */ void* pSound;
    /* 0x08 */ s32 bException;
    /* 0x0C */ enum __anon_0x845B5 eMode;
    /* 0x10 */ struct __anon_0x8461E romCopy;
    /* 0x20 */ enum __anon_0x846CF eTypeROM;
    /* 0x24 */ void* apObject[16];
    /* 0x68 */ u64 nAddressBreak;
    /* 0x70 */ enum __anon_0x84334 storageDevice;
    /* 0x74 */ u8 anException[16];
    /* 0x84 */ s32 bJapaneseVersion;
} __anon_0x84822; // size = 0x88

// size = 0x4, address = 0x80137B00
struct __anon_0x84822* gpSystem;

// Range: 0x80097DD4 -> 0x80097E18
static s32 peripheralDMA_Complete() {
    // Local variables
    struct __anon_0x83EEC* pPeripheral; // r3

    // References
    // -> struct __anon_0x84822* gpSystem;
}

// Range: 0x80097DCC -> 0x80097DD4
s32 peripheralPut8() {}

// Range: 0x80097DC4 -> 0x80097DCC
s32 peripheralPut16() {}

// Range: 0x80097A40 -> 0x80097DC4
s32 peripheralPut32(struct __anon_0x83EEC* pPeripheral, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x83EEC* pPeripheral; // r30
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 bFlag; // r31
    enum __anon_0x84334 storageDevice; // r1+0x14
}

// Range: 0x80097A38 -> 0x80097A40
s32 peripheralPut64() {}

// Range: 0x80097A30 -> 0x80097A38
s32 peripheralGet8() {}

// Range: 0x80097A28 -> 0x80097A30
s32 peripheralGet16() {}

// Range: 0x80097928 -> 0x80097A28
s32 peripheralGet32(struct __anon_0x83EEC* pPeripheral, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x83EEC* pPeripheral; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x80097920 -> 0x80097928
s32 peripheralGet64() {}

// Range: 0x80097818 -> 0x80097920
s32 peripheralEvent(struct __anon_0x83EEC* pPeripheral, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x83EEC* pPeripheral; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
