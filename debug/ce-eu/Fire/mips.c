/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\mips.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008E3DC -> 0x8008E91C
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x76F11; // size = 0x10

// size = 0x10, address = 0x8013AA00
struct _XL_OBJECTTYPE gClassMips;

typedef struct __anon_0x77003 {
    /* 0x0 */ s32 nMask;
    /* 0x4 */ s32 nMode;
    /* 0x8 */ void* pHost;
    /* 0xC */ s32 nInterrupt;
} __anon_0x77003; // size = 0x10

typedef enum __anon_0x773A6 {
    MIT_NONE = -1,
    MIT_SP = 0,
    MIT_SI = 1,
    MIT_AI = 2,
    MIT_VI = 3,
    MIT_PI = 4,
    MIT_DP = 5,
} __anon_0x773A6;

// Range: 0x8008E830 -> 0x8008E91C
s32 mipsSetInterrupt(struct __anon_0x77003* pMips, enum __anon_0x773A6 eType) {
    // Parameters
    // struct __anon_0x77003* pMips; // r1+0x0
    // enum __anon_0x773A6 eType; // r1+0x4

    // Local variables
    s32 nInterrupt; // r5
}

// Range: 0x8008E78C -> 0x8008E830
s32 mipsResetInterrupt(struct __anon_0x77003* pMips, enum __anon_0x773A6 eType) {
    // Parameters
    // struct __anon_0x77003* pMips; // r1+0x0
    // enum __anon_0x773A6 eType; // r1+0x4

    // Local variables
    s32 nInterrupt; // r5
}

// Range: 0x8008E784 -> 0x8008E78C
s32 mipsPut8() {}

// Range: 0x8008E77C -> 0x8008E784
s32 mipsPut16() {}

// Range: 0x8008E574 -> 0x8008E77C
s32 mipsPut32(struct __anon_0x77003* pMips, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x77003* pMips; // r30
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 nData; // r31
}

// Range: 0x8008E56C -> 0x8008E574
s32 mipsPut64() {}

// Range: 0x8008E564 -> 0x8008E56C
s32 mipsGet8() {}

// Range: 0x8008E55C -> 0x8008E564
s32 mipsGet16() {}

// Range: 0x8008E4F4 -> 0x8008E55C
s32 mipsGet32(struct __anon_0x77003* pMips, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x77003* pMips; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8008E4EC -> 0x8008E4F4
s32 mipsGet64() {}

// Range: 0x8008E3DC -> 0x8008E4EC
s32 mipsEvent(struct __anon_0x77003* pMips, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x77003* pMips; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
