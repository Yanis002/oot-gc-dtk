/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\codeGCN.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8001C2DC -> 0x8001C330
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x22508; // size = 0x10

// size = 0x10, address = 0x80136AC0
struct _XL_OBJECTTYPE gClassCode;

typedef enum __anon_0x225FA {
    XLFT_NONE = -1,
    XLFT_TEXT = 0,
    XLFT_BINARY = 1,
} __anon_0x225FA;

typedef struct DVDDiskID {
    /* 0x0 */ char gameName[4];
    /* 0x4 */ char company[2];
    /* 0x6 */ u8 diskNumber;
    /* 0x7 */ u8 gameVersion;
    /* 0x8 */ u8 streaming;
    /* 0x9 */ u8 streamingBufSize;
    /* 0xA */ u8 padding[22];
} __anon_0x226B2; // size = 0x20

typedef struct DVDCommandBlock {
    /* 0x00 */ struct DVDCommandBlock* next;
    /* 0x04 */ struct DVDCommandBlock* prev;
    /* 0x08 */ u32 command;
    /* 0x0C */ s32 state;
    /* 0x10 */ u32 offset;
    /* 0x14 */ u32 length;
    /* 0x18 */ void* addr;
    /* 0x1C */ u32 currTransferSize;
    /* 0x20 */ u32 transferredSize;
    /* 0x24 */ struct DVDDiskID* id;
    /* 0x28 */ void (* callback)(s32, struct DVDCommandBlock*);
    /* 0x2C */ void* userData;
} __anon_0x22822; // size = 0x30

typedef struct DVDFileInfo {
    /* 0x00 */ struct DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (* callback)(s32, struct DVDFileInfo*);
} __anon_0x22A48; // size = 0x3C

typedef struct tXL_FILE {
    /* 0x00 */ void* pData;
    /* 0x04 */ char* acLine;
    /* 0x08 */ void* pBuffer;
    /* 0x0C */ s32 nAttributes;
    /* 0x10 */ s32 nSize;
    /* 0x14 */ s32 nOffset;
    /* 0x18 */ enum __anon_0x225FA eType;
    /* 0x1C */ s32 iLine;
    /* 0x20 */ s32 nLineNumber;
    /* 0x24 */ struct DVDFileInfo info;
} __anon_0x22B00; // size = 0x60

// size = 0x4, address = 0x801819C0
static void* gpBufferFunction;

// size = 0x4, address = 0x801819C4
static u32* ganDataCode;

typedef struct _CODE_CACHE_NODE {
    /* 0x0 */ s32 checksum;
    /* 0x4 */ s32 length;
    /* 0x8 */ struct _CODE_CACHE_NODE* next;
    /* 0xC */ struct _CODE_CACHE_NODE* child;
} __anon_0x22E07; // size = 0x10

// Erased
static s32 hioInitSend() {}

// Erased
static s32 hioCallbackDevice() {}

// Erased
static void hioCallback() {}

// Erased
static s32 hioSendBuffer() {}

// Erased
static s32 hioInit() {}

// Erased
static s32 codeSendFilePart() {}

// Erased
static s32 codeCheckCatalog(s32 nAddress0, s32 nAddress1) {
    // Parameters
    // s32 nAddress0; // r4
    // s32 nAddress1; // r5

    // Local variables
    s32 iFunction; // r1+0x8
    s32 instruction; // r31
    u32 checksum; // r1+0x14

    // References
    // -> static u32 gnCountFunction;
    // -> static u32* ganDataCode;
    // -> static s32 gCatalogLoaded;
}

// Range: 0x8001C2DC -> 0x8001C330
s32 codeEvent(s32 nEvent) {
    // Parameters
    // s32 nEvent; // r1+0x4

    // References
    // -> static u32* ganDataCode;
    // -> static void* gpBufferFunction;
}
