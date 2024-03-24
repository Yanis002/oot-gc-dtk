/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\sram.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008F2CC -> 0x8008F63C
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x786C1; // size = 0x10

// size = 0x10, address = 0x8013AA98
struct _XL_OBJECTTYPE gClassSram;

typedef struct __anon_0x787B3 {
    /* 0x0 */ void* pHost;
} __anon_0x787B3; // size = 0x4

// Range: 0x8008F5C4 -> 0x8008F63C
s32 sramCopySRAM(struct __anon_0x787B3* pSRAM, s32 nOffsetRAM, s32 nOffsetSRAM, s32 nSize) {
    // Parameters
    // struct __anon_0x787B3* pSRAM; // r1+0x8
    // s32 nOffsetRAM; // r4
    // s32 nOffsetSRAM; // r31
    // s32 nSize; // r1+0x14

    // Local variables
    void* pTarget; // r1+0x18
}

// Range: 0x8008F54C -> 0x8008F5C4
s32 sramTransferSRAM(struct __anon_0x787B3* pSRAM, s32 nOffsetRAM, s32 nOffsetSRAM, s32 nSize) {
    // Parameters
    // struct __anon_0x787B3* pSRAM; // r1+0x8
    // s32 nOffsetRAM; // r4
    // s32 nOffsetSRAM; // r31
    // s32 nSize; // r1+0x14

    // Local variables
    void* pTarget; // r1+0x18
}

// Range: 0x8008F51C -> 0x8008F54C
static s32 sramPut8(u32 nAddress, char* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // char* pData; // r5
}

// Range: 0x8008F4EC -> 0x8008F51C
static s32 sramPut16(u32 nAddress, s16* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s16* pData; // r5
}

// Range: 0x8008F4BC -> 0x8008F4EC
static s32 sramPut32(u32 nAddress, s32* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s32* pData; // r5
}

// Range: 0x8008F48C -> 0x8008F4BC
static s32 sramPut64(u32 nAddress, s64* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s64* pData; // r5
}

// Range: 0x8008F45C -> 0x8008F48C
static s32 sramGet8(u32 nAddress, char* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // char* pData; // r5
}

// Range: 0x8008F42C -> 0x8008F45C
static s32 sramGet16(u32 nAddress, s16* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s16* pData; // r5
}

// Range: 0x8008F3FC -> 0x8008F42C
static s32 sramGet32(u32 nAddress, s32* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s32* pData; // r5
}

// Range: 0x8008F3CC -> 0x8008F3FC
static s32 sramGet64(u32 nAddress, s64* pData) {
    // Parameters
    // u32 nAddress; // r1+0xC
    // s64* pData; // r5
}

// Range: 0x8008F2CC -> 0x8008F3CC
s32 sramEvent(struct __anon_0x787B3* pSram, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x787B3* pSram; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
