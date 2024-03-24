/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\rdb.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x80072764 -> 0x80072D4C
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x5A54C; // size = 0x10

// size = 0x10, address = 0x8013A4E0
struct _XL_OBJECTTYPE gClassRdb;

typedef struct __anon_0x5A65D {
    /* 0x000 */ s32 nHackCount;
    /* 0x004 */ char szString[256];
    /* 0x104 */ s32 nIndexString;
    /* 0x108 */ s32 nAddress;
    /* 0x10C */ void* pHost;
} __anon_0x5A65D; // size = 0x110

// Range: 0x80072D44 -> 0x80072D4C
static s32 rdbPut8() {}

// Range: 0x80072D3C -> 0x80072D44
static s32 rdbPut16() {}

// Range: 0x800728C0 -> 0x80072D3C
static s32 rdbPut32(struct __anon_0x5A65D* pRDB, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x5A65D* pRDB; // r3
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 nLength; // r7
    s32 iCounter; // r5
}

// Range: 0x800728B8 -> 0x800728C0
static s32 rdbPut64() {}

// Range: 0x800728B0 -> 0x800728B8
static s32 rdbGet8() {}

// Range: 0x800728A8 -> 0x800728B0
static s32 rdbGet16() {}

// Range: 0x80072874 -> 0x800728A8
static s32 rdbGet32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8007286C -> 0x80072874
static s32 rdbGet64() {}

// Range: 0x80072764 -> 0x8007286C
s32 rdbEvent(struct __anon_0x5A65D* pRDB, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x5A65D* pRDB; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
