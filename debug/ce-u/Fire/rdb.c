/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\rdb.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8007164C -> 0x80071C34
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x56A2D; // size = 0x10

// size = 0x10, address = 0x800F06B8
struct _XL_OBJECTTYPE gClassRdb;

typedef struct __anon_0x56B3E {
    /* 0x000 */ s32 nHackCount;
    /* 0x004 */ char szString[256];
    /* 0x104 */ s32 nIndexString;
    /* 0x108 */ s32 nAddress;
    /* 0x10C */ void* pHost;
} __anon_0x56B3E; // size = 0x110

// Range: 0x80071C2C -> 0x80071C34
static s32 rdbPut8() {}

// Range: 0x80071C24 -> 0x80071C2C
static s32 rdbPut16() {}

// Range: 0x800717A8 -> 0x80071C24
static s32 rdbPut32(struct __anon_0x56B3E* pRDB, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x56B3E* pRDB; // r3
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 nLength; // r7
    s32 iCounter; // r5
}

// Range: 0x800717A0 -> 0x800717A8
static s32 rdbPut64() {}

// Range: 0x80071798 -> 0x800717A0
static s32 rdbGet8() {}

// Range: 0x80071790 -> 0x80071798
static s32 rdbGet16() {}

// Range: 0x8007175C -> 0x80071790
static s32 rdbGet32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x80071754 -> 0x8007175C
static s32 rdbGet64() {}

// Range: 0x8007164C -> 0x80071754
s32 rdbEvent(struct __anon_0x56B3E* pRDB, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x56B3E* pRDB; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
