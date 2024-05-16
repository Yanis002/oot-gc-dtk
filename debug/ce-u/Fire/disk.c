/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\disk.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008D804 -> 0x8008DA98
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x73BBE; // size = 0x10

// size = 0x10, address = 0x800F0C50
struct _XL_OBJECTTYPE gClassDisk;

typedef struct __anon_0x73CB0 {
    /* 0x0 */ void* pHost;
} __anon_0x73CB0; // size = 0x4

// Range: 0x8008DA90 -> 0x8008DA98
static s32 diskPutROM8() {}

// Range: 0x8008DA88 -> 0x8008DA90
static s32 diskPutROM16() {}

// Range: 0x8008DA80 -> 0x8008DA88
static s32 diskPutROM32() {}

// Range: 0x8008DA78 -> 0x8008DA80
static s32 diskPutROM64() {}

// Range: 0x8008DA68 -> 0x8008DA78
static s32 diskGetROM8(char* pData) {
    // Parameters
    // char* pData; // r1+0x8
}

// Range: 0x8008DA58 -> 0x8008DA68
static s32 diskGetROM16(s16* pData) {
    // Parameters
    // s16* pData; // r1+0x8
}

// Range: 0x8008DA48 -> 0x8008DA58
static s32 diskGetROM32(s32* pData) {
    // Parameters
    // s32* pData; // r1+0x8
}

// Range: 0x8008DA34 -> 0x8008DA48
static s32 diskGetROM64(s64* pData) {
    // Parameters
    // s64* pData; // r1+0x8
}

// Range: 0x8008DA2C -> 0x8008DA34
static s32 diskPutDrive8() {}

// Range: 0x8008DA24 -> 0x8008DA2C
static s32 diskPutDrive16() {}

// Range: 0x8008D9F8 -> 0x8008DA24
static s32 diskPutDrive32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8008D9F0 -> 0x8008D9F8
static s32 diskPutDrive64() {}

// Range: 0x8008D9E8 -> 0x8008D9F0
static s32 diskGetDrive8() {}

// Range: 0x8008D9E0 -> 0x8008D9E8
static s32 diskGetDrive16() {}

// Range: 0x8008D9A8 -> 0x8008D9E0
static s32 diskGetDrive32(u32 nAddress, s32* pData) {
    // Parameters
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8008D9A0 -> 0x8008D9A8
static s32 diskGetDrive64() {}

// Range: 0x8008D804 -> 0x8008D9A0
s32 diskEvent(struct __anon_0x73CB0* pDisk, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x73CB0* pDisk; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
