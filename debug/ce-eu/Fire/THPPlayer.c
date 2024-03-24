/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\THPPlayer.c
    Producer: MW EABI PPC C-Compiler
    Language: C89
    Code range: 0x8000F084 -> 0x80010590
*/

#include "types.h"

// size = 0x100, address = 0x80136478
static u16 VolumeTable[128];

// size = 0x4, address = 0x80181958
static s32 Initialized;

// size = 0x40, address = 0x801459E0
static s32 WorkBuffer[16];

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
} __anon_0x119D6; // size = 0x2C8

typedef struct OSThreadLink {
    /* 0x0 */ struct OSThread* next;
    /* 0x4 */ struct OSThread* prev;
} __anon_0x11BEF; // size = 0x8

typedef struct OSMutexLink {
    /* 0x0 */ struct OSMutex* next;
    /* 0x4 */ struct OSMutex* prev;
} __anon_0x11C60; // size = 0x8

typedef struct OSMutex {
    /* 0x00 */ struct OSThreadQueue queue;
    /* 0x08 */ struct OSThread* thread;
    /* 0x0C */ s32 count;
    /* 0x10 */ struct OSMutexLink link;
} __anon_0x11CD0; // size = 0x18

typedef struct OSMutexQueue {
    /* 0x0 */ struct OSMutex* head;
    /* 0x4 */ struct OSMutex* tail;
} __anon_0x11D81; // size = 0x8

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
} __anon_0x11E12; // size = 0x318

typedef struct OSThreadQueue {
    /* 0x0 */ struct OSThread* head;
    /* 0x4 */ struct OSThread* tail;
} __anon_0x120AB; // size = 0x8

typedef struct OSMessageQueue {
    /* 0x00 */ struct OSThreadQueue queueSend;
    /* 0x08 */ struct OSThreadQueue queueReceive;
    /* 0x10 */ void* msgArray;
    /* 0x14 */ s32 msgCount;
    /* 0x18 */ s32 firstIndex;
    /* 0x1C */ s32 usedCount;
} __anon_0x1211D; // size = 0x20

// size = 0x20, address = 0x80145A20
static struct OSMessageQueue PrepareReadyQueue;

// size = 0x20, address = 0x80145A40
static struct OSMessageQueue UsedTextureSetQueue;

// size = 0x4, address = 0x8018195C
static void* PrepareReadyMessage;

// size = 0xC, address = 0x80145A60
static void* UsedTextureSetMessage[3];

// size = 0x4, address = 0x80181960
static void (* OldVIPostCallback)(u32);

// size = 0x500, address = 0x80145A80
static s16 SoundBuffer[2][320];

// size = 0x4, address = 0x80181964
static s32 SoundBufferIndex;

// size = 0x4, address = 0x80181968
static void (* OldAIDCallback)();

// size = 0x4, address = 0x8018196C
static s16* LastAudioBuffer;

// size = 0x4, address = 0x80181970
static s16* CurAudioBuffer;

// size = 0x4, address = 0x80181974
static s32 AudioSystem;

typedef struct DVDDiskID {
    /* 0x0 */ char gameName[4];
    /* 0x4 */ char company[2];
    /* 0x6 */ u8 diskNumber;
    /* 0x7 */ u8 gameVersion;
    /* 0x8 */ u8 streaming;
    /* 0x9 */ u8 streamingBufSize;
    /* 0xA */ u8 padding[22];
} __anon_0x1251E; // size = 0x20

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
} __anon_0x1268E; // size = 0x30

typedef struct DVDFileInfo {
    /* 0x00 */ struct DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (* callback)(s32, struct DVDFileInfo*);
} __anon_0x128B4; // size = 0x3C

typedef struct __anon_0x1298C {
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
} __anon_0x1298C; // size = 0x30

typedef struct __anon_0x12BB8 {
    /* 0x0 */ u32 numComponents;
    /* 0x4 */ u8 frameComp[16];
} __anon_0x12BB8; // size = 0x14

typedef struct __anon_0x12C20 {
    /* 0x0 */ u32 xSize;
    /* 0x4 */ u32 ySize;
    /* 0x8 */ u32 videoType;
} __anon_0x12C20; // size = 0xC

typedef struct __anon_0x12CA0 {
    /* 0x0 */ u32 sndChannels;
    /* 0x4 */ u32 sndFrequency;
    /* 0x8 */ u32 sndNumSamples;
    /* 0xC */ u32 sndNumTracks;
} __anon_0x12CA0; // size = 0x10

typedef struct __anon_0x12D5A {
    /* 0x0 */ u8* ytexture;
    /* 0x4 */ u8* utexture;
    /* 0x8 */ u8* vtexture;
    /* 0xC */ s32 frameNumber;
} __anon_0x12D5A; // size = 0x10

typedef struct __anon_0x12E10 {
    /* 0x0 */ s16* buffer;
    /* 0x4 */ s16* curPtr;
    /* 0x8 */ u32 validSample;
} __anon_0x12E10; // size = 0xC

typedef struct __anon_0x12E9A {
    /* 0x0 */ u8* ptr;
    /* 0x4 */ s32 frameNumber;
    /* 0x8 */ s32 isValid;
} __anon_0x12E9A; // size = 0xC

typedef struct __anon_0x12F85 {
    /* 0x000 */ struct DVDFileInfo fileInfo;
    /* 0x03C */ struct __anon_0x1298C header;
    /* 0x06C */ struct __anon_0x12BB8 compInfo;
    /* 0x080 */ struct __anon_0x12C20 videoInfo;
    /* 0x08C */ struct __anon_0x12CA0 audioInfo;
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
    /* 0x0F8 */ struct __anon_0x12D5A* dispTextureSet;
    /* 0x0FC */ struct __anon_0x12E10* playAudioBuffer;
    /* 0x100 */ struct __anon_0x12E9A readBuffer[10];
    /* 0x178 */ struct __anon_0x12D5A textureSet[3];
    /* 0x1A8 */ struct __anon_0x12E10 audioBuffer[3];
} __anon_0x12F85; // size = 0x1D0

// size = 0x1D0, address = 0x80145F80
struct __anon_0x12F85 ActivePlayer;

typedef enum __anon_0x13DFF {
    VI_TVMODE_NTSC_INT = 0,
    VI_TVMODE_NTSC_DS = 1,
    VI_TVMODE_NTSC_PROG = 2,
    VI_TVMODE_PAL_INT = 4,
    VI_TVMODE_PAL_DS = 5,
    VI_TVMODE_EURGB60_INT = 20,
    VI_TVMODE_EURGB60_DS = 21,
    VI_TVMODE_MPAL_INT = 8,
    VI_TVMODE_MPAL_DS = 9,
    VI_TVMODE_DEBUG_INT = 12,
    VI_TVMODE_DEBUG_PAL_INT = 16,
    VI_TVMODE_DEBUG_PAL_DS = 17,
} __anon_0x13DFF;

typedef enum __anon_0x13F4B {
    VI_XFBMODE_SF = 0,
    VI_XFBMODE_DF = 1,
} __anon_0x13F4B;

typedef struct _GXRenderModeObj {
    /* 0x00 */ enum __anon_0x13DFF viTVmode;
    /* 0x04 */ u16 fbWidth;
    /* 0x06 */ u16 efbHeight;
    /* 0x08 */ u16 xfbHeight;
    /* 0x0A */ u16 viXOrigin;
    /* 0x0C */ u16 viYOrigin;
    /* 0x0E */ u16 viWidth;
    /* 0x10 */ u16 viHeight;
    /* 0x14 */ enum __anon_0x13F4B xFBmode;
    /* 0x18 */ u8 field_rendering;
    /* 0x19 */ u8 aa;
    /* 0x1A */ u8 sample_pattern[12][2];
    /* 0x32 */ u8 vfilter[7];
} __anon_0x13FFE; // size = 0x3C

// Erased
static s32 THPPlayerGetVolume() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static s32 THPPlayerSetVolume(s32 vol, s32 time) {
    // Parameters
    // s32 vol; // r28
    // s32 time; // r29

    // Local variables
    s32 old; // r3
    s32 samplePerMs; // r30

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x800101F4 -> 0x80010590
static void MixAudio(s16* destination, s16* source, u32 sample) {
    // Parameters
    // s16* destination; // r3
    // s16* source; // r4
    // u32 sample; // r5

    // Local variables
    u32 sampleNum; // r1+0x8
    u32 requestSample; // r26
    u32 i; // r1+0x8
    s32 mix; // r4
    s16* dst; // r27
    s16* libsrc; // r25
    s16* thpsrc; // r3
    u16 attenuation; // r1+0x8

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
    // -> static u16 VolumeTable[128];
}

// Range: 0x8001007C -> 0x800101F4
static void THPAudioMixCallback() {
    // Local variables
    s32 old; // r30

    // References
    // -> static s32 SoundBufferIndex;
    // -> static s16 SoundBuffer[2][320];
    // -> static s16* CurAudioBuffer;
    // -> static void (* OldAIDCallback)();
    // -> static s16* LastAudioBuffer;
    // -> static s32 AudioSystem;
}

// Range: 0x8001000C -> 0x8001007C
void THPPlayerDrawDone() {
    // Local variables
    void* textureSet; // r3

    // References
    // -> static struct OSMessageQueue UsedTextureSetQueue;
    // -> static s32 Initialized;
}

// Erased
static void* PopUsedTextureSet() {
    // Local variables
    void* msg; // r1+0x8

    // References
    // -> static struct OSMessageQueue UsedTextureSetQueue;
}

// Range: 0x8000FFDC -> 0x8001000C
static void PushUsedTextureSet(void* buffer) {
    // Parameters
    // void* buffer; // r4

    // References
    // -> static struct OSMessageQueue UsedTextureSetQueue;
}

// Erased
static s32 THPPlayerGetState() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static u32 THPPlayerGetTotalFrame() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static f32 THPPlayerGetFrameRate() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static s32 THPPlayerGetAudioInfo(struct __anon_0x12CA0* audioInfo) {
    // Parameters
    // struct __anon_0x12CA0* audioInfo; // r3

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static s32 THPPlayerGetVideoInfo(struct __anon_0x12C20* videoInfo) {
    // Parameters
    // struct __anon_0x12C20* videoInfo; // r3

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000FF10 -> 0x8000FFDC
s32 THPPlayerDrawCurrentFrame(struct _GXRenderModeObj* rmode, u32 x, u32 y, u32 polygonW, u32 polygonH) {
    // Parameters
    // struct _GXRenderModeObj* rmode; // r3
    // u32 x; // r26
    // u32 y; // r27
    // u32 polygonW; // r28
    // u32 polygonH; // r29

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000FDEC -> 0x8000FF10
static s32 ProperTimingForGettingNextFrame() {
    // Local variables
    s32 frameRate; // r30

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000FD80 -> 0x8000FDEC
static s32 ProperTimingForStart() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000FAE4 -> 0x8000FD80
static void PlayControl(u32 retraceCount) {
    // Parameters
    // u32 retraceCount; // r3

    // Local variables
    s32 diff; // r1+0x8
    s32 frameNumber; // r4
    struct __anon_0x12D5A* textureSet; // r29

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
    // -> static void (* OldVIPostCallback)(u32);
}

// Erased
static s32 THPPlayerSkip() {
    // Local variables
    s32 old; // r3
    s32 frameNumber; // r3
    s32 audioGet; // r29
    s32 videoGet; // r1+0x8

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static s32 THPPlayerPause() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static void THPPlayerStop() {
    // Local variables
    void* texture; // r1+0x8

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
    // -> static void (* OldVIPostCallback)(u32);
}

// Range: 0x8000FA88 -> 0x8000FAE4
s32 THPPlayerPlay() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000F814 -> 0x8000FA88
s32 THPPlayerPrepare(s32 frameNum, s32 playFlag, s32 audioTrack) {
    // Parameters
    // s32 frameNum; // r29
    // s32 playFlag; // r26
    // s32 audioTrack; // r27

    // Local variables
    s32 offset; // r6
    u8* ptr; // r26

    // References
    // -> static void (* OldVIPostCallback)(u32);
    // -> struct __anon_0x12F85 ActivePlayer;
    // -> static struct OSMessageQueue PrepareReadyQueue;
    // -> static s32 WorkBuffer[16];
}

// Range: 0x8000F7E4 -> 0x8000F814
void PrepareReady(s32 flag) {
    // Parameters
    // s32 flag; // r4

    // References
    // -> static struct OSMessageQueue PrepareReadyQueue;
}

// Erased
static s32 WaitUntilPrepare() {
    // Local variables
    void* msg; // r1+0x8

    // References
    // -> static struct OSMessageQueue PrepareReadyQueue;
}

// Range: 0x8000F718 -> 0x8000F7E4
static void InitAllMessageQueue() {
    // Local variables
    s32 i; // r28
    struct __anon_0x12E9A* readBuffer; // r3
    struct __anon_0x12D5A* textureSet; // r3
    struct __anon_0x12E10* audioBuffer; // r3

    // References
    // -> static void* PrepareReadyMessage;
    // -> static struct OSMessageQueue PrepareReadyQueue;
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000F4DC -> 0x8000F718
s32 THPPlayerSetBuffer(u8* buffer) {
    // Parameters
    // u8* buffer; // r1+0x8

    // Local variables
    u32 i; // r1+0x8
    u8* ptr; // r30
    u32 ysize; // r27
    u32 uvsize; // r26

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000F434 -> 0x8000F4DC
u32 THPPlayerCalcNeedMemory() {
    // Local variables
    u32 size; // r6

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Erased
static s32 THPPlayerClose() {
    // References
    // -> struct __anon_0x12F85 ActivePlayer;
}

// Range: 0x8000F1BC -> 0x8000F434
s32 THPPlayerOpen(char* fileName, s32 onMemory) {
    // Parameters
    // char* fileName; // r21
    // s32 onMemory; // r30

    // Local variables
    s32 offset; // r22
    s32 i; // r21

    // References
    // -> struct __anon_0x12F85 ActivePlayer;
    // -> static s32 WorkBuffer[16];
    // -> static s32 Initialized;
}

// Erased
static void THPPlayerQuit() {
    // Local variables
    s32 old; // r31

    // References
    // -> static s32 Initialized;
    // -> static void (* OldAIDCallback)();
}

// Range: 0x8000F084 -> 0x8000F1BC
s32 THPPlayerInit(s32 audioSystem) {
    // Parameters
    // s32 audioSystem; // r30

    // Local variables
    s32 old; // r30

    // References
    // -> static s32 Initialized;
    // -> static s32 SoundBufferIndex;
    // -> static s16 SoundBuffer[2][320];
    // -> static s32 AudioSystem;
    // -> static void (* OldAIDCallback)();
    // -> static s16* CurAudioBuffer;
    // -> static s16* LastAudioBuffer;
    // -> static void* UsedTextureSetMessage[3];
    // -> static struct OSMessageQueue UsedTextureSetQueue;
    // -> struct __anon_0x12F85 ActivePlayer;
}
