/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\mips.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008D2C4 -> 0x8008D804
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x733A6; // size = 0x10

// size = 0x10, address = 0x800F0BD8
struct _XL_OBJECTTYPE gClassMips;

typedef struct __anon_0x73498 {
    /* 0x0 */ s32 nMask;
    /* 0x4 */ s32 nMode;
    /* 0x8 */ void* pHost;
    /* 0xC */ s32 nInterrupt;
} __anon_0x73498; // size = 0x10

typedef enum __anon_0x7383B {
    MIT_NONE = -1,
    MIT_SP = 0,
    MIT_SI = 1,
    MIT_AI = 2,
    MIT_VI = 3,
    MIT_PI = 4,
    MIT_DP = 5,
} __anon_0x7383B;

// Range: 0x8008D718 -> 0x8008D804
s32 mipsSetInterrupt(struct __anon_0x73498* pMips, enum __anon_0x7383B eType) {
    // Parameters
    // struct __anon_0x73498* pMips; // r1+0x0
    // enum __anon_0x7383B eType; // r1+0x4

    // Local variables
    s32 nInterrupt; // r5
}

// Range: 0x8008D674 -> 0x8008D718
s32 mipsResetInterrupt(struct __anon_0x73498* pMips, enum __anon_0x7383B eType) {
    // Parameters
    // struct __anon_0x73498* pMips; // r1+0x0
    // enum __anon_0x7383B eType; // r1+0x4

    // Local variables
    s32 nInterrupt; // r5
}

// Range: 0x8008D66C -> 0x8008D674
s32 mipsPut8() {}

// Range: 0x8008D664 -> 0x8008D66C
s32 mipsPut16() {}

// Range: 0x8008D45C -> 0x8008D664
s32 mipsPut32(struct __anon_0x73498* pMips, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x73498* pMips; // r30
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 nData; // r31
}

// Range: 0x8008D454 -> 0x8008D45C
s32 mipsPut64() {}

// Range: 0x8008D44C -> 0x8008D454
s32 mipsGet8() {}

// Range: 0x8008D444 -> 0x8008D44C
s32 mipsGet16() {}

// Range: 0x8008D3DC -> 0x8008D444
s32 mipsGet32(struct __anon_0x73498* pMips, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x73498* pMips; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8008D3D4 -> 0x8008D3DC
s32 mipsGet64() {}

// Range: 0x8008D2C4 -> 0x8008D3D4
s32 mipsEvent(struct __anon_0x73498* pMips, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x73498* pMips; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
