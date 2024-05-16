/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\ram.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8006CE14 -> 0x8006D428
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x4BFF9; // size = 0x10

// size = 0x10, address = 0x800EFBD0
struct _XL_OBJECTTYPE gClassRAM;

typedef struct __anon_0x4C0EA {
    /* 0x0 */ void* pHost;
    /* 0x4 */ void* pBuffer;
    /* 0x8 */ u32 nSize;
} __anon_0x4C0EA; // size = 0xC

// Range: 0x8006D420 -> 0x8006D428
static s32 ramPutControl8() {}

// Range: 0x8006D418 -> 0x8006D420
static s32 ramPutControl16() {}

// Range: 0x8006D3E4 -> 0x8006D418
static s32 ramPutControl32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D3DC -> 0x8006D3E4
static s32 ramPutControl64() {}

// Range: 0x8006D3D4 -> 0x8006D3DC
static s32 ramGetControl8() {}

// Range: 0x8006D3CC -> 0x8006D3D4
static s32 ramGetControl16() {}

// Range: 0x8006D398 -> 0x8006D3CC
static s32 ramGetControl32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D390 -> 0x8006D398
static s32 ramGetControl64() {}

// Range: 0x8006D388 -> 0x8006D390
static s32 ramPutRI8() {}

// Range: 0x8006D380 -> 0x8006D388
static s32 ramPutRI16() {}

// Range: 0x8006D34C -> 0x8006D380
static s32 ramPutRI32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D344 -> 0x8006D34C
static s32 ramPutRI64() {}

// Range: 0x8006D33C -> 0x8006D344
static s32 ramGetRI8() {}

// Range: 0x8006D334 -> 0x8006D33C
static s32 ramGetRI16() {}

// Range: 0x8006D300 -> 0x8006D334
static s32 ramGetRI32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D2F8 -> 0x8006D300
static s32 ramGetRI64() {}

// Range: 0x8006D2D4 -> 0x8006D2F8
static s32 ramPut8(struct __anon_0x4C0EA* pRAM, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // char* pData; // r1+0x8
}

// Range: 0x8006D2AC -> 0x8006D2D4
static s32 ramPut16(struct __anon_0x4C0EA* pRAM, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // s16* pData; // r1+0x8
}

// Range: 0x8006D284 -> 0x8006D2AC
static s32 ramPut32(struct __anon_0x4C0EA* pRAM, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // s32* pData; // r1+0x8
}

// Range: 0x8006D250 -> 0x8006D284
static s32 ramPut64(struct __anon_0x4C0EA* pRAM, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s64* pData; // r1+0x8
}

// Range: 0x8006D220 -> 0x8006D250
static s32 ramGet8(struct __anon_0x4C0EA* pRAM, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // char* pData; // r1+0x8
}

// Range: 0x8006D1EC -> 0x8006D220
static s32 ramGet16(struct __anon_0x4C0EA* pRAM, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s16* pData; // r1+0x8
}

// Range: 0x8006D1B8 -> 0x8006D1EC
static s32 ramGet32(struct __anon_0x4C0EA* pRAM, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s32* pData; // r1+0x8
}

// Range: 0x8006D174 -> 0x8006D1B8
static s32 ramGet64(struct __anon_0x4C0EA* pRAM, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s64* pData; // r1+0x8
}

// Range: 0x8006D11C -> 0x8006D174
s32 ramGetBuffer(struct __anon_0x4C0EA* pRAM, void* ppRAM, u32 nOffset, u32* pnSize) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // void* ppRAM; // r1+0x4
    // u32 nOffset; // r5
    // u32* pnSize; // r1+0xC
}

// Range: 0x8006D0D4 -> 0x8006D11C
s32 ramWipe(struct __anon_0x4C0EA* pRAM) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r3
}

// Range: 0x8006D064 -> 0x8006D0D4
s32 ramSetSize(struct __anon_0x4C0EA* pRAM, u32 nSize) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r30
    // u32 nSize; // r31
}

// Range: 0x8006D04C -> 0x8006D064
s32 ramGetSize(struct __anon_0x4C0EA* pRAM, u32* pnSize) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r1+0x0
    // u32* pnSize; // r1+0x4
}

// Range: 0x8006CE14 -> 0x8006D04C
s32 ramEvent(struct __anon_0x4C0EA* pRAM, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x4C0EA* pRAM; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
