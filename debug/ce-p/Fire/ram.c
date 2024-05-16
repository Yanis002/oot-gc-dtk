/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\ram.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8006D0E0 -> 0x8006D6F4
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x4EF80; // size = 0x10

// size = 0x10, address = 0x801399B8
struct _XL_OBJECTTYPE gClassRAM;

typedef struct __anon_0x4F071 {
    /* 0x0 */ void* pHost;
    /* 0x4 */ void* pBuffer;
    /* 0x8 */ u32 nSize;
} __anon_0x4F071; // size = 0xC

// Range: 0x8006D6EC -> 0x8006D6F4
static s32 ramPutControl8() {}

// Range: 0x8006D6E4 -> 0x8006D6EC
static s32 ramPutControl16() {}

// Range: 0x8006D6B0 -> 0x8006D6E4
static s32 ramPutControl32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D6A8 -> 0x8006D6B0
static s32 ramPutControl64() {}

// Range: 0x8006D6A0 -> 0x8006D6A8
static s32 ramGetControl8() {}

// Range: 0x8006D698 -> 0x8006D6A0
static s32 ramGetControl16() {}

// Range: 0x8006D664 -> 0x8006D698
static s32 ramGetControl32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D65C -> 0x8006D664
static s32 ramGetControl64() {}

// Range: 0x8006D654 -> 0x8006D65C
static s32 ramPutRI8() {}

// Range: 0x8006D64C -> 0x8006D654
static s32 ramPutRI16() {}

// Range: 0x8006D618 -> 0x8006D64C
static s32 ramPutRI32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D610 -> 0x8006D618
static s32 ramPutRI64() {}

// Range: 0x8006D608 -> 0x8006D610
static s32 ramGetRI8() {}

// Range: 0x8006D600 -> 0x8006D608
static s32 ramGetRI16() {}

// Range: 0x8006D5CC -> 0x8006D600
static s32 ramGetRI32(u32 nAddress) {
    // Parameters
    // u32 nAddress; // r1+0x4
}

// Range: 0x8006D5C4 -> 0x8006D5CC
static s32 ramGetRI64() {}

// Range: 0x8006D5A0 -> 0x8006D5C4
static s32 ramPut8(struct __anon_0x4F071* pRAM, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // char* pData; // r1+0x8
}

// Range: 0x8006D578 -> 0x8006D5A0
static s32 ramPut16(struct __anon_0x4F071* pRAM, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // s16* pData; // r1+0x8
}

// Range: 0x8006D550 -> 0x8006D578
static s32 ramPut32(struct __anon_0x4F071* pRAM, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r6
    // s32* pData; // r1+0x8
}

// Range: 0x8006D51C -> 0x8006D550
static s32 ramPut64(struct __anon_0x4F071* pRAM, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s64* pData; // r1+0x8
}

// Range: 0x8006D4EC -> 0x8006D51C
static s32 ramGet8(struct __anon_0x4F071* pRAM, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // char* pData; // r1+0x8
}

// Range: 0x8006D4B8 -> 0x8006D4EC
static s32 ramGet16(struct __anon_0x4F071* pRAM, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s16* pData; // r1+0x8
}

// Range: 0x8006D484 -> 0x8006D4B8
static s32 ramGet32(struct __anon_0x4F071* pRAM, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s32* pData; // r1+0x8
}

// Range: 0x8006D440 -> 0x8006D484
static s32 ramGet64(struct __anon_0x4F071* pRAM, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32 nAddress; // r4
    // s64* pData; // r1+0x8
}

// Range: 0x8006D3E8 -> 0x8006D440
s32 ramGetBuffer(struct __anon_0x4F071* pRAM, void* ppRAM, u32 nOffset, u32* pnSize) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // void* ppRAM; // r1+0x4
    // u32 nOffset; // r5
    // u32* pnSize; // r1+0xC
}

// Range: 0x8006D3A0 -> 0x8006D3E8
s32 ramWipe(struct __anon_0x4F071* pRAM) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r3
}

// Range: 0x8006D330 -> 0x8006D3A0
s32 ramSetSize(struct __anon_0x4F071* pRAM, u32 nSize) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r30
    // u32 nSize; // r31
}

// Range: 0x8006D318 -> 0x8006D330
s32 ramGetSize(struct __anon_0x4F071* pRAM, u32* pnSize) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r1+0x0
    // u32* pnSize; // r1+0x4
}

// Range: 0x8006D0E0 -> 0x8006D318
s32 ramEvent(struct __anon_0x4F071* pRAM, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x4F071* pRAM; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
