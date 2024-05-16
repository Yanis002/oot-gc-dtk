/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\serial.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8008FFB4 -> 0x80090288
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x7C3B7; // size = 0x10

// size = 0x10, address = 0x8013AD58
struct _XL_OBJECTTYPE gClassSerial;

typedef struct __anon_0x7C4AB {
    /* 0x0 */ void* pHost;
    /* 0x4 */ s32 nAddress;
} __anon_0x7C4AB; // size = 0x8

// Range: 0x80090280 -> 0x80090288
s32 serialPut8() {}

// Range: 0x80090278 -> 0x80090280
s32 serialPut16() {}

// Range: 0x80090138 -> 0x80090278
s32 serialPut32(struct __anon_0x7C4AB* pSerial, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x7C4AB* pSerial; // r31
    // u32 nAddress; // r1+0xC
    // s32* pData; // r1+0x10

    // Local variables
    s32 nSize; // r1+0x18
    void* aData; // r1+0x14
}

// Range: 0x80090130 -> 0x80090138
s32 serialPut64() {}

// Range: 0x80090128 -> 0x80090130
s32 serialGet8() {}

// Range: 0x80090120 -> 0x80090128
s32 serialGet16() {}

// Range: 0x800900BC -> 0x80090120
s32 serialGet32(struct __anon_0x7C4AB* pSerial, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x7C4AB* pSerial; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x800900B4 -> 0x800900BC
s32 serialGet64() {}

// Range: 0x8008FFB4 -> 0x800900B4
s32 serialEvent(struct __anon_0x7C4AB* pSerial, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x7C4AB* pSerial; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
