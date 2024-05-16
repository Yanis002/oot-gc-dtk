/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\pif.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8006BEE4 -> 0x8006CE14
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x4A8ED; // size = 0x10

// size = 0x10, address = 0x800EFBC0
struct _XL_OBJECTTYPE gClassPIF;

typedef struct __anon_0x4AA67 {
    /* 0x00 */ void* pROM;
    /* 0x04 */ void* pRAM;
    /* 0x08 */ void* pHost;
    /* 0x0C */ u16 controllerType[5];
    /* 0x16 */ char controllerStatus[5];
    /* 0x1C */ enum __anon_0x4B4F1 eControllerType[5];
} __anon_0x4AA67; // size = 0x30

typedef enum __anon_0x4B4F1 {
    CT_NONE = 0,
    CT_CONTROLLER = 1,
    CT_CONTROLLER_W_PAK = 2,
    CT_CONTROLLER_W_RPAK = 3,
    CT_MOUSE = 4,
    CT_VOICE = 5,
    CT_4K = 6,
    CT_16K = 7,
    CT_COUNT = 8,
} __anon_0x4B4F1;

// Erased
static s32 pifIdCheckSum(u16* ptr, u16* csum, u16* icsum) {
    // Parameters
    // u16* ptr; // r4
    // u16* csum; // r1+0x8
    // u16* icsum; // r1+0xC

    // Local variables
    u16 data; // r7
    u32 j; // r1+0x0
}

// Range: 0x8006CCF0 -> 0x8006CE14
s32 pifReadRumble(u16 address, u8* data) {
    // Parameters
    // u16 address; // r1+0x8
    // u8* data; // r1+0xC

    // Local variables
    s32 i; // r1+0x0
}

// Range: 0x8006CC98 -> 0x8006CCF0
s32 pifWriteRumble(s32 channel, u16 address, u8* data) {
    // Parameters
    // s32 channel; // r4
    // u16 address; // r1+0x10
    // u8* data; // r1+0x14
}

// Range: 0x8006CB20 -> 0x8006CC98
static u8 pifContDataCrc(u8* data) {
    // Parameters
    // u8* data; // r4

    // Local variables
    u32 temp; // r3
    u32 i; // r5
    u32 j; // r6
}

// Range: 0x8006CA10 -> 0x8006CB20
s32 pifSetControllerType(struct __anon_0x4AA67* pPIF, s32 channel, enum __anon_0x4B4F1 type) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r29
    // s32 channel; // r30
    // enum __anon_0x4B4F1 type; // r31
}

// Range: 0x8006C9F8 -> 0x8006CA10
s32 pifGetEControllerType(struct __anon_0x4AA67* pPIF, s32 channel, enum __anon_0x4B4F1* type) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // s32 channel; // r1+0x4
    // enum __anon_0x4B4F1* type; // r1+0x8
}

// Range: 0x8006C994 -> 0x8006C9F8
s32 pifSetEEPROMType(struct __anon_0x4AA67* pPIF, enum __anon_0x4B4F1 type) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // enum __anon_0x4B4F1 type; // r1+0x4
}

// Erased
static s32 pifGetControllerInput(s32 channel, u32* controllerInput) {
    // Parameters
    // s32 channel; // r4
    // u32* controllerInput; // r5
}

// Erased
static s32 pifGetControllerType(struct __anon_0x4AA67* pPIF, s32 channel, u16* type, char* status) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // s32 channel; // r1+0x4
    // u16* type; // r1+0x8
    // char* status; // r1+0xC

    // Local variables
    enum __anon_0x4B4F1 eType; // r1+0x0
}

// Range: 0x8006C950 -> 0x8006C994
s32 pifGetEEPROMSize(struct __anon_0x4AA67* pPIF, u32* size) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32* size; // r1+0x4
}

// Erased
static s32 pifQueryController(struct __anon_0x4AA67* pPIF, u8* buffer, u8* prx, s32 channel) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u8* buffer; // r1+0x4
    // u8* prx; // r1+0xC
    // s32 channel; // r1+0x10
}

// Erased
static s32 pifReadController(struct __anon_0x4AA67* pPIF, u8* buffer, u8* prx, s32 channel) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x8
    // u8* buffer; // r4
    // u8* prx; // r1+0x14
    // s32 channel; // r7

    // Local variables
    enum __anon_0x4B4F1 type; // r1+0x8
}

// Range: 0x8006C92C -> 0x8006C950
static s32 pifPut8(struct __anon_0x4AA67* pPIF, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // char* pData; // r1+0x8
}

// Range: 0x8006C904 -> 0x8006C92C
static s32 pifPut16(struct __anon_0x4AA67* pPIF, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s16* pData; // r1+0x8
}

// Range: 0x8006C8DC -> 0x8006C904
static s32 pifPut32(struct __anon_0x4AA67* pPIF, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8006C8A8 -> 0x8006C8DC
static s32 pifPut64(struct __anon_0x4AA67* pPIF, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s64* pData; // r1+0x8
}

// Range: 0x8006C874 -> 0x8006C8A8
static s32 pifGet8(struct __anon_0x4AA67* pPIF, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // char* pData; // r1+0x8
}

// Range: 0x8006C838 -> 0x8006C874
static s32 pifGet16(struct __anon_0x4AA67* pPIF, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s16* pData; // r1+0x8
}

// Range: 0x8006C7FC -> 0x8006C838
static s32 pifGet32(struct __anon_0x4AA67* pPIF, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s32* pData; // r1+0x8
}

// Range: 0x8006C7A8 -> 0x8006C7FC
static s32 pifGet64(struct __anon_0x4AA67* pPIF, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r1+0x0
    // u32 nAddress; // r1+0x4
    // s64* pData; // r1+0x8
}

// Range: 0x8006C504 -> 0x8006C7A8
s32 pifExecuteCommand(struct __anon_0x4AA67* pPIF, u8* buffer, u8* prx, s32 channel) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r30
    // u8* buffer; // r31
    // u8* prx; // r1+0x14
    // s32 channel; // r7
}

// Range: 0x8006C374 -> 0x8006C504
s32 pifProcessInputData(struct __anon_0x4AA67* pPIF) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r30

    // Local variables
    u8* prx; // r6
    u8* ptx; // r5
    s32 iData; // r29
    s32 channel; // r31
}

// Range: 0x8006C1D8 -> 0x8006C374
s32 pifProcessOutputData(struct __anon_0x4AA67* pPIF) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r29

    // Local variables
    u8* prx; // r6
    u8* ptx; // r5
    s32 iData; // r31
    s32 channel; // r30
}

// Range: 0x8006C178 -> 0x8006C1D8
s32 pifSetData(struct __anon_0x4AA67* pPIF, u8* acData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r31
    // u8* acData; // r4
}

// Range: 0x8006C10C -> 0x8006C178
s32 pifGetData(struct __anon_0x4AA67* pPIF, u8* acData) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r30
    // u8* acData; // r31
}

// Range: 0x8006BEE4 -> 0x8006C10C
s32 pifEvent(struct __anon_0x4AA67* pPIF, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x4AA67* pPIF; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31

    // Local variables
    s32 i; // r31
}
