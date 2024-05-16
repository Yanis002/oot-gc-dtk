/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\audio.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008E524 -> 0x8008E91C
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x7549F; // size = 0x10

// size = 0x10, address = 0x800F0C80
struct _XL_OBJECTTYPE gClassAudio;

typedef struct __anon_0x75592 {
    /* 0x00 */ s32 nSize;
    /* 0x04 */ s32 bEnable;
    /* 0x08 */ void* pHost;
    /* 0x0C */ s32 nControl;
    /* 0x10 */ s32 nAddress;
    /* 0x14 */ s32 nRateBit;
    /* 0x18 */ s32 nRateDAC;
    /* 0x1C */ s32 nStatus;
} __anon_0x75592; // size = 0x20

// Range: 0x8008E914 -> 0x8008E91C
s32 audioPut8() {}

// Range: 0x8008E90C -> 0x8008E914
s32 audioPut16() {}

// Range: 0x8008E7C4 -> 0x8008E90C
s32 audioPut32(struct __anon_0x75592* pAudio, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x75592* pAudio; // r31
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    void* pBuffer; // r1+0x14
}

// Range: 0x8008E7BC -> 0x8008E7C4
s32 audioPut64() {}

// Range: 0x8008E7B4 -> 0x8008E7BC
s32 audioGet8() {}

// Range: 0x8008E7AC -> 0x8008E7B4
s32 audioGet16() {}

// Range: 0x8008E6A4 -> 0x8008E7AC
s32 audioGet32(struct __anon_0x75592* pAudio, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x75592* pAudio; // r30
    // u32 nAddress; // r1+0xC
    // s32* pData; // r31
}

// Range: 0x8008E69C -> 0x8008E6A4
s32 audioGet64() {}

// Range: 0x8008E644 -> 0x8008E69C
s32 audioEnable(struct __anon_0x75592* pAudio, s32 bEnable) {
    // Parameters
    // struct __anon_0x75592* pAudio; // r3
    // s32 bEnable; // r1+0xC
}

// Range: 0x8008E524 -> 0x8008E644
s32 audioEvent(struct __anon_0x75592* pAudio, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x75592* pAudio; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
