/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\THPRead.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x8001112C -> 0x80012DD8
*/

#include "types.h"

// size = 0x4, address = 0x80181980
static s32 ReadThreadCreated;

typedef struct OSThreadQueue {
    /* 0x0 */ struct OSThread* head;
    /* 0x4 */ struct OSThread* tail;
} __anon_0x173C1; // size = 0x8

typedef struct OSMessageQueue {
    /* 0x00 */ struct OSThreadQueue queueSend;
    /* 0x08 */ struct OSThreadQueue queueReceive;
    /* 0x10 */ void* msgArray;
    /* 0x14 */ s32 msgCount;
    /* 0x18 */ s32 firstIndex;
    /* 0x1C */ s32 usedCount;
} __anon_0x17433; // size = 0x20

// size = 0x20, address = 0x801474C0
static struct OSMessageQueue FreeReadBufferQueue;

// size = 0x20, address = 0x801474E0
static struct OSMessageQueue ReadedBufferQueue;

// size = 0x20, address = 0x80147500
static struct OSMessageQueue ReadedBufferQueue2;

// size = 0x28, address = 0x80147520
static void* FreeReadBufferMessage[10];

// size = 0x28, address = 0x80147548
static void* ReadedBufferMessage[10];

// size = 0x28, address = 0x80147570
static void* ReadedBufferMessage2[10];

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
} __anon_0x1774A; // size = 0x2C8

typedef struct OSThreadLink {
    /* 0x0 */ struct OSThread* next;
    /* 0x4 */ struct OSThread* prev;
} __anon_0x17963; // size = 0x8

typedef struct OSMutexLink {
    /* 0x0 */ struct OSMutex* next;
    /* 0x4 */ struct OSMutex* prev;
} __anon_0x179D4; // size = 0x8

typedef struct OSMutex {
    /* 0x00 */ struct OSThreadQueue queue;
    /* 0x08 */ struct OSThread* thread;
    /* 0x0C */ s32 count;
    /* 0x10 */ struct OSMutexLink link;
} __anon_0x17A44; // size = 0x18

typedef struct OSMutexQueue {
    /* 0x0 */ struct OSMutex* head;
    /* 0x4 */ struct OSMutex* tail;
} __anon_0x17AF5; // size = 0x8

typedef struct OSThread {
    /* 0x000 */ struct OSContext context;
    /* 0x2C8 */ u16 state;
    /* 0x2CA */ u16 attr;
    /* 0x2CC */ s32 suspend;
    /* 0x2D0 */ s32 priority;
    /* 0x2D4 */ s32 base;
    /* 0x2D8 */ void* val;
    /* 0x2DC */ struct OSThreadQueue* queue;
    /* 0x2E0 */ struct OSThreadLink link;
    /* 0x2E8 */ struct OSThreadQueue queueJoin;
    /* 0x2F0 */ struct OSMutex* mutex;
    /* 0x2F4 */ struct OSMutexQueue queueMutex;
    /* 0x2FC */ struct OSThreadLink linkActive;
    /* 0x304 */ u8* stackBase;
    /* 0x308 */ u32* stackEnd;
    /* 0x30C */ s32 error;
    /* 0x310 */ void* specific[2];
} __anon_0x17B86; // size = 0x318

// size = 0x318, address = 0x80147598
static struct OSThread ReadThread;

// size = 0x1000, address = 0x801478B0
static u8 ReadThreadStack[4096];

// size = 0x40, address = 0x801488B0
static f32 gOrthoMtx[4][4];

// size = 0x4, address = 0x80181984
s32 gMovieErrorToggle;

// size = 0x4, address = 0x80181988
static s32 toggle$229;

// size = 0x4, address = 0x8018198C
static s32 gbReset;

// size = 0x4, address = 0x80181990
static u32 gnTickReset;

typedef struct DVDDiskID {
    /* 0x0 */ char gameName[4];
    /* 0x4 */ char company[2];
    /* 0x6 */ u8 diskNumber;
    /* 0x7 */ u8 gameVersion;
    /* 0x8 */ u8 streaming;
    /* 0x9 */ u8 streamingBufSize;
    /* 0xA */ u8 padding[22];
} __anon_0x1821C; // size = 0x20

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
} __anon_0x1838C; // size = 0x30

typedef struct DVDFileInfo {
    /* 0x00 */ struct DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (* callback)(s32, struct DVDFileInfo*);
} __anon_0x185B2; // size = 0x3C

typedef struct __anon_0x1868A {
    /* 0x00 */ char magic[4];
    /* 0x04 */ u32 version;
    /* 0x08 */ u32 bufSize;
    /* 0x0C */ u32 audioMaxSamples;
    /* 0x10 */ f32 frameRate;
    /* 0x14 */ u32 numFrames;
    /* 0x18 */ u32 firstFrameSize;
    /* 0x1C */ u32 movieDataSize;
    /* 0x20 */ u32 compInfoDataOffsets;
    /* 0x24 */ u32 offsetDataOffsets;
    /* 0x28 */ u32 movieDataOffsets;
    /* 0x2C */ u32 finalFrameDataOffsets;
} __anon_0x1868A; // size = 0x30

typedef struct __anon_0x188B6 {
    /* 0x0 */ u32 numComponents;
    /* 0x4 */ u8 frameComp[16];
} __anon_0x188B6; // size = 0x14

typedef struct __anon_0x1891E {
    /* 0x0 */ u32 xSize;
    /* 0x4 */ u32 ySize;
    /* 0x8 */ u32 videoType;
} __anon_0x1891E; // size = 0xC

typedef struct __anon_0x1899E {
    /* 0x0 */ u32 sndChannels;
    /* 0x4 */ u32 sndFrequency;
    /* 0x8 */ u32 sndNumSamples;
    /* 0xC */ u32 sndNumTracks;
} __anon_0x1899E; // size = 0x10

typedef struct __anon_0x18A58 {
    /* 0x0 */ u8* ytexture;
    /* 0x4 */ u8* utexture;
    /* 0x8 */ u8* vtexture;
    /* 0xC */ s32 frameNumber;
} __anon_0x18A58; // size = 0x10

typedef struct __anon_0x18B0E {
    /* 0x0 */ s16* buffer;
    /* 0x4 */ s16* curPtr;
    /* 0x8 */ u32 validSample;
} __anon_0x18B0E; // size = 0xC

typedef struct __anon_0x18B98 {
    /* 0x0 */ u8* ptr;
    /* 0x4 */ s32 frameNumber;
    /* 0x8 */ s32 isValid;
} __anon_0x18B98; // size = 0xC

typedef struct __anon_0x18C83 {
    /* 0x000 */ struct DVDFileInfo fileInfo;
    /* 0x03C */ struct __anon_0x1868A header;
    /* 0x06C */ struct __anon_0x188B6 compInfo;
    /* 0x080 */ struct __anon_0x1891E videoInfo;
    /* 0x08C */ struct __anon_0x1899E audioInfo;
    /* 0x09C */ void* thpWork;
    /* 0x0A0 */ s32 open;
    /* 0x0A4 */ u8 state;
    /* 0x0A5 */ u8 internalState;
    /* 0x0A6 */ u8 playFlag;
    /* 0x0A7 */ u8 audioExist;
    /* 0x0A8 */ s32 dvdError;
    /* 0x0AC */ s32 videoError;
    /* 0x0B0 */ s32 onMemory;
    /* 0x0B4 */ u8* movieData;
    /* 0x0B8 */ s32 initOffset;
    /* 0x0BC */ s32 initReadSize;
    /* 0x0C0 */ s32 initReadFrame;
    /* 0x0C8 */ s64 retraceCount;
    /* 0x0D0 */ s32 prevCount;
    /* 0x0D4 */ s32 curCount;
    /* 0x0D8 */ s32 videoAhead;
    /* 0x0DC */ f32 curVolume;
    /* 0x0E0 */ f32 targetVolume;
    /* 0x0E4 */ f32 deltaVolume;
    /* 0x0E8 */ s32 rampCount;
    /* 0x0EC */ s32 curAudioTrack;
    /* 0x0F0 */ s32 curVideoNumber;
    /* 0x0F4 */ s32 curAudioNumber;
    /* 0x0F8 */ struct __anon_0x18A58* dispTextureSet;
    /* 0x0FC */ struct __anon_0x18B0E* playAudioBuffer;
    /* 0x100 */ struct __anon_0x18B98 readBuffer[10];
    /* 0x178 */ struct __anon_0x18A58 textureSet[3];
    /* 0x1A8 */ struct __anon_0x18B0E audioBuffer[3];
} __anon_0x18C83; // size = 0x1D0

// size = 0x1D0, address = 0x80145F80
struct __anon_0x18C83 ActivePlayer;

typedef struct PADStatus {
    /* 0x0 */ u16 button;
    /* 0x2 */ s8 stickX;
    /* 0x3 */ s8 stickY;
    /* 0x4 */ s8 substickX;
    /* 0x5 */ s8 substickY;
    /* 0x6 */ u8 triggerLeft;
    /* 0x7 */ u8 triggerRight;
    /* 0x8 */ u8 analogA;
    /* 0x9 */ u8 analogB;
    /* 0xA */ s8 err;
} __anon_0x1944C; // size = 0xC

typedef struct __anon_0x195DC {
    /* 0x00 */ struct PADStatus pst;
    /* 0x0C */ u16 buttonDown;
    /* 0x0E */ u16 buttonUp;
    /* 0x10 */ u16 dirs;
    /* 0x12 */ u16 dirsNew;
    /* 0x14 */ u16 dirsReleased;
    /* 0x16 */ s16 stickDeltaX;
    /* 0x18 */ s16 stickDeltaY;
    /* 0x1A */ s16 substickDeltaX;
    /* 0x1C */ s16 substickDeltaY;
} __anon_0x195DC; // size = 0x1E

// size = 0x78, address = 0x8017EA58
struct __anon_0x195DC DemoPad[4];

typedef enum __anon_0x1999E {
    M_M_NONE = -1,
    M_M_DISK_COVER_OPEN = 0,
    M_M_DISK_WRONG_DISK = 1,
    M_M_DISK_READING_DISK = 2,
    M_M_DISK_FATAL_ERROR = 3,
    M_M_DISK_RETRY_ERROR = 4,
    M_M_DISK_NO_DISK = 5,
    M_M_DISK_DEFAULT_ERROR = 6,
} __anon_0x1999E;

// size = 0x1, address = 0x80181914
u8 gLanguage;

// size = 0x0, address = 0x800FF3C0
u8 ggerman_coverOpen[];

// size = 0x0, address = 0x8010CFE0
u8 ggerman_wrongDisk[];

// size = 0x0, address = 0x8010F500
u8 ggerman_readingDisk[];

// size = 0x0, address = 0x80104220
u8 ggerman_retryErr[];

// size = 0x0, address = 0x80108900
u8 ggerman_fatalErr[];

// size = 0x0, address = 0x80102000
u8 ggerman_noDisk[];

// size = 0x0, address = 0x800ECCA0
u8 gfrench_coverOpen[];

// size = 0x0, address = 0x800FB880
u8 gfrench_wrongDisk[];

// size = 0x0, address = 0x800FDDA0
u8 gfrench_readingDisk[];

// size = 0x0, address = 0x800F2040
u8 gfrench_retryErr[];

// size = 0x0, address = 0x800F6A20
u8 gfrench_fatalErr[];

// size = 0x0, address = 0x800EFB20
u8 gfrench_noDisk[];

// size = 0x0, address = 0x80110820
u8 gspanish_coverOpen[];

// size = 0x0, address = 0x8011F400
u8 gspanish_wrongDisk[];

// size = 0x0, address = 0x80121920
u8 gspanish_readingDisk[];

// size = 0x0, address = 0x80115BC0
u8 gspanish_retryErr[];

// size = 0x0, address = 0x8011A5A0
u8 gspanish_fatalErr[];

// size = 0x0, address = 0x801136A0
u8 gspanish_noDisk[];

// size = 0x0, address = 0x80122DA0
u8 gitalian_coverOpen[];

// size = 0x0, address = 0x80131B00
u8 gitalian_wrongDisk[];

// size = 0x0, address = 0x80134020
u8 gitalian_readingDisk[];

// size = 0x0, address = 0x80128140
u8 gitalian_retryErr[];

// size = 0x0, address = 0x8012CB20
u8 gitalian_fatalErr[];

// size = 0x0, address = 0x80125C20
u8 gitalian_noDisk[];

// size = 0x0, address = 0x800DCAC0
u8 gcoverOpen[];

// size = 0x0, address = 0x800E9AE0
u8 gwrongDisk[];

// size = 0x0, address = 0x800EBD00
u8 greadingDisk[];

// size = 0x0, address = 0x800E1B60
u8 gretryErr[];

// size = 0x0, address = 0x800E4F80
u8 gfatalErr[];

// size = 0x0, address = 0x800DF940
u8 gnoDisk[];

// size = 0x0, address = 0x80135C00
s16 Vert_s16[];

// size = 0x0, address = 0x80135CA0
u32 Colors_u32[];

// size = 0x0, address = 0x80135CC0
u8 TexCoords_u8[];

typedef enum _GXTexWrapMode {
    GX_CLAMP = 0,
    GX_REPEAT = 1,
    GX_MIRROR = 2,
    GX_MAX_TEXWRAPMODE = 3,
} __anon_0x1A658;

typedef enum _GXTexFilter {
    GX_NEAR = 0,
    GX_LINEAR = 1,
    GX_NEAR_MIP_NEAR = 2,
    GX_LIN_MIP_NEAR = 3,
    GX_NEAR_MIP_LIN = 4,
    GX_LIN_MIP_LIN = 5,
} __anon_0x1A6C1;

typedef struct __anon_0x1A752 {
    /* 0x00 */ u16 height;
    /* 0x02 */ u16 width;
    /* 0x04 */ u32 format;
    /* 0x08 */ char* data;
    /* 0x0C */ enum _GXTexWrapMode wrapS;
    /* 0x10 */ enum _GXTexWrapMode wrapT;
    /* 0x14 */ enum _GXTexFilter minFilter;
    /* 0x18 */ enum _GXTexFilter magFilter;
    /* 0x1C */ f32 LODBias;
    /* 0x20 */ u8 edgeLODEnable;
    /* 0x21 */ u8 minLOD;
    /* 0x22 */ u8 maxLOD;
    /* 0x23 */ u8 unpacked;
} __anon_0x1A752; // size = 0x24

typedef enum _GXTlutFmt {
    GX_TL_IA8 = 0,
    GX_TL_RGB565 = 1,
    GX_TL_RGB5A3 = 2,
    GX_MAX_TLUTFMT = 3,
} __anon_0x1A945;

typedef struct __anon_0x1A9AD {
    /* 0x0 */ u16 numEntries;
    /* 0x2 */ u8 unpacked;
    /* 0x3 */ u8 pad8;
    /* 0x4 */ enum _GXTlutFmt format;
    /* 0x8 */ char* data;
} __anon_0x1A9AD; // size = 0xC

typedef struct __anon_0x1AA79 {
    /* 0x0 */ struct __anon_0x1A752* textureHeader;
    /* 0x4 */ struct __anon_0x1A9AD* CLUTHeader;
} __anon_0x1AA79; // size = 0x8

typedef struct __anon_0x1AAEA {
    /* 0x0 */ u32 versionNumber;
    /* 0x4 */ u32 numDescriptors;
    /* 0x8 */ struct __anon_0x1AA79* descriptorArray;
} __anon_0x1AAEA; // size = 0xC

typedef struct _GXTexObj {
    /* 0x0 */ u32 dummy[8];
} __anon_0x1ABA6; // size = 0x20

typedef struct _GXColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} __anon_0x1ABEC; // size = 0x4

// Range: 0x80012708 -> 0x80012DD8
s32 movieGXInit() {
    // Local variables
    s32 i; // r31
    struct _GXColor GX_DEFAULT_BG; // r1+0x58
    struct _GXColor BLACK; // r1+0x54
    struct _GXColor WHITE; // r1+0x50
    f32 identity_mtx[3][4]; // r1+0x20
}

// Range: 0x800121EC -> 0x80012708
s32 movieDrawImage(struct __anon_0x1AAEA* tpl, s16 nX0, s16 nY0) {
    // Parameters
    // struct __anon_0x1AAEA* tpl; // r25
    // s16 nX0; // r26
    // s16 nY0; // r27

    // Local variables
    struct _GXTexObj texObj; // r1+0xB0
    struct _GXColor color; // r1+0xA8
    f32 identity_mtx[3][4]; // r1+0x78
    f32 g2DviewMtx[3][4]; // r1+0x48
    f32 g2[3][4]; // r1+0x18

    // References
    // -> u8 TexCoords_u8[];
    // -> u32 Colors_u32[];
    // -> s16 Vert_s16[];
    // -> static f32 gOrthoMtx[4][4];
}

// Range: 0x80011964 -> 0x800121EC
s32 movieDrawErrorMessage(enum __anon_0x1999E movieMessage) {
    // Parameters
    // enum __anon_0x1999E movieMessage; // r1+0x8

    // References
    // -> u8 gfatalErr[];
    // -> u8 gnoDisk[];
    // -> u8 gretryErr[];
    // -> u8 greadingDisk[];
    // -> u8 gwrongDisk[];
    // -> u8 gcoverOpen[];
    // -> u8 gitalian_fatalErr[];
    // -> u8 gitalian_noDisk[];
    // -> u8 gitalian_retryErr[];
    // -> u8 gitalian_readingDisk[];
    // -> u8 gitalian_wrongDisk[];
    // -> u8 gitalian_coverOpen[];
    // -> u8 gspanish_fatalErr[];
    // -> u8 gspanish_noDisk[];
    // -> u8 gspanish_retryErr[];
    // -> u8 gspanish_readingDisk[];
    // -> u8 gspanish_wrongDisk[];
    // -> u8 gspanish_coverOpen[];
    // -> u8 gfrench_fatalErr[];
    // -> u8 gfrench_noDisk[];
    // -> u8 gfrench_retryErr[];
    // -> u8 gfrench_readingDisk[];
    // -> u8 gfrench_wrongDisk[];
    // -> u8 gfrench_coverOpen[];
    // -> u8 ggerman_fatalErr[];
    // -> u8 ggerman_noDisk[];
    // -> u8 ggerman_retryErr[];
    // -> u8 ggerman_readingDisk[];
    // -> u8 ggerman_wrongDisk[];
    // -> u8 ggerman_coverOpen[];
    // -> u8 gLanguage;
}

// Range: 0x80011704 -> 0x80011964
s32 movieDVDShowError(s32 nStatus) {
    // Parameters
    // s32 nStatus; // r1+0x8

    // Local variables
    enum __anon_0x1999E nMessage; // r31

    // References
    // -> static u32 gnTickReset;
    // -> static s32 gbReset;
    // -> struct __anon_0x195DC DemoPad[4];
    // -> static s32 toggle$229;
    // -> s32 gMovieErrorToggle;
}

// Range: 0x80011654 -> 0x80011704
s32 movieDVDRead(struct DVDFileInfo* pFileInfo, void* anData, s32 nSizeRead, s32 nOffset) {
    // Parameters
    // struct DVDFileInfo* pFileInfo; // r26
    // void* anData; // r27
    // s32 nSizeRead; // r28
    // s32 nOffset; // r29

    // Local variables
    s32 nStatus; // r31
    s32 bRetry; // r30

    // References
    // -> s32 gMovieErrorToggle;
}

// Range: 0x800114A0 -> 0x80011654
s32 movieTestReset(s32 IPL, s32 forceMenu) {
    // Parameters
    // s32 IPL; // r29
    // s32 forceMenu; // r30

    // Local variables
    u32 bFlag; // r1+0x8
    u32 nTick; // r1+0x8

    // References
    // -> static u32 gnTickReset;
    // -> static s32 gbReset;
    // -> struct __anon_0x195DC DemoPad[4];
}

// Range: 0x80011400 -> 0x800114A0
void movieReset(s32 IPL, s32 forceMenu) {
    // Parameters
    // s32 IPL; // r30
    // s32 forceMenu; // r31
}

// Range: 0x80011354 -> 0x80011400
s32 CreateReadThread(s32 priority) {
    // Parameters
    // s32 priority; // r3

    // References
    // -> static s32 ReadThreadCreated;
    // -> static void* ReadedBufferMessage2[10];
    // -> static struct OSMessageQueue ReadedBufferQueue2;
    // -> static void* ReadedBufferMessage[10];
    // -> static struct OSMessageQueue ReadedBufferQueue;
    // -> static void* FreeReadBufferMessage[10];
    // -> static struct OSMessageQueue FreeReadBufferQueue;
    // -> static u8 ReadThreadStack[4096];
    // -> static struct OSThread ReadThread;
}

// Range: 0x80011320 -> 0x80011354
void ReadThreadStart() {
    // References
    // -> static struct OSThread ReadThread;
    // -> static s32 ReadThreadCreated;
}

// Erased
static void ReadThreadCancel() {
    // References
    // -> static s32 ReadThreadCreated;
    // -> static struct OSThread ReadThread;
}

// Range: 0x800111F4 -> 0x80011320
static void* Reader() {
    // Local variables
    struct __anon_0x18B98* readBuffer; // r27
    s32 offset; // r26
    s32 size; // r25
    s32 readFrame; // r24

    // References
    // -> static struct OSThread ReadThread;
    // -> struct __anon_0x18C83 ActivePlayer;
    // -> static struct OSMessageQueue ReadedBufferQueue;
    // -> s32 gMovieErrorToggle;
    // -> static struct OSMessageQueue FreeReadBufferQueue;
}

// Range: 0x800111C0 -> 0x800111F4
void* PopReadedBuffer() {
    // Local variables
    void* msg; // r1+0x8

    // References
    // -> static struct OSMessageQueue ReadedBufferQueue;
}

// Erased
static void PushReadedBuffer(void* buffer) {
    // Parameters
    // void* buffer; // r4

    // References
    // -> static struct OSMessageQueue ReadedBufferQueue;
}

// Erased
static void* PopFreeReadBuffer() {
    // Local variables
    void* msg; // r1+0x8

    // References
    // -> static struct OSMessageQueue FreeReadBufferQueue;
}

// Range: 0x80011190 -> 0x800111C0
void PushFreeReadBuffer(void* buffer) {
    // Parameters
    // void* buffer; // r4

    // References
    // -> static struct OSMessageQueue FreeReadBufferQueue;
}

// Range: 0x8001115C -> 0x80011190
void* PopReadedBuffer2() {
    // Local variables
    void* msg; // r1+0x8

    // References
    // -> static struct OSMessageQueue ReadedBufferQueue2;
}

// Range: 0x8001112C -> 0x8001115C
void PushReadedBuffer2(void* buffer) {
    // Parameters
    // void* buffer; // r4

    // References
    // -> static struct OSMessageQueue ReadedBufferQueue2;
}
