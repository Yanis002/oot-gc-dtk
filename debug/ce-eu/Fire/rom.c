/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\rom.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8006D6F4 -> 0x80071054
*/

#include "types.h"

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0x4FDD4; // size = 0x10

// size = 0x10, address = 0x80139BD8
struct _XL_OBJECTTYPE gClassROM;

// size = 0x318, address = 0x80139BE8
static u32 ganOffsetBlock_ZLP[198];

// size = 0x318, address = 0x80139F00
static u32 ganOffsetBlock_URAZLP[198];

// size = 0x4, address = 0x80181AA0
static s32 gbProgress;

// size = 0x4, address = 0x80181AA4
static void* gpImageBack;

// size = 0x4, address = 0x80181AA8
static s32 iImage$401;

typedef enum __anon_0x50021 {
    RLM_NONE = -1,
    RLM_PART = 0,
    RLM_FULL = 1,
    RLM_COUNT_ = 2,
} __anon_0x50021;

typedef struct __anon_0x50080 {
    /* 0x0 */ s32 iCache;
    /* 0x4 */ u32 nSize;
    /* 0x8 */ u32 nTickUsed;
    /* 0xC */ char keep;
} __anon_0x50080; // size = 0x10

typedef struct __anon_0x50194 {
    /* 0x00 */ s32 bWait;
    /* 0x04 */ s32 (* pCallback)();
    /* 0x08 */ u8* pTarget;
    /* 0x0C */ u32 nSize;
    /* 0x10 */ u32 nOffset;
} __anon_0x50194; // size = 0x14

typedef struct __anon_0x50274 {
    /* 0x00 */ s32 bWait;
    /* 0x04 */ s32 bDone;
    /* 0x08 */ s32 nResult;
    /* 0x0C */ u8* anData;
    /* 0x10 */ s32 (* pCallback)();
    /* 0x14 */ s32 iCache;
    /* 0x18 */ s32 iBlock;
    /* 0x1C */ s32 nOffset;
    /* 0x20 */ u32 nOffset0;
    /* 0x24 */ u32 nOffset1;
    /* 0x28 */ u32 nSize;
    /* 0x2C */ u32 nSizeRead;
} __anon_0x50274; // size = 0x30

typedef struct __anon_0x5045F {
    /* 0x0 */ s32 nPosition;
    /* 0x4 */ s32 nLineNumber;
} __anon_0x5045F; // size = 0x8

typedef struct __anon_0x504C3 {
    /* 0x0 */ s32 nMode;
    /* 0x4 */ s32 nModeSave;
    /* 0x8 */ struct __anon_0x5045F save;
} __anon_0x504C3; // size = 0x10

typedef struct DVDDiskID {
    /* 0x0 */ char gameName[4];
    /* 0x4 */ char company[2];
    /* 0x6 */ u8 diskNumber;
    /* 0x7 */ u8 gameVersion;
    /* 0x8 */ u8 streaming;
    /* 0x9 */ u8 streamingBufSize;
    /* 0xA */ u8 padding[22];
} __anon_0x505A4; // size = 0x20

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
} __anon_0x50714; // size = 0x30

typedef struct DVDFileInfo {
    /* 0x00 */ struct DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (* callback)(s32, struct DVDFileInfo*);
} __anon_0x5093A; // size = 0x3C

typedef struct __anon_0x509F2 {
    /* 0x00000 */ void* pHost;
    /* 0x00004 */ void* pBuffer;
    /* 0x00008 */ s32 bFlip;
    /* 0x0000C */ s32 bLoad;
    /* 0x00010 */ char acNameFile[513];
    /* 0x00214 */ u32 nSize;
    /* 0x00218 */ enum __anon_0x50021 eModeLoad;
    /* 0x0021C */ struct __anon_0x50080 aBlock[4096];
    /* 0x1021C */ u32 nTick;
    /* 0x10220 */ u8* pCacheRAM;
    /* 0x10224 */ u8 anBlockCachedRAM[1024];
    /* 0x10624 */ u8 anBlockCachedARAM[2046];
    /* 0x10E24 */ struct __anon_0x50194 copy;
    /* 0x10E38 */ struct __anon_0x50274 load;
    /* 0x10E68 */ s32 nCountBlockRAM;
    /* 0x10E6C */ s32 nSizeCacheRAM;
    /* 0x10E70 */ u8 acHeader[64];
    /* 0x10EB0 */ u32* anOffsetBlock;
    /* 0x10EB4 */ s32 nCountOffsetBlocks;
    /* 0x10EB8 */ struct __anon_0x504C3 tagFile;
    /* 0x10EC8 */ u32 nChecksum;
    /* 0x10ECC */ struct DVDFileInfo fileInfo;
    /* 0x10F08 */ s32 offsetToRom;
} __anon_0x509F2; // size = 0x10F0C

typedef enum __anon_0x50E2A {
    XLFT_NONE = -1,
    XLFT_TEXT = 0,
    XLFT_BINARY = 1,
} __anon_0x50E2A;

typedef struct tXL_FILE {
    /* 0x00 */ void* pData;
    /* 0x04 */ char* acLine;
    /* 0x08 */ void* pBuffer;
    /* 0x0C */ s32 nAttributes;
    /* 0x10 */ s32 nSize;
    /* 0x14 */ s32 nOffset;
    /* 0x18 */ enum __anon_0x50E2A eType;
    /* 0x1C */ s32 iLine;
    /* 0x20 */ s32 nLineNumber;
    /* 0x24 */ struct DVDFileInfo info;
} __anon_0x50E7E; // size = 0x60

typedef struct __anon_0x5100A {
    /* 0x0 */ struct tXL_FILE* pFile;
} __anon_0x5100A; // size = 0x4

typedef enum __anon_0x51047 {
    RTT_NONE = -1,
    RTT_CODE = 0,
    RTT_CODE_INVALID = 1,
    RTT_NAME = 2,
    RTT_NAME_INVALID = 3,
    RTT_DATA_STRING = 4,
    RTT_DATA_NUMBER = 5,
    RTT_DONE = 6,
    RTT_LAST_ = 7,
} __anon_0x51047;

typedef struct __anon_0x52ADB {
    /* 0x0 */ s32 nOffsetHost;
    /* 0x4 */ s32 nAddressN64;
} __anon_0x52ADB; // size = 0x8

typedef struct cpu_callerID {
    /* 0x0 */ s32 N64address;
    /* 0x4 */ s32 GCNaddress;
} __anon_0x52B41; // size = 0x8

typedef struct cpu_function {
    /* 0x00 */ void* pnBase;
    /* 0x04 */ void* pfCode;
    /* 0x08 */ s32 nCountJump;
    /* 0x0C */ struct __anon_0x52ADB* aJump;
    /* 0x10 */ s32 nAddress0;
    /* 0x14 */ s32 nAddress1;
    /* 0x18 */ struct cpu_callerID* block;
    /* 0x1C */ s32 callerID_total;
    /* 0x20 */ s32 callerID_flag;
    /* 0x24 */ u32 nChecksum;
    /* 0x28 */ s32 timeToLive;
    /* 0x2C */ s32 memory_size;
    /* 0x30 */ s32 heapID;
    /* 0x34 */ s32 heapWhere;
    /* 0x38 */ s32 treeheapWhere;
    /* 0x3C */ struct cpu_function* prev;
    /* 0x40 */ struct cpu_function* left;
    /* 0x44 */ struct cpu_function* right;
} __anon_0x52BB4; // size = 0x48

typedef union __anon_0x52E90 {
    /* 0x0 */ char _0s8;
    /* 0x1 */ char _1s8;
    /* 0x2 */ char _2s8;
    /* 0x3 */ char _3s8;
    /* 0x4 */ char _4s8;
    /* 0x5 */ char _5s8;
    /* 0x6 */ char _6s8;
    /* 0x7 */ char s8;
    /* 0x0 */ s16 _0s16;
    /* 0x2 */ s16 _1s16;
    /* 0x4 */ s16 _2s16;
    /* 0x6 */ s16 s16;
    /* 0x0 */ s32 _0s32;
    /* 0x4 */ s32 s32;
    /* 0x0 */ s64 s64;
    /* 0x0 */ u8 _0u8;
    /* 0x1 */ u8 _1u8;
    /* 0x2 */ u8 _2u8;
    /* 0x3 */ u8 _3u8;
    /* 0x4 */ u8 _4u8;
    /* 0x5 */ u8 _5u8;
    /* 0x6 */ u8 _6u8;
    /* 0x7 */ u8 u8;
    /* 0x0 */ u16 _0u16;
    /* 0x2 */ u16 _1u16;
    /* 0x4 */ u16 _2u16;
    /* 0x6 */ u16 u16;
    /* 0x0 */ u32 _0u32;
    /* 0x4 */ u32 u32;
    /* 0x0 */ u64 u64;
} __anon_0x52E90;

typedef union __anon_0x532A4 {
    /* 0x0 */ f32 _0f32;
    /* 0x4 */ f32 f32;
    /* 0x0 */ f64 f64;
    /* 0x0 */ s32 _0s32;
    /* 0x4 */ s32 s32;
    /* 0x0 */ s64 s64;
    /* 0x0 */ u32 _0u32;
    /* 0x4 */ u32 u32;
    /* 0x0 */ u64 u64;
} __anon_0x532A4;

typedef struct __anon_0x537B2 {
    /* 0x00 */ s32 nType;
    /* 0x04 */ void* pObject;
    /* 0x08 */ s32 nOffsetAddress;
    /* 0x0C */ s32 (* pfGet8)(void*, u32, char*);
    /* 0x10 */ s32 (* pfGet16)(void*, u32, s16*);
    /* 0x14 */ s32 (* pfGet32)(void*, u32, s32*);
    /* 0x18 */ s32 (* pfGet64)(void*, u32, s64*);
    /* 0x1C */ s32 (* pfPut8)(void*, u32, char*);
    /* 0x20 */ s32 (* pfPut16)(void*, u32, s16*);
    /* 0x24 */ s32 (* pfPut32)(void*, u32, s32*);
    /* 0x28 */ s32 (* pfPut64)(void*, u32, s64*);
    /* 0x2C */ u32 nAddressPhysical0;
    /* 0x30 */ u32 nAddressPhysical1;
} __anon_0x537B2; // size = 0x34

typedef struct cpu_treeRoot {
    /* 0x00 */ u16 total;
    /* 0x04 */ s32 total_memory;
    /* 0x08 */ s32 root_address;
    /* 0x0C */ s32 start_range;
    /* 0x10 */ s32 end_range;
    /* 0x14 */ s32 cache_miss;
    /* 0x18 */ s32 cache[20];
    /* 0x68 */ struct cpu_function* left;
    /* 0x6C */ struct cpu_function* right;
    /* 0x70 */ s32 kill_limit;
    /* 0x74 */ s32 kill_number;
    /* 0x78 */ s32 side;
    /* 0x7C */ struct cpu_function* restore;
    /* 0x80 */ s32 restore_side;
} __anon_0x53A80; // size = 0x84

typedef struct _CPU_ADDRESS {
    /* 0x0 */ s32 nN64;
    /* 0x4 */ s32 nHost;
    /* 0x8 */ struct cpu_function* pFunction;
} __anon_0x53CC1; // size = 0xC

typedef struct __anon_0x53D76 {
    /* 0x0 */ u32 nAddress;
    /* 0x4 */ u32 nOpcodeOld;
    /* 0x8 */ u32 nOpcodeNew;
} __anon_0x53D76; // size = 0xC

typedef struct OSContext {
    /* 0x000 */ u32 gpr[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ f64 fpr[32];
    /* 0x190 */ u32 fpscr_pad;
    /* 0x194 */ u32 fpscr;
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqr[8];
    /* 0x1C4 */ u32 psf_pad;
    /* 0x1C8 */ f64 psf[32];
} __anon_0x53EA1; // size = 0x2C8

typedef struct OSAlarm {
    /* 0x00 */ void (* handler)(struct OSAlarm*, struct OSContext*);
    /* 0x04 */ u32 tag;
    /* 0x08 */ s64 fire;
    /* 0x10 */ struct OSAlarm* prev;
    /* 0x14 */ struct OSAlarm* next;
    /* 0x18 */ s64 period;
    /* 0x20 */ s64 start;
} __anon_0x540F8; // size = 0x28

typedef struct cpu_optimize {
    /* 0x00 */ u32 validCheck;
    /* 0x04 */ u32 destGPR_check;
    /* 0x08 */ s32 destGPR;
    /* 0x0C */ s32 destGPR_mapping;
    /* 0x10 */ u32 destFPR_check;
    /* 0x14 */ s32 destFPR;
    /* 0x18 */ u32 addr_check;
    /* 0x1C */ s32 addr_last;
    /* 0x20 */ u32 checkType;
    /* 0x24 */ u32 checkNext;
} __anon_0x54213; // size = 0x28

typedef struct _CPU {
    /* 0x00000 */ s32 nMode;
    /* 0x00004 */ s32 nTick;
    /* 0x00008 */ void* pHost;
    /* 0x00010 */ s64 nLo;
    /* 0x00018 */ s64 nHi;
    /* 0x00020 */ s32 nCountAddress;
    /* 0x00024 */ s32 iDeviceDefault;
    /* 0x00028 */ u32 nPC;
    /* 0x0002C */ u32 nWaitPC;
    /* 0x00030 */ u32 nCallLast;
    /* 0x00034 */ struct cpu_function* pFunctionLast;
    /* 0x00038 */ s32 nReturnAddrLast;
    /* 0x0003C */ s32 survivalTimer;
    /* 0x00040 */ union __anon_0x52E90 aGPR[32];
    /* 0x00140 */ union __anon_0x532A4 aFPR[32];
    /* 0x00240 */ u64 aTLB[48][5];
    /* 0x009C0 */ s32 anFCR[32];
    /* 0x00A40 */ s64 anCP0[32];
    /* 0x00B40 */ s32 (* pfStep)(struct _CPU*);
    /* 0x00B44 */ s32 (* pfJump)(struct _CPU*);
    /* 0x00B48 */ s32 (* pfCall)(struct _CPU*);
    /* 0x00B4C */ s32 (* pfIdle)(struct _CPU*);
    /* 0x00B50 */ s32 (* pfRam)(struct _CPU*);
    /* 0x00B54 */ s32 (* pfRamF)(struct _CPU*);
    /* 0x00B58 */ u32 nTickLast;
    /* 0x00B5C */ u32 nRetrace;
    /* 0x00B60 */ u32 nRetraceUsed;
    /* 0x00B64 */ struct __anon_0x537B2* apDevice[256];
    /* 0x00F64 */ u8 aiDevice[65536];
    /* 0x10F64 */ void* gHeap1;
    /* 0x10F68 */ void* gHeap2;
    /* 0x10F6C */ u32 aHeap1Flag[192];
    /* 0x1126C */ u32 aHeap2Flag[13];
    /* 0x112A0 */ struct cpu_treeRoot* gTree;
    /* 0x112A4 */ struct _CPU_ADDRESS aAddressCache[256];
    /* 0x11EA4 */ s32 nCountCodeHack;
    /* 0x11EA8 */ struct __anon_0x53D76 aCodeHack[32];
    /* 0x12028 */ s64 nTimeRetrace;
    /* 0x12030 */ struct OSAlarm alarmRetrace;
    /* 0x12058 */ u32 nFlagRAM;
    /* 0x1205C */ u32 nFlagCODE;
    /* 0x12060 */ u32 nCompileFlag;
    /* 0x12064 */ struct cpu_optimize nOptimize;
} __anon_0x543C0; // size = 0x12090

typedef enum __anon_0x54BE1 {
    SM_NONE = -1,
    SM_RUNNING = 0,
    SM_STOPPED = 1,
} __anon_0x54BE1;

typedef struct __anon_0x54C44 {
    /* 0x0 */ s32 nSize;
    /* 0x4 */ s32 nOffsetRAM;
    /* 0x8 */ s32 nOffsetROM;
    /* 0xC */ s32 (* pCallback)();
} __anon_0x54C44; // size = 0x10

typedef enum __anon_0x54CF5 {
    SRT_NONE = -1,
    SRT_MARIO = 0,
    SRT_WAVERACE = 1,
    SRT_MARIOKART = 2,
    SRT_STARFOX = 3,
    SRT_ZELDA1 = 4,
    SRT_ZELDA2 = 5,
    SRT_1080 = 6,
    SRT_PANEL = 7,
    SRT_MARIOPARTY1 = 8,
    SRT_MARIOPARTY2 = 9,
    SRT_MARIOPARTY3 = 10,
    SRT_DRMARIO = 11,
    SRT_UNKNOWN = 12,
} __anon_0x54CF5;

typedef enum __anon_0x54E21 {
    SOT_NONE = -1,
    SOT_CPU = 0,
    SOT_PIF = 1,
    SOT_RAM = 2,
    SOT_ROM = 3,
    SOT_RSP = 4,
    SOT_RDP = 5,
    SOT_MIPS = 6,
    SOT_DISK = 7,
    SOT_FLASH = 8,
    SOT_SRAM = 9,
    SOT_AUDIO = 10,
    SOT_VIDEO = 11,
    SOT_SERIAL = 12,
    SOT_LIBRARY = 13,
    SOT_PERIPHERAL = 14,
    SOT_RDB = 15,
    SOT_COUNT = 16,
} __anon_0x54E21;

typedef struct __anon_0x54F5C {
    /* 0x00 */ void* pFrame;
    /* 0x04 */ void* pSound;
    /* 0x08 */ s32 bException;
    /* 0x0C */ enum __anon_0x54BE1 eMode;
    /* 0x10 */ struct __anon_0x54C44 romCopy;
    /* 0x20 */ enum __anon_0x54CF5 eTypeROM;
    /* 0x24 */ void* apObject[16];
    /* 0x68 */ u64 nAddressBreak;
    /* 0x70 */ enum __anon_0x54E21 storageDevice;
    /* 0x74 */ u8 anException[16];
    /* 0x84 */ s32 bJapaneseVersion;
} __anon_0x54F5C; // size = 0x88

// size = 0x4, address = 0x80181944
struct __anon_0x54F5C* gpSystem;

// size = 0x4, address = 0x8018191C
s32 gDVDResetToggle;

// size = 0x1, address = 0x80181914
u8 gLanguage;

// size = 0x4, address = 0x80181A18
u32 gnFlagZelda;

// size = 0x4, address = 0x80181940
s32 gbDisplayedError;

typedef struct _GXTexObj {
    /* 0x0 */ u32 dummy[8];
} __anon_0x5560B; // size = 0x20

typedef enum __anon_0x55BD8 {
    RCT_NONE = -1,
    RCT_RAM = 0,
    RCT_ARAM = 1,
} __anon_0x55BD8;

typedef enum __anon_0x5632E {
    XLFTT_NONE = -1,
    XLFTT_LABEL = 0,
    XLFTT_NUMBER = 1,
    XLFTT_STRING = 2,
    XLFTT_SYMBOL = 3,
    XLFTT_LAST_ = 4,
} __anon_0x5632E;

// Range: 0x800709A4 -> 0x80071054
static s32 romGetTagToken(struct __anon_0x509F2* pROM, struct tXL_FILE* pFile, enum __anon_0x51047* peToken, char* acData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r27
    // struct tXL_FILE* pFile; // r28
    // enum __anon_0x51047* peToken; // r29
    // char* acData; // r30

    // Local variables
    u32 nChecksum; // r1+0x60
    enum __anon_0x5632E eTypeToken; // r1+0x5C
    char acToken[65]; // r1+0x18
}

// Erased
static s32 romTestARAM() {}

// Erased
static s32 romMatchRange(struct __anon_0x509F2* pROM, u32 nOffset, s32* pnOffset0, s32* pnOffset1) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // u32 nOffset; // r1+0x4
    // s32* pnOffset0; // r1+0x8
    // s32* pnOffset1; // r1+0xC

    // Local variables
    s32 iBlock; // r10
}

// Erased
static s32 romFreeBlock(struct __anon_0x509F2* pROM, s32 iBlock) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // s32 iBlock; // r1+0x4

    // Local variables
    s32 iCache; // r4
    struct __anon_0x50080* pBlock; // r1+0x0
}

// Range: 0x800708E0 -> 0x800709A4
static s32 romFindFreeCache(struct __anon_0x509F2* pROM, s32* piCache, enum __anon_0x55BD8 eType) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // s32* piCache; // r1+0x4
    // enum __anon_0x55BD8 eType; // r1+0x8

    // Local variables
    s32 iBlock; // r7
}

// Range: 0x80070730 -> 0x800708E0
static s32 romFindOldestBlock(struct __anon_0x509F2* pROM, s32* piBlock, enum __anon_0x55BD8 eTypeCache, s32 whichBlock) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // s32* piBlock; // r1+0x4
    // enum __anon_0x55BD8 eTypeCache; // r1+0x8
    // s32 whichBlock; // r1+0xC

    // Local variables
    struct __anon_0x50080* pBlock; // r7
    s32 iBlock; // r8
    s32 iBlockOldest; // r9
    u32 nTick; // r10
    u32 nTickDelta; // r11
    u32 nTickDeltaOldest; // r12
}

// Range: 0x8007051C -> 0x80070730
static s32 romMakeFreeCache(struct __anon_0x509F2* pROM, s32* piCache, enum __anon_0x55BD8 eType) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r30
    // s32* piCache; // r31
    // enum __anon_0x55BD8 eType; // r1+0x10

    // Local variables
    s32 iCache; // r1+0x20
    s32 iBlockOldest; // r1+0x1C
}

// Range: 0x800702C4 -> 0x8007051C
static s32 romSetBlockCache(struct __anon_0x509F2* pROM, s32 iBlock, enum __anon_0x55BD8 eType) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r30
    // s32 iBlock; // r1+0xC
    // enum __anon_0x55BD8 eType; // r1+0x10

    // Local variables
    struct __anon_0x50080* pBlock; // r31
    s32 iCacheRAM; // r1+0x18
    s32 iCacheARAM; // r1+0x14
    s32 nOffsetRAM; // r28
    s32 nOffsetARAM; // r29
}

// Range: 0x800701D0 -> 0x800702C4
static s32 __romLoadBlock_Complete(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x8

    // Local variables
    u32 iData; // r9
    u32 nData; // r1+0x8
}

// Range: 0x800701B4 -> 0x800701D0
static void __romLoadBlock_CompleteGCN(s32 nResult) {
    // Parameters
    // s32 nResult; // r1+0x0

    // Local variables
    struct __anon_0x509F2* pROM; // r4

    // References
    // -> struct __anon_0x54F5C* gpSystem;
}

// Range: 0x800700B8 -> 0x800701B4
static s32 romLoadBlock(struct __anon_0x509F2* pROM, s32 iBlock, s32 iCache, s32 (* pCallback)()) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r31
    // s32 iBlock; // r1+0xC
    // s32 iCache; // r1+0x10
    // s32 (* pCallback)(); // r1+0x14

    // Local variables
    u8* anData; // r8
    s32 nSizeRead; // r10
    u32 nSize; // r10
    u32 nOffset; // r1+0x8
}

// Erased
static s32 romKeepCheck() {}

// Range: 0x8006FF6C -> 0x800700B8
static s32 romLoadRange(struct __anon_0x509F2* pROM, s32 begin, s32 end, s32* blockCount, s32 whichBlock, s32 (* pfProgress)(f32)) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r26
    // s32 begin; // r1+0xC
    // s32 end; // r1+0x10
    // s32* blockCount; // r27
    // s32 whichBlock; // r1+0x18
    // s32 (* pfProgress)(f32); // r28

    // Local variables
    s32 iCache; // r1+0x20
    u32 iBlock; // r30
    u32 iBlockLast; // r29
}

// Range: 0x8006FCEC -> 0x8006FF6C
static s32 romCacheGame_ZELDA(f32 rProgress) {
    // Parameters
    // f32 rProgress; // f31

    // Local variables
    s32 nSize; // r31
    f32 matrix44[4][4]; // r1+0x2C
    struct _GXTexObj textureObject; // r1+0xC

    // References
    // -> static s32 gbProgress;
    // -> static s32 iImage$401;
    // -> struct __anon_0x54F5C* gpSystem;
    // -> static void* gpImageBack;
    // -> s32 gbDisplayedError;
}

// Range: 0x8006F250 -> 0x8006FCEC
static s32 romCacheGame(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r31

    // Local variables
    s32 blockCount; // r1+0x14
    s32 bZeldaE; // r8
    s32 bZeldaF; // r6
    s32 bZeldaG; // r7
    s32 bZeldaI; // r9
    s32 bZeldaS; // r10
    s32 nSize; // r30
    char* szName; // r5
    struct tXL_FILE* pFile; // r1+0xC

    // References
    // -> s32 gDVDResetToggle;
    // -> u32 gnFlagZelda;
    // -> s32 gbDisplayedError;
    // -> static s32 gbProgress;
    // -> static void* gpImageBack;
    // -> static u32 ganOffsetBlock_URAZLP[198];
    // -> static u32 ganOffsetBlock_ZLP[198];
    // -> u8 gLanguage;
}

// Range: 0x8006F234 -> 0x8006F250
static s32 __romLoadUpdate_Complete() {
    // References
    // -> struct __anon_0x54F5C* gpSystem;
}

// Erased
static s32 romLoadInProgress(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
}

// Range: 0x8006F0D4 -> 0x8006F234
static s32 romLoadUpdate(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r29

    // Local variables
    s32 iCache; // r1+0xC
    struct __anon_0x50080* pBlock; // r4
    u32 iBlock0; // r31
    u32 iBlock1; // r25
    struct _CPU* pCPU; // r30
}

// Range: 0x8006F0B8 -> 0x8006F0D4
static s32 __romCopyUpdate_Complete() {
    // References
    // -> struct __anon_0x54F5C* gpSystem;
}

// Range: 0x8006EE34 -> 0x8006F0B8
static s32 romCopyUpdate(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r29

    // Local variables
    struct __anon_0x50080* pBlock; // r28
    s32 iCache; // r1+0xC
    s32 nTickLast; // r27
    u8* anData; // r1+0x8
    u32 iBlock; // r26
    u32 nSize; // r26
    u32 nOffsetBlock; // r1+0x8
    struct _CPU* pCPU; // r30
}

// Erased
static s32 romCacheAllBlocks(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r27

    // Local variables
    s32 iCache; // r1+0xC
    u32 iBlock; // r28
    u32 iBlockLast; // r1+0x8
}

// Range: 0x8006E9CC -> 0x8006EE34
static s32 romLoadFullOrPart(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r31

    // Local variables
    struct tXL_FILE* pFile; // r1+0x1C
    s32 iBlock; // r1+0x8
    s32 nLoad; // r27
    s32 nStep; // r28
    s32 iData; // r7
    u32 nData; // r1+0x8
}

// Erased
static s32 romLoad(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r31
}

// Range: 0x8006E7D0 -> 0x8006E9CC
s32 romGetPC(struct __anon_0x509F2* pROM, u64* pnPC) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // u64* pnPC; // r31

    // Local variables
    s32 nOffset; // r5
    u32 nData; // r5
    u32 iData; // r1+0x8
    u32 anData[1024]; // r1+0x18
}

// Range: 0x8006E79C -> 0x8006E7D0
s32 romGetCode(struct __anon_0x509F2* pROM, char* acCode) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // char* acCode; // r1+0x4
}

// Erased
static s32 romGetName(struct __anon_0x509F2* pROM, char* acName) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // char* acName; // r1+0x4

    // Local variables
    s32 iName; // r10
}

// Erased
static s32 romGetMask(struct __anon_0x509F2* pROM, s32* pnMask) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // s32* pnMask; // r1+0x4
}

// Range: 0x8006E628 -> 0x8006E79C
s32 romTestCode(struct __anon_0x509F2* pROM, char* acCode) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // char* acCode; // r1+0x4

    // Local variables
    s32 iCode; // r5
    s32 nCode1; // r5
    s32 nCode2; // r6
}

// Range: 0x8006E620 -> 0x8006E628
static s32 romPut8() {}

// Range: 0x8006E618 -> 0x8006E620
static s32 romPut16() {}

// Range: 0x8006E610 -> 0x8006E618
static s32 romPut32() {}

// Range: 0x8006E608 -> 0x8006E610
static s32 romPut64() {}

// Range: 0x8006E598 -> 0x8006E608
static s32 romGet8(struct __anon_0x509F2* pROM, u32 nAddress, char* pData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // u32 nAddress; // r4
    // char* pData; // r31

    // Local variables
    u8 nData; // r1+0x14
}

// Range: 0x8006E528 -> 0x8006E598
static s32 romGet16(struct __anon_0x509F2* pROM, u32 nAddress, s16* pData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // u32 nAddress; // r4
    // s16* pData; // r31

    // Local variables
    u16 nData; // r1+0x14
}

// Range: 0x8006E4B8 -> 0x8006E528
static s32 romGet32(struct __anon_0x509F2* pROM, u32 nAddress, s32* pData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // u32 nAddress; // r4
    // s32* pData; // r31

    // Local variables
    u32 nData; // r1+0x14
}

// Range: 0x8006E43C -> 0x8006E4B8
static s32 romGet64(struct __anon_0x509F2* pROM, u32 nAddress, s64* pData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // u32 nAddress; // r4
    // s64* pData; // r31

    // Local variables
    u64 nData; // r1+0x18
}

// Range: 0x8006E434 -> 0x8006E43C
static s32 romPutDebug8() {}

// Range: 0x8006E42C -> 0x8006E434
static s32 romPutDebug16() {}

// Range: 0x8006E424 -> 0x8006E42C
static s32 romPutDebug32() {}

// Range: 0x8006E41C -> 0x8006E424
static s32 romPutDebug64() {}

// Range: 0x8006E40C -> 0x8006E41C
static s32 romGetDebug8(char* pData) {
    // Parameters
    // char* pData; // r1+0x8
}

// Range: 0x8006E3FC -> 0x8006E40C
static s32 romGetDebug16(s16* pData) {
    // Parameters
    // s16* pData; // r1+0x8
}

// Range: 0x8006E3EC -> 0x8006E3FC
static s32 romGetDebug32(s32* pData) {
    // Parameters
    // s32* pData; // r1+0x8
}

// Range: 0x8006E3D8 -> 0x8006E3EC
static s32 romGetDebug64(s64* pData) {
    // Parameters
    // s64* pData; // r1+0x8
}

// Erased
static s32 romGetSize(struct __anon_0x509F2* pROM, s32* pnSize) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // s32* pnSize; // r1+0x4
}

// Range: 0x8006E140 -> 0x8006E3D8
s32 romCopy(struct __anon_0x509F2* pROM, void* pTarget, s32 nOffset, u32 nSize, s32 (* pCallback)()) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r27
    // void* pTarget; // r28
    // s32 nOffset; // r29
    // u32 nSize; // r30
    // s32 (* pCallback)(); // r31

    // Local variables
    void* pSource; // r4
    struct tXL_FILE* pFile; // r1+0x1C
}

// Range: 0x8006DED8 -> 0x8006E140
s32 romCopyImmediate(struct __anon_0x509F2* pROM, void* pTarget, s32 nOffsetROM, u32 nSize) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r26
    // void* pTarget; // r27
    // s32 nOffsetROM; // r28
    // u32 nSize; // r29

    // Local variables
    void* pSource; // r4
    struct __anon_0x50080* pBlock; // r3
    s32 nOffsetARAM; // r23
    s32 nSizeCopy; // r31
    s32 nOffsetBlock; // r1+0x8
    s32 nSizeCopyARAM; // r22
    s32 nSizeDMA; // r21
    s32 nOffset; // r20
    s32 nOffsetTarget; // r19
    u8* pBuffer; // r30
    u8 anBuffer[608]; // r1+0x18
}

// Range: 0x8006DD78 -> 0x8006DED8
s32 romUpdate(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r31

    // Local variables
    s32 nStatus; // r30
}

// Erased
static s32 romCopyBusy(struct __anon_0x509F2* pROM) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
}

// Range: 0x8006DCDC -> 0x8006DD78
s32 romSetCacheSize(struct __anon_0x509F2* pROM, s32 nSize) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r30
    // s32 nSize; // r4
}

// Erased
static s32 romGetCacheSize(struct __anon_0x509F2* pROM, s32* pnSize) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // s32* pnSize; // r1+0x4
}

// Range: 0x8006D96C -> 0x8006DCDC
s32 romSetImage(struct __anon_0x509F2* pROM, char* szNameFile) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r29
    // char* szNameFile; // r30

    // Local variables
    struct tXL_FILE* pFile; // r1+0x464
    enum __anon_0x51047 eToken; // r1+0x460
    s32 iCode; // r1+0x8
    s32 iName; // r5
    s32 nSize; // r1+0x45C
    char acToken[65]; // r1+0x418
    u32 anData[256]; // r1+0x18
}

// Range: 0x8006D924 -> 0x8006D96C
s32 romGetImage(struct __anon_0x509F2* pROM, char* acNameFile) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x0
    // char* acNameFile; // r1+0x4

    // Local variables
    s32 iName; // r6
}

// Erased
static s32 romOpenTags(struct __anon_0x509F2* pROM, struct __anon_0x5100A* pTag) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r1+0x8
    // struct __anon_0x5100A* pTag; // r30
}

// Erased
static s32 romFreeTags(struct __anon_0x5100A* pTag) {
    // Parameters
    // struct __anon_0x5100A* pTag; // r4
}

// Erased
static s32 romFindTagLabel(struct __anon_0x509F2* pROM, struct __anon_0x5100A* pTag, char* szLabel) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r29
    // struct __anon_0x5100A* pTag; // r30
    // char* szLabel; // r31

    // Local variables
    enum __anon_0x51047 eToken; // r1+0x58
    char acToken[65]; // r1+0x14
}

// Erased
static s32 romGetTagNumber(struct __anon_0x509F2* pROM, struct __anon_0x5100A* pTag, s32* pnData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // struct __anon_0x5100A* pTag; // r4
    // s32* pnData; // r31

    // Local variables
    enum __anon_0x51047 eToken; // r1+0x58
    char acToken[65]; // r1+0x14
}

// Erased
static s32 romGetTagString(struct __anon_0x509F2* pROM, struct __anon_0x5100A* pTag, char* acString, s32 nSizeString) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // struct __anon_0x5100A* pTag; // r4
    // char* acString; // r30
    // s32 nSizeString; // r31

    // Local variables
    enum __anon_0x51047 eToken; // r1+0x5C
    char acToken[65]; // r1+0x18
}

// Erased
static s32 romGetTagBoolean(struct __anon_0x509F2* pROM, struct __anon_0x5100A* pTag, s32* pnData) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r3
    // struct __anon_0x5100A* pTag; // r4
    // s32* pnData; // r31

    // Local variables
    s32 nValue; // r1+0x5C
    enum __anon_0x51047 eToken; // r1+0x58
    char acToken[65]; // r1+0x14
}

// Range: 0x8006D6F4 -> 0x8006D924
s32 romEvent(struct __anon_0x509F2* pROM, s32 nEvent, void* pArgument) {
    // Parameters
    // struct __anon_0x509F2* pROM; // r30
    // s32 nEvent; // r1+0xC
    // void* pArgument; // r31
}
