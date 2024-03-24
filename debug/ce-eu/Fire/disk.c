/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\disk.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008E91C -> 0x8008EBB0
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x77729; // size = 0x10

// size = 0x10, address = 0x8013AA78
struct _XL_OBJECTTYPE gClassDisk;

typedef struct __anon_0x7781B {
    /* 0x0 */ void* pHost;
} __anon_0x7781B; // size = 0x4

// Range: 0x8008EBA8 -> 0x8008EBB0
static s32 diskPutROM8() {}

// Range: 0x8008EBA0 -> 0x8008EBA8
static s32 diskPutROM16() {}

// Range: 0x8008EB98 -> 0x8008EBA0
static s32 diskPutROM32() {}

// Range: 0x8008EB90 -> 0x8008EB98
static s32 diskPutROM64() {}

// Range: 0x8008EB80 -> 0x8008EB90
static s32 diskGetROM8(char* pData) {
    // Parameters
    // char* pData; // r1+0x8
}

// Range: 0x8008EB70 -> 0x8008EB80
static s32 diskGetROM16(s16* pData) {
    // Parameters
    // s16* pData; // r1+0x8
}

// Range: 0x8008EB60 -> 0x8008EB70
static s32 diskGetROM32(s32* pData) {
    // Parameters
    // s32* pData; // r1+0x8
}

// Range: 0x8008EB4C -> 0x8008EB60
static s32 diskGetROM64(s64* pData) {
    // Parameters
    // s64* pData; // r1+0x8
}

// Range: 0x8008EB44 -> 0x8008EB4C
static s32 diskPutDrive8() {}

// Range: 0x8008EB3C -> 0x8008EB44
static s32 diskPutDrive16() {}

// Range: 0x8008EB10 -> 0x8008EB3C
static s32 diskPutDrive32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8008EB08 -> 0x8008EB10
static s32 diskPutDrive64() {}

// Range: 0x8008EB00 -> 0x8008EB08
static s32 diskGetDrive8() {}

// Range: 0x8008EAF8 -> 0x8008EB00
static s32 diskGetDrive16() {}

// Range: 0x8008EAC0 -> 0x8008EAF8
static s32 diskGetDrive32(u32 nAddress, s32* pData) {
    // Parameters
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8008EAB8 -> 0x8008EAC0
static s32 diskGetDrive64() {}

// Range: 0x8008E91C -> 0x8008EAB8
s32 diskEvent(struct __anon_0x7781B* pDisk, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x7781B* pDisk; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
