/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\ENGLISH ZELDA\Fire\simGCN.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x80007F80 -> 0x8000F7D8
*/

#include "types.h"

typedef struct __anon_0x57EC {
    /* 0x0 */ s32 nMode;
} __anon_0x57EC; // size = 0x4

// size = 0x4, address = 0x80137AD0
static struct __anon_0x57EC* gpCode;

// size = 0x2B01, address = 0x800DB880
u8 gcoverOpen[11009];

// size = 0x2201, address = 0x800DE3A0
u8 gnoDisk[8705];

// size = 0x3401, address = 0x800E05C0
u8 gretryErr[13313];

// size = 0x4B41, address = 0x800E39E0
u8 gfatalErr[19265];

// size = 0x2201, address = 0x800E8540
u8 gwrongDisk[8705];

// size = 0xB81, address = 0x800EA760
u8 greadingDisk[2945];

// size = 0x741, address = 0x800EB300
u8 gbar[1857];

// size = 0x141, address = 0x800EBA60
u8 gyes[321];

// size = 0x101, address = 0x800EBBC0
u8 gno[257];

// size = 0x161, address = 0x800EBCE0
u8 gmesgOK[353];

// size = 0x4, address = 0x801371E8
u32 gmsg_ld01Size;

// size = 0x4, address = 0x801371EC
u32 gmsg_ld02Size;

// size = 0x4, address = 0x801371F0
u32 gmsg_ld03Size;

// size = 0x4, address = 0x801371F4
u32 gmsg_ld04Size;

// size = 0x4, address = 0x801371F8
u32 gmsg_ld05_1Size;

// size = 0x4, address = 0x801371FC
u32 gmsg_ld05_2Size;

// size = 0x4, address = 0x80137200
u32 gmsg_ld06_1Size;

// size = 0x4, address = 0x80137204
u32 gmsg_ld06_2Size;

// size = 0x4, address = 0x80137208
u32 gmsg_ld06_3Size;

// size = 0x4, address = 0x8013720C
u32 gmsg_ld06_4Size;

// size = 0x4, address = 0x80137210
u32 gmsg_ld07Size;

// size = 0x4, address = 0x80137214
u32 gmsg_gf01Size;

// size = 0x4, address = 0x80137218
u32 gmsg_gf02Size;

// size = 0x4, address = 0x8013721C
u32 gmsg_gf03Size;

// size = 0x4, address = 0x80137220
u32 gmsg_gf04Size;

// size = 0x4, address = 0x80137224
u32 gmsg_gf05Size;

// size = 0x4, address = 0x80137228
u32 gmsg_gf06Size;

// size = 0x4, address = 0x8013722C
u32 gmsg_in01Size;

// size = 0x4, address = 0x80137230
u32 gmsg_in02Size;

// size = 0x4, address = 0x80137234
u32 gmsg_in03Size;

// size = 0x4, address = 0x80137238
u32 gmsg_in04Size;

// size = 0x4, address = 0x8013723C
u32 gmsg_in05Size;

// size = 0x4, address = 0x80137240
u32 gmsg_sv01Size;

// size = 0x4, address = 0x80137244
u32 gmsg_sv01_2Size;

// size = 0x4, address = 0x80137248
u32 gmsg_sv02Size;

// size = 0x4, address = 0x8013724C
u32 gmsg_sv03Size;

// size = 0x4, address = 0x80137250
u32 gmsg_sv04Size;

// size = 0x4, address = 0x80137254
u32 gmsg_sv05_1Size;

// size = 0x4, address = 0x80137258
u32 gmsg_sv06_1Size;

// size = 0x4, address = 0x8013725C
u32 gmsg_sv06_2Size;

// size = 0x4, address = 0x80137260
u32 gmsg_sv06_3Size;

// size = 0x4, address = 0x80137264
u32 gmsg_sv06_4Size;

// size = 0x4, address = 0x80137268
u32 gmsg_sv06_5Size;

// size = 0x4, address = 0x8013726C
u32 gmsg_sv07Size;

// size = 0x4, address = 0x80137270
u32 gmsg_sv08Size;

// size = 0x4, address = 0x80137274
u32 gmsg_sv09Size;

// size = 0x4, address = 0x80137278
u32 gmsg_sv10Size;

// size = 0x4, address = 0x8013727C
u32 gmsg_sv11Size;

// size = 0x4, address = 0x80137280
u32 gmsg_sv12Size;

// size = 0x4, address = 0x80137284
u32 gmsg_sv_shareSize;

// size = 0x4, address = 0x80137288
u32 gz_bnrSize;

// size = 0x4, address = 0x8013728C
u32 gz_iconSize;

// size = 0x4, address = 0x80137290
s32 gHighlightChoice;

typedef enum __anon_0x6222 {
    S_M_NONE = -1,
    S_M_DISK_COVER_OPEN = 0,
    S_M_DISK_WRONG_DISK = 1,
    S_M_DISK_READING_DISK = 2,
    S_M_DISK_FATAL_ERROR = 3,
    S_M_DISK_RETRY_ERROR = 4,
    S_M_DISK_NO_DISK = 5,
    S_M_DISK_DEFAULT_ERROR = 6,
    S_M_CARD_LD01 = 7,
    S_M_CARD_LD02 = 8,
    S_M_CARD_LD03 = 9,
    S_M_CARD_LD04 = 10,
    S_M_CARD_LD05_1 = 11,
    S_M_CARD_LD05_2 = 12,
    S_M_CARD_LD06_1 = 13,
    S_M_CARD_LD06_2 = 14,
    S_M_CARD_LD06_3 = 15,
    S_M_CARD_LD06_4 = 16,
    S_M_CARD_LD07 = 17,
    S_M_CARD_GF01 = 18,
    S_M_CARD_GF02 = 19,
    S_M_CARD_GF03 = 20,
    S_M_CARD_GF04 = 21,
    S_M_CARD_GF05 = 22,
    S_M_CARD_GF06 = 23,
    S_M_CARD_IN01 = 24,
    S_M_CARD_IN02 = 25,
    S_M_CARD_IN03 = 26,
    S_M_CARD_IN04 = 27,
    S_M_CARD_IN05 = 28,
    S_M_CARD_SV01 = 29,
    S_M_CARD_SV01_2 = 30,
    S_M_CARD_SV02 = 31,
    S_M_CARD_SV03 = 32,
    S_M_CARD_SV04 = 33,
    S_M_CARD_SV05_1 = 34,
    S_M_CARD_SV06_1 = 35,
    S_M_CARD_SV06_2 = 36,
    S_M_CARD_SV06_3 = 37,
    S_M_CARD_SV06_4 = 38,
    S_M_CARD_SV06_5 = 39,
    S_M_CARD_SV07 = 40,
    S_M_CARD_SV08 = 41,
    S_M_CARD_SV09 = 42,
    S_M_CARD_SV10 = 43,
    S_M_CARD_SV11 = 44,
    S_M_CARD_SV12 = 45,
    S_M_CARD_SV_SHARE = 46,
    S_M_CARD_DEFAULT_ERROR = 47,
} __anon_0x6222;

// size = 0x4, address = 0x80137294
enum __anon_0x6222 simulatorMessageCurrent;

// size = 0x40, address = 0x800F6A40
static f32 gOrthoMtx[4][4];

// size = 0x4, address = 0x80137AD4
s32 gButtonDownToggle;

// size = 0x18, address = 0x800EBE60
s16 Vert_s16[12];

// size = 0x18, address = 0x800EBE80
s16 VertTitle_s16[12];

// size = 0x18, address = 0x800EBEA0
s16 VertYes_s16[12];

// size = 0x18, address = 0x800EBEC0
s16 VertNo_s16[12];

// size = 0x18, address = 0x800EBEE0
s16 Vert_s16Bar[12];

// size = 0xC, address = 0x800EBF00
u32 Colors_u32[3];

// size = 0x8, address = 0x800EBF20
u8 TexCoords_u8[8];

// size = 0x4, address = 0x80137AD8
s32 gDVDResetToggle;

// size = 0x4, address = 0x80137ADC
static s32 toggle$192;

// size = 0x140, address = 0x800F6A80
static u32 gContMap[4][20];

// size = 0x4, address = 0x80137AE0
static u32 nPrevButton$701;

// size = 0x4, address = 0x80137AE4
static u32 nCurrButton$702;

// size = 0x4, address = 0x80137AE8
static s32 gbReset;

// size = 0x4, address = 0x80137AEC
static u32 gnTickReset;

// size = 0x4, address = 0x80137298
s32 gResetBeginFlag;

// size = 0x4, address = 0x80137AF0
s32 gPreviousIPLSetting;

// size = 0x4, address = 0x80137AF4
s32 gPreviousForceMenuSetting;

// size = 0x4, address = 0x80137AF8
s32 gPreviousAllowResetSetting;

// size = 0x20, address = 0x800F6BC0
static char* gaszArgument[8];

// size = 0x5000, address = 0x800F6BE0
char gpErrorMessageBuffer[20480];

// size = 0x4, address = 0x80137AFC
s32 gbDisplayedError;

typedef struct __anon_0x6BD1 {
    /* 0x0 */ s32 nSize;
    /* 0x4 */ s32 nOffsetRAM;
    /* 0x8 */ s32 nOffsetROM;
    /* 0xC */ s32 (* pCallback)();
} __anon_0x6BD1; // size = 0x10

typedef enum __anon_0x6C82 {
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
} __anon_0x6C82;

typedef enum __anon_0x6DB1 {
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
} __anon_0x6DB1;

typedef struct __anon_0x6EEF {
    /* 0x00 */ void* pFrame;
    /* 0x04 */ void* pSound;
    /* 0x08 */ s32 bException;
    /* 0x0C */ enum __anon_0xA732 eMode;
    /* 0x10 */ struct __anon_0x6BD1 romCopy;
    /* 0x20 */ enum __anon_0x6C82 eTypeROM;
    /* 0x24 */ void* apObject[16];
    /* 0x68 */ u64 nAddressBreak;
    /* 0x70 */ enum __anon_0x6DB1 storageDevice;
    /* 0x74 */ u8 anException[16];
    /* 0x84 */ s32 bJapaneseVersion;
} __anon_0x6EEF; // size = 0x88

// size = 0x4, address = 0x80137B00
struct __anon_0x6EEF* gpSystem;

typedef enum __anon_0x7160 {
    SPM_NONE = -1,
    SPM_PLAY = 0,
    SPM_RAMPQUEUED = 1,
    SPM_RAMPPLAYED = 2,
} __anon_0x7160;

typedef struct __anon_0x71CC {
    /* 0x00 */ void* pSrcData;
    /* 0x04 */ s32 nFrequency;
    /* 0x08 */ s32 nDacrate;
    /* 0x0C */ s32 nSndLen;
    /* 0x10 */ void* apBuffer[16];
    /* 0x50 */ s32 anSizeBuffer[16];
    /* 0x90 */ s32 nCountBeep;
    /* 0x94 */ s32 anSizeBeep[3];
    /* 0xA0 */ void* apDataBeep[3];
    /* 0xAC */ s32 iBufferPlay;
    /* 0xB0 */ s32 iBufferMake;
    /* 0xB4 */ enum __anon_0x7160 eMode;
    /* 0xB8 */ void* pBufferZero;
    /* 0xBC */ void* pBufferHold;
    /* 0xC0 */ void* pBufferRampUp;
    /* 0xC4 */ void* pBufferRampDown;
    /* 0xC8 */ s32 nSizePlay;
    /* 0xCC */ s32 nSizeZero;
    /* 0xD0 */ s32 nSizeHold;
    /* 0xD4 */ s32 nSizeRamp;
} __anon_0x71CC; // size = 0xD8

// size = 0x4, address = 0x80137B04
struct __anon_0x71CC* gpSound;

typedef struct __anon_0x755C {
    /* 0x0 */ f32 rX;
    /* 0x4 */ f32 rY;
    /* 0x8 */ f32 rSizeX;
    /* 0xC */ f32 rSizeY;
} __anon_0x755C; // size = 0x10

typedef struct __anon_0x75F6 {
    /* 0x00 */ s32 nSize;
    /* 0x04 */ s32 nWidth;
    /* 0x08 */ s32 nFormat;
    /* 0x0C */ void* pData;
    /* 0x10 */ s32 nAddress;
} __anon_0x75F6; // size = 0x14

typedef struct __anon_0x7737 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} __anon_0x7737; // size = 0xC

typedef struct __anon_0x77A7 {
    /* 0x00 */ s32 bTransformed;
    /* 0x04 */ struct __anon_0x7737 rVecOrigTowards;
    /* 0x10 */ f32 rColorR;
    /* 0x14 */ f32 rColorG;
    /* 0x18 */ f32 rColorB;
    /* 0x1C */ f32 rVectorX;
    /* 0x20 */ f32 rVectorY;
    /* 0x24 */ f32 rVectorZ;
    /* 0x28 */ f32 kc;
    /* 0x2C */ f32 kl;
    /* 0x30 */ f32 kq;
    /* 0x34 */ s16 coordX;
    /* 0x36 */ s16 coordY;
    /* 0x38 */ s16 coordZ;
} __anon_0x77A7; // size = 0x3C

typedef struct __anon_0x79D7 {
    /* 0x00 */ s32 bTransformed;
    /* 0x04 */ struct __anon_0x7737 rS;
    /* 0x10 */ struct __anon_0x7737 rT;
    /* 0x1C */ struct __anon_0x7737 rSRaw;
    /* 0x28 */ struct __anon_0x7737 rTRaw;
} __anon_0x79D7; // size = 0x34

typedef struct __anon_0x7AC0 {
    /* 0x00 */ f32 rSum;
    /* 0x04 */ f32 rS;
    /* 0x08 */ f32 rT;
    /* 0x0C */ struct __anon_0x7737 vec;
    /* 0x18 */ u8 anColor[4];
} __anon_0x7AC0; // size = 0x1C

typedef union __anon_0x7C1F {
    /* 0x0 */ u8 u8[4096];
    /* 0x0 */ u16 u16[2048];
    /* 0x0 */ u32 u32[1024];
    /* 0x0 */ u64 u64[512];
} __anon_0x7C1F;

typedef struct __anon_0x7CBC {
    /* 0x0 */ union __anon_0x7C1F data;
} __anon_0x7CBC; // size = 0x1000

typedef enum _GXTexFmt {
    GX_TF_I4 = 0,
    GX_TF_I8 = 1,
    GX_TF_IA4 = 2,
    GX_TF_IA8 = 3,
    GX_TF_RGB565 = 4,
    GX_TF_RGB5A3 = 5,
    GX_TF_RGBA8 = 6,
    GX_TF_CMPR = 14,
    GX_CTF_R4 = 32,
    GX_CTF_RA4 = 34,
    GX_CTF_RA8 = 35,
    GX_CTF_YUVA8 = 38,
    GX_CTF_A8 = 39,
    GX_CTF_R8 = 40,
    GX_CTF_G8 = 41,
    GX_CTF_B8 = 42,
    GX_CTF_RG8 = 43,
    GX_CTF_GB8 = 44,
    GX_TF_Z8 = 17,
    GX_TF_Z16 = 19,
    GX_TF_Z24X8 = 22,
    GX_CTF_Z4 = 48,
    GX_CTF_Z8M = 57,
    GX_CTF_Z8L = 58,
    GX_CTF_Z16L = 60,
    GX_TF_A8 = 39,
} __anon_0x7D55;

typedef struct _GXTlutObj {
    /* 0x0 */ u32 dummy[3];
} __anon_0x7F17; // size = 0xC

typedef enum _GXTexWrapMode {
    GX_CLAMP = 0,
    GX_REPEAT = 1,
    GX_MIRROR = 2,
    GX_MAX_TEXWRAPMODE = 3,
} __anon_0x7F5E;

typedef struct _FRAME_TEXTURE {
    /* 0x00 */ s32 nMode;
    /* 0x04 */ s32 iPackPixel;
    /* 0x08 */ s32 iPackColor;
    /* 0x0C */ s32 nFrameLast;
    /* 0x10 */ s16 nSizeX;
    /* 0x12 */ s16 nSizeY;
    /* 0x14 */ u32 nAddress;
    /* 0x18 */ u32 nCodePixel;
    /* 0x1C */ u32 nCodeColor;
    /* 0x20 */ struct _FRAME_TEXTURE* pTextureNext;
    /* 0x24 */ u32 nData0;
    /* 0x28 */ u32 nData1;
    /* 0x2C */ u32 nData2;
    /* 0x30 */ u32 nData3;
    /* 0x34 */ enum _GXTexFmt eFormat;
    /* 0x38 */ struct _GXTlutObj objectTLUT;
    /* 0x44 */ struct _GXTexObj objectTexture;
    /* 0x64 */ enum _GXTexWrapMode eWrapS;
    /* 0x68 */ enum _GXTexWrapMode eWrapT;
} __anon_0x7FC7; // size = 0x6C

typedef struct __anon_0x8324 {
    /* 0x00 */ s32 nSize;
    /* 0x04 */ s32 nTMEM;
    /* 0x08 */ s32 iTLUT;
    /* 0x0C */ s32 nSizeX;
    /* 0x10 */ s32 nFormat;
    /* 0x14 */ s16 nMaskS;
    /* 0x16 */ s16 nMaskT;
    /* 0x18 */ s16 nModeS;
    /* 0x1A */ s16 nModeT;
    /* 0x1C */ s16 nShiftS;
    /* 0x1E */ s16 nShiftT;
    /* 0x20 */ s16 nX0;
    /* 0x22 */ s16 nY0;
    /* 0x24 */ s16 nX1;
    /* 0x26 */ s16 nY1;
    /* 0x28 */ u32 nCodePixel;
} __anon_0x8324; // size = 0x2C

typedef enum __anon_0x8606 {
    FMP_NONE = -1,
    FMP_PERSPECTIVE = 0,
    FMP_ORTHOGRAPHIC = 1,
} __anon_0x8606;

typedef struct __anon_0x868A {
    /* 0x00 */ s32 nCount;
    /* 0x04 */ f32 rScale;
    /* 0x08 */ f32 rAspect;
    /* 0x0C */ f32 rFieldOfViewY;
    /* 0x10 */ f32 rClipNear;
    /* 0x14 */ f32 rClipFar;
    /* 0x18 */ u32 nAddressFloat;
    /* 0x1C */ u32 nAddressFixed;
    /* 0x20 */ enum __anon_0x8606 eProjection;
} __anon_0x868A; // size = 0x24

typedef struct __anon_0x8841 {
    /* 0x00000 */ u32 anCIMGAddresses[8];
    /* 0x00020 */ u16 nNumCIMGAddresses;
    /* 0x00024 */ s32 bBlurOn;
    /* 0x00028 */ s32 bHackPause;
    /* 0x0002C */ s32 nHackCount;
    /* 0x00030 */ s32 nFrameCounter;
    /* 0x00034 */ s32 bPauseThisFrame;
    /* 0x00038 */ s32 bCameFromBomberNotes;
    /* 0x0003C */ s32 bInBomberNotes;
    /* 0x00040 */ s32 bShrinking;
    /* 0x00044 */ s32 bSnapShot;
    /* 0x00048 */ s32 bUsingLens;
    /* 0x0004C */ u8 cBlurAlpha;
    /* 0x00050 */ s32 bBlurredThisFrame;
    /* 0x00054 */ s32 nFrameCIMGCalls;
    /* 0x00058 */ s32 bModifyZBuffer;
    /* 0x0005C */ s32 bOverrideDepth;
    /* 0x00060 */ s32 nZBufferSets;
    /* 0x00064 */ s32 nLastFrameZSets;
    /* 0x00068 */ s32 bPauseBGDrawn;
    /* 0x0006C */ s32 bFrameOn;
    /* 0x00070 */ s32 bBackBufferDrawn;
    /* 0x00074 */ s32 bGrabbedFrame;
    /* 0x00078 */ u64* pnGBI;
    /* 0x0007C */ u32 nFlag;
    /* 0x00080 */ f32 rScaleX;
    /* 0x00084 */ f32 rScaleY;
    /* 0x00088 */ u32 nCountFrames;
    /* 0x0008C */ u32 nMode;
    /* 0x00090 */ u32 aMode[10];
    /* 0x000B8 */ struct __anon_0x755C viewport;
    /* 0x000C8 */ struct __anon_0x75F6 aBuffer[4];
    /* 0x00118 */ u32 nOffsetDepth0;
    /* 0x0011C */ u32 nOffsetDepth1;
    /* 0x00120 */ s32 nWidthLine;
    /* 0x00124 */ f32 rDepth;
    /* 0x00128 */ f32 rDelta;
    /* 0x0012C */ s32 (* aDraw[4])(void*, void*);
    /* 0x0013C */ s32 nCountLight;
    /* 0x00140 */ struct __anon_0x77A7 aLight[8];
    /* 0x00320 */ struct __anon_0x79D7 lookAt;
    /* 0x00354 */ s32 nCountVertex;
    /* 0x00358 */ struct __anon_0x7AC0 aVertex[80];
    /* 0x00C18 */ struct __anon_0x7CBC TMEM;
    /* 0x01C18 */ void* aPixelData;
    /* 0x01C1C */ void* aColorData;
    /* 0x01C20 */ s32 nBlocksPixel;
    /* 0x01C24 */ s32 nBlocksMaxPixel;
    /* 0x01C28 */ s32 nBlocksColor;
    /* 0x01C2C */ s32 nBlocksMaxColor;
    /* 0x01C30 */ s32 nBlocksTexture;
    /* 0x01C34 */ s32 nBlocksMaxTexture;
    /* 0x01C38 */ u32 anPackPixel[48];
    /* 0x01CF8 */ u32 anPackColor[320];
    /* 0x021F8 */ u32 nAddressLoad;
    /* 0x021FC */ u32 nCodePixel;
    /* 0x02200 */ u32 nTlutCode[16];
    /* 0x02240 */ struct _FRAME_TEXTURE aTexture[2048];
    /* 0x38240 */ u32 anTextureUsed[64];
    /* 0x38340 */ struct _FRAME_TEXTURE* apTextureCached[4096];
    /* 0x3C340 */ s32 iTileLoad;
    /* 0x3C344 */ u32 n2dLoadTexType;
    /* 0x3C348 */ s32 nLastX0;
    /* 0x3C34C */ s32 nLastY0;
    /* 0x3C350 */ s32 nLastX1;
    /* 0x3C354 */ s32 nLastY1;
    /* 0x3C358 */ struct __anon_0x8324 aTile[8];
    /* 0x3C4B8 */ s32 anSizeX[2];
    /* 0x3C4C0 */ s32 anSizeY[2];
    /* 0x3C4C8 */ s32 iHintMatrix;
    /* 0x3C4CC */ s32 iMatrixModel;
    /* 0x3C4D0 */ s32 iHintProjection;
    /* 0x3C4D4 */ f32 matrixView[4][4];
    /* 0x3C514 */ s32 iHintLast;
    /* 0x3C518 */ s32 iHintHack;
    /* 0x3C51C */ enum __anon_0x8606 eTypeProjection;
    /* 0x3C520 */ f32 aMatrixModel[10][4][4];
    /* 0x3C7A0 */ f32 matrixProjection[4][4];
    /* 0x3C7E0 */ f32 matrixProjectionExtra[4][4];
    /* 0x3C820 */ struct __anon_0x868A aMatrixHint[64];
    /* 0x3D120 */ u8 primLODmin;
    /* 0x3D121 */ u8 primLODfrac;
    /* 0x3D122 */ u8 lastTile;
    /* 0x3D123 */ u8 iTileDrawn;
    /* 0x3D124 */ struct _GXColor aColor[5];
    /* 0x3D138 */ u32 nModeVtx;
    /* 0x3D13C */ u16* nTempBuffer;
    /* 0x3D140 */ u16* nCopyBuffer;
    /* 0x3D144 */ u32* nLensBuffer;
    /* 0x3D148 */ u16* nCameraBuffer;
} __anon_0x8841; // size = 0x3D150

// size = 0x4, address = 0x80137B08
struct __anon_0x8841* gpFrame;

// size = 0x1, address = 0x80137FA8
u8 DemoStatEnable;

// size = 0x4, address = 0x80137F8C
void* DemoCurrentBuffer;

// size = 0x4, address = 0x80137F94
void* DemoFrameBuffer1;

// size = 0x4, address = 0x80137F90
void* DemoFrameBuffer2;

typedef struct __anon_0x9782 {
    /* 0x00 */ s32 configuration;
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 offset;
    /* 0x0C */ char* buffer;
    /* 0x10 */ s32* writtenBlocks;
    /* 0x14 */ s32 writtenConfig;
} __anon_0x9782; // size = 0x18

typedef struct OSCalendarTime {
    /* 0x00 */ s32 sec;
    /* 0x04 */ s32 min;
    /* 0x08 */ s32 hour;
    /* 0x0C */ s32 mday;
    /* 0x10 */ s32 mon;
    /* 0x14 */ s32 year;
    /* 0x18 */ s32 wday;
    /* 0x1C */ s32 yday;
    /* 0x20 */ s32 msec;
    /* 0x24 */ s32 usec;
} __anon_0x9925; // size = 0x28

typedef struct CARDFileInfo {
    /* 0x00 */ s32 chan;
    /* 0x04 */ s32 fileNo;
    /* 0x08 */ s32 offset;
    /* 0x0C */ s32 length;
    /* 0x10 */ u16 iBlock;
    /* 0x12 */ u16 __padding;
} __anon_0x9A93; // size = 0x14

typedef struct __anon_0x9B8B {
    /* 0x000 */ s32 currentGame;
    /* 0x004 */ s32 fileSize;
    /* 0x008 */ char name[33];
    /* 0x02C */ s32 numberOfGames;
    /* 0x030 */ struct __anon_0x9782 game;
    /* 0x048 */ s32 changedDate;
    /* 0x04C */ s32 changedChecksum;
    /* 0x050 */ s32 gameSize[16];
    /* 0x090 */ s32 gameOffset[16];
    /* 0x0D0 */ s32 gameConfigIndex[16];
    /* 0x110 */ char gameName[16][33];
    /* 0x320 */ struct OSCalendarTime time;
    /* 0x348 */ struct CARDFileInfo fileInfo;
} __anon_0x9B8B; // size = 0x35C

typedef enum __anon_0x9DA1 {
    MC_E_NONE = 0,
    MC_E_BUSY = 1,
    MC_E_WRONGDEVICE = 2,
    MC_E_NOCARD = 3,
    MC_E_NOFILE = 4,
    MC_E_IOERROR = 5,
    MC_E_BROKEN = 6,
    MC_E_EXIST = 7,
    MC_E_NOENT = 8,
    MC_E_INSSPACE = 9,
    MC_E_NOPERM = 10,
    MC_E_LIMIT = 11,
    MC_E_NAMETOOLONG = 12,
    MC_E_ENCODING = 13,
    MC_E_CANCELED = 14,
    MC_E_FATAL = 15,
    MC_E_SECTOR_SIZE_INVALID = 16,
    MC_E_GAME_NOT_FOUND = 17,
    MC_E_CHECKSUM = 18,
    MC_E_NO_FREE_SPACE = 19,
    MC_E_NO_FREE_FILES = 20,
    MC_E_FILE_EXISTS = 21,
    MC_E_GAME_EXISTS = 22,
    MC_E_TIME_WRONG = 23,
    MC_E_WRITE_CORRUPTED = 24,
    MC_E_UNKNOWN = 25,
} __anon_0x9DA1;

typedef struct _MCARD {
    /* 0x000 */ struct __anon_0x9B8B file;
    /* 0x35C */ enum __anon_0x9DA1 error;
    /* 0x360 */ s32 slot;
    /* 0x364 */ s32 (* pPollFunction)();
    /* 0x368 */ s32 pollPrevBytes;
    /* 0x36C */ s32 pollSize;
    /* 0x370 */ char pollMessage[256];
    /* 0x470 */ s32 saveToggle;
    /* 0x474 */ char* writeBuffer;
    /* 0x478 */ char* readBuffer;
    /* 0x47C */ s32 writeToggle;
    /* 0x480 */ s32 soundToggle;
    /* 0x484 */ s32 writeStatus;
    /* 0x488 */ s32 writeIndex;
    /* 0x48C */ s32 accessType;
    /* 0x490 */ s32 gameIsLoaded;
    /* 0x494 */ char saveFileName[256];
    /* 0x594 */ char saveComment[256];
    /* 0x694 */ char* saveIcon;
    /* 0x698 */ char* saveBanner;
    /* 0x69C */ char saveGameName[256];
    /* 0x79C */ s32 saveFileSize;
    /* 0x7A0 */ s32 saveGameSize;
    /* 0x7A4 */ s32 bufferCreated;
    /* 0x7A8 */ s32 cardSize;
    /* 0x7AC */ s32 wait;
    /* 0x7B0 */ s32 isBroken;
    /* 0x7B4 */ s32 saveConfiguration;
} __anon_0xA043; // size = 0x7B8

// size = 0x7B8, address = 0x80109EB0
struct _MCARD mCard;

typedef struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ struct _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ s32 (* pfEvent)(void*, s32, void*);
} __anon_0xA52B; // size = 0x10

// size = 0x10, address = 0x800ECCC8
struct _XL_OBJECTTYPE gClassCode;

// size = 0x10, address = 0x800ECD48
struct _XL_OBJECTTYPE gClassFrame;

// size = 0x10, address = 0x800ECCD8
struct _XL_OBJECTTYPE gClassSound;

// size = 0x10, address = 0x800ED810
struct _XL_OBJECTTYPE gClassSystem;

typedef struct _GXColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} __anon_0xA699; // size = 0x4

typedef enum __anon_0xA732 {
    SM_NONE = -1,
    SM_RUNNING = 0,
    SM_STOPPED = 1,
} __anon_0xA732;

typedef enum __anon_0xA9CD {
    SAT_NONE = -1,
    SAT_NAME = 0,
    SAT_PROGRESSIVE = 1,
    SAT_VIBRATION = 2,
    SAT_CONTROLLER = 3,
    SAT_XTRA = 4,
    SAT_MEMORYCARD = 5,
    SAT_MOVIE = 6,
    SAT_RESET = 7,
    SAT_COUNT_ = 8,
} __anon_0xA9CD;

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
} __anon_0xABEA; // size = 0xC

typedef struct __anon_0xAD7A {
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
} __anon_0xAD7A; // size = 0x1E

// size = 0x78, address = 0x80134C58
struct __anon_0xAD7A DemoPad[4];

typedef enum __anon_0xC04E {
    CT_NONE = 0,
    CT_CONTROLLER = 1,
    CT_CONTROLLER_W_PAK = 2,
    CT_CONTROLLER_W_RPAK = 3,
    CT_MOUSE = 4,
    CT_VOICE = 5,
    CT_4K = 6,
    CT_16K = 7,
    CT_COUNT = 8,
} __anon_0xC04E;

typedef struct __anon_0xC69F {
    /* 0x000 */ char rom[36];
    /* 0x024 */ s32 controllerConfiguration[4][20];
    /* 0x164 */ s32 rumbleConfiguration;
    /* 0x168 */ s32 storageDevice;
    /* 0x16C */ s32 normalControllerConfig;
    /* 0x170 */ s32 currentControllerConfig;
} __anon_0xC69F; // size = 0x174

typedef enum __anon_0xCA44 {
    SV_NONE = 0,
    SV_CODE = 1,
    SV_FRAME = 2,
} __anon_0xCA44;

typedef enum __anon_0xCBCD {
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
} __anon_0xCBCD;

typedef enum __anon_0xCD17 {
    VI_XFBMODE_SF = 0,
    VI_XFBMODE_DF = 1,
} __anon_0xCD17;

typedef struct _GXRenderModeObj {
    /* 0x00 */ enum __anon_0xCBCD viTVmode;
    /* 0x04 */ u16 fbWidth;
    /* 0x06 */ u16 efbHeight;
    /* 0x08 */ u16 xfbHeight;
    /* 0x0A */ u16 viXOrigin;
    /* 0x0C */ u16 viYOrigin;
    /* 0x0E */ u16 viWidth;
    /* 0x10 */ u16 viHeight;
    /* 0x14 */ enum __anon_0xCD17 xFBmode;
    /* 0x18 */ u8 field_rendering;
    /* 0x19 */ u8 aa;
    /* 0x1A */ u8 sample_pattern[12][2];
    /* 0x32 */ u8 vfilter[7];
} __anon_0xCDC8; // size = 0x3C

// size = 0x4, address = 0x80137A9C
struct _GXRenderModeObj* rmode;

// size = 0x4, address = 0x80137B44
s32 gMovieErrorToggle;

typedef struct DVDDiskID {
    /* 0x0 */ char gameName[4];
    /* 0x4 */ char company[2];
    /* 0x6 */ u8 diskNumber;
    /* 0x7 */ u8 gameVersion;
    /* 0x8 */ u8 streaming;
    /* 0x9 */ u8 streamingBufSize;
    /* 0xA */ u8 padding[22];
} __anon_0xD1C0; // size = 0x20

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
} __anon_0xD330; // size = 0x30

typedef struct DVDFileInfo {
    /* 0x00 */ struct DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (* callback)(s32, struct DVDFileInfo*);
} __anon_0xD556; // size = 0x3C

typedef enum _GXTexFilter {
    GX_NEAR = 0,
    GX_LINEAR = 1,
    GX_NEAR_MIP_NEAR = 2,
    GX_LIN_MIP_NEAR = 3,
    GX_NEAR_MIP_LIN = 4,
    GX_LIN_MIP_LIN = 5,
} __anon_0xD78B;

typedef struct __anon_0xD81C {
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
} __anon_0xD81C; // size = 0x24

typedef enum _GXTlutFmt {
    GX_TL_IA8 = 0,
    GX_TL_RGB565 = 1,
    GX_TL_RGB5A3 = 2,
    GX_MAX_TLUTFMT = 3,
} __anon_0xDA0F;

typedef struct __anon_0xDA77 {
    /* 0x0 */ u16 numEntries;
    /* 0x2 */ u8 unpacked;
    /* 0x3 */ u8 pad8;
    /* 0x4 */ enum _GXTlutFmt format;
    /* 0x8 */ char* data;
} __anon_0xDA77; // size = 0xC

typedef struct __anon_0xDB43 {
    /* 0x0 */ struct __anon_0xD81C* textureHeader;
    /* 0x4 */ struct __anon_0xDA77* CLUTHeader;
} __anon_0xDB43; // size = 0x8

typedef struct __anon_0xDBB4 {
    /* 0x0 */ u32 versionNumber;
    /* 0x4 */ u32 numDescriptors;
    /* 0x8 */ struct __anon_0xDB43* descriptorArray;
} __anon_0xDBB4; // size = 0xC

typedef struct _GXTexObj {
    /* 0x0 */ u32 dummy[8];
} __anon_0xE0D9; // size = 0x20

// Range: 0x8000F108 -> 0x8000F7D8
s32 simulatorGXInit() {
    // Local variables
    s32 i; // r31
    struct _GXColor GX_DEFAULT_BG; // r1+0x58
    struct _GXColor BLACK; // r1+0x54
    struct _GXColor WHITE; // r1+0x50
    f32 identity_mtx[3][4]; // r1+0x20
}

// Range: 0x8000F02C -> 0x8000F108
void simulatorUnpackTexPalette(struct __anon_0xDBB4* pal) {
    // Parameters
    // struct __anon_0xDBB4* pal; // r1+0x0

    // Local variables
    u16 i; // r4
}

// Erased
static void simulatorDEMOSwapBuffers() {
    // References
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
}

// Erased
static void simulatorDEMODoneRender() {
    // References
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
}

// Erased
static s32 simulatorDrawBlack() {
    // Local variables
    struct _GXColor color; // r1+0x6C

    // References
    // -> struct __anon_0x8841* gpFrame;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
}

// Range: 0x8000EE24 -> 0x8000F02C
s32 simulatorDVDShowError(s32 nStatus) {
    // Parameters
    // s32 nStatus; // r26

    // Local variables
    s32 continueToggle; // r28
    enum __anon_0x6222 nMessage; // r27

    // References
    // -> struct __anon_0x6EEF* gpSystem;
    // -> s32 gDVDResetToggle;
    // -> static s32 toggle$192;
}

// Range: 0x8000EDB4 -> 0x8000EE24
s32 simulatorDVDOpen(char* szNameFile, struct DVDFileInfo* pFileInfo) {
    // Parameters
    // char* szNameFile; // r30
    // struct DVDFileInfo* pFileInfo; // r31

    // Local variables
    s32 nStatus; // r3
}

// Range: 0x8000ECD0 -> 0x8000EDB4
s32 simulatorDVDRead(struct DVDFileInfo* pFileInfo, void* anData, s32 nSizeRead, s32 nOffset, void (* callback)(s32, struct DVDFileInfo*)) {
    // Parameters
    // struct DVDFileInfo* pFileInfo; // r26
    // void* anData; // r27
    // s32 nSizeRead; // r28
    // s32 nOffset; // r29
    // void (* callback)(s32, struct DVDFileInfo*); // r7

    // Local variables
    s32 nStatus; // r31
    s32 bRetry; // r30
}

// Range: 0x8000ECAC -> 0x8000ECD0
s32 simulatorPlayMovie() {}

// Range: 0x8000E490 -> 0x8000ECAC
s32 simulatorDrawImage(struct __anon_0xDBB4* tpl, s32 nX0, s32 nY0, s32 drawBar, s32 percent) {
    // Parameters
    // struct __anon_0xDBB4* tpl; // r22
    // s32 nX0; // r30
    // s32 nY0; // r23
    // s32 drawBar; // r24
    // s32 percent; // r25

    // Local variables
    struct _GXTexObj texObj; // r1+0xDC
    struct _GXTexObj texObj2; // r1+0xBC
    struct _GXColor color; // r1+0xB4
    f32 identity_mtx[3][4]; // r1+0x84
    f32 g2DviewMtx[3][4]; // r1+0x54
    f32 g2[3][4]; // r1+0x24

    // References
    // -> struct __anon_0x8841* gpFrame;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
    // -> u8 gbar[1857];
    // -> u8 TexCoords_u8[8];
    // -> u32 Colors_u32[3];
    // -> s16 Vert_s16Bar[12];
    // -> s16 Vert_s16[12];
    // -> static f32 gOrthoMtx[4][4];
}

// Range: 0x8000DBC0 -> 0x8000E490
s32 simulatorDrawYesNoImage(struct __anon_0xDBB4* tplMessage, s32 nX0Message, s32 nY0Message, struct __anon_0xDBB4* tplYes, s32 nX0Yes, s32 nY0Yes, struct __anon_0xDBB4* tplNo, s32 nX0No, s32 nY0No) {
    // Parameters
    // struct __anon_0xDBB4* tplMessage; // r21
    // s32 nX0Message; // r22
    // s32 nY0Message; // r30
    // struct __anon_0xDBB4* tplYes; // r23
    // s32 nX0Yes; // r24
    // s32 nY0Yes; // r25
    // struct __anon_0xDBB4* tplNo; // r26
    // s32 nX0No; // r27
    // s32 nY0No; // r28

    // Local variables
    struct _GXTexObj texObj; // r1+0xAC
    struct _GXColor color0; // r1+0xA4
    struct _GXColor color1; // r1+0xA0
    f32 identity_mtx[3][4]; // r1+0x70
    f32 g2DviewMtx[3][4]; // r1+0x40

    // References
    // -> struct __anon_0x8841* gpFrame;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
    // -> s32 gHighlightChoice;
    // -> u8 TexCoords_u8[8];
    // -> u32 Colors_u32[3];
    // -> s16 VertNo_s16[12];
    // -> s16 VertYes_s16[12];
    // -> s16 Vert_s16[12];
    // -> static f32 gOrthoMtx[4][4];
}

// Range: 0x8000D598 -> 0x8000DBC0
s32 simulatorDrawOKImage(struct __anon_0xDBB4* tplMessage, s32 nX0Message, s32 nY0Message, struct __anon_0xDBB4* tplOK, s32 nX0OK, s32 nY0OK) {
    // Parameters
    // struct __anon_0xDBB4* tplMessage; // r29
    // s32 nX0Message; // r28
    // s32 nY0Message; // r27
    // struct __anon_0xDBB4* tplOK; // r23
    // s32 nX0OK; // r24
    // s32 nY0OK; // r25

    // Local variables
    struct _GXTexObj texObj; // r1+0x98
    struct _GXColor color0; // r1+0x94
    struct _GXColor color1; // r1+0x90
    f32 identity_mtx[3][4]; // r1+0x5C
    f32 g2DviewMtx[3][4]; // r1+0x2C

    // References
    // -> struct __anon_0x8841* gpFrame;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
    // -> u8 TexCoords_u8[8];
    // -> u32 Colors_u32[3];
    // -> s16 VertYes_s16[12];
    // -> s16 Vert_s16[12];
    // -> static f32 gOrthoMtx[4][4];
}

// Range: 0x8000D360 -> 0x8000D598
s32 simulatorDrawErrorMessage(enum __anon_0x6222 simulatorErrorMessage, s32 drawBar, s32 percent) {
    // Parameters
    // enum __anon_0x6222 simulatorErrorMessage; // r28
    // s32 drawBar; // r30
    // s32 percent; // r31

    // References
    // -> s32 gbDisplayedError;
    // -> u8 gfatalErr[19265];
    // -> u8 gnoDisk[8705];
    // -> u8 gretryErr[13313];
    // -> u8 greadingDisk[2945];
    // -> u8 gwrongDisk[8705];
    // -> u8 gcoverOpen[11009];
}

// Range: 0x8000D1F4 -> 0x8000D360
s32 simulatorPrepareMessage(enum __anon_0x6222 simulatorErrorMessage) {
    // Parameters
    // enum __anon_0x6222 simulatorErrorMessage; // r1+0x8

    // Local variables
    struct DVDFileInfo fileInfo; // r1+0xC

    // References
    // -> char gpErrorMessageBuffer[20480];
    // -> u32 gmsg_gf02Size;
    // -> enum __anon_0x6222 simulatorMessageCurrent;
    // -> u32 gmsg_sv09Size;
    // -> u32 gmsg_in02Size;
}

// Erased
static s32 simulatorDrawErrorMessageFromDVD(s32 drawBar, s32 percent) {
    // Parameters
    // s32 drawBar; // r29
    // s32 percent; // r30

    // References
    // -> char gpErrorMessageBuffer[20480];
}

// Range: 0x8000CF28 -> 0x8000D1F4
s32 simulatorDrawYesNoMessageLoop(struct __anon_0xDBB4* simulatorQuestion, s32* yes) {
    // Parameters
    // struct __anon_0xDBB4* simulatorQuestion; // r26
    // s32* yes; // r27

    // References
    // -> struct __anon_0x6EEF* gpSystem;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> s32 gButtonDownToggle;
    // -> u8 gno[257];
    // -> u8 gyes[321];
    // -> s32 gHighlightChoice;
}

// Range: 0x8000CB80 -> 0x8000CF28
s32 simulatorDrawYesNoMessage(enum __anon_0x6222 simulatorMessage, s32* yes) {
    // Parameters
    // enum __anon_0x6222 simulatorMessage; // r1+0x8
    // s32* yes; // r30

    // Local variables
    struct DVDFileInfo fileInfo; // r1+0x10

    // References
    // -> char gpErrorMessageBuffer[20480];
    // -> u32 gmsg_sv08Size;
    // -> enum __anon_0x6222 simulatorMessageCurrent;
    // -> u32 gmsg_sv06_5Size;
    // -> u32 gmsg_sv06_4Size;
    // -> u32 gmsg_in01Size;
    // -> u32 gmsg_gf01Size;
    // -> u32 gmsg_ld07Size;
    // -> u32 gmsg_ld06_4Size;
    // -> u32 gmsg_ld05_2Size;
}

// Erased
static s32 simulatorDrawOKMessageLoop(struct __anon_0xDBB4* simulatorMessage) {
    // Parameters
    // struct __anon_0xDBB4* simulatorMessage; // r27

    // References
    // -> s32 gButtonDownToggle;
    // -> struct __anon_0x6EEF* gpSystem;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> u8 gmesgOK[353];
    // -> u8 gyes[321];
}

// Range: 0x80009A34 -> 0x8000CB80
s32 simulatorDrawErrorMessageWait(enum __anon_0x6222 simulatorErrorMessage) {
    // Parameters
    // enum __anon_0x6222 simulatorErrorMessage; // r1+0x8

    // Local variables
    struct DVDFileInfo fileInfo; // r1+0x80

    // References
    // -> s32 gButtonDownToggle;
    // -> struct __anon_0x6EEF* gpSystem;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> u8 gmesgOK[353];
    // -> char gpErrorMessageBuffer[20480];
    // -> u8 gyes[321];
    // -> u32 gmsg_sv_shareSize;
    // -> enum __anon_0x6222 simulatorMessageCurrent;
    // -> u32 gmsg_sv12Size;
    // -> u32 gmsg_sv11Size;
    // -> u32 gmsg_sv10Size;
    // -> u32 gmsg_sv07Size;
    // -> u32 gmsg_sv06_3Size;
    // -> u32 gmsg_sv06_2Size;
    // -> u32 gmsg_sv06_1Size;
    // -> u32 gmsg_sv05_1Size;
    // -> u32 gmsg_sv04Size;
    // -> u32 gmsg_sv03Size;
    // -> u32 gmsg_sv02Size;
    // -> u32 gmsg_sv01_2Size;
    // -> u32 gmsg_sv01Size;
    // -> u32 gmsg_in05Size;
    // -> u32 gmsg_in04Size;
    // -> u32 gmsg_in03Size;
    // -> u32 gmsg_gf06Size;
    // -> u32 gmsg_gf05Size;
    // -> u32 gmsg_gf04Size;
    // -> u32 gmsg_gf03Size;
    // -> u32 gmsg_ld06_3Size;
    // -> u32 gmsg_ld06_2Size;
    // -> u32 gmsg_ld06_1Size;
    // -> u32 gmsg_ld05_1Size;
    // -> u32 gmsg_ld04Size;
    // -> u32 gmsg_ld03Size;
    // -> u32 gmsg_ld02Size;
    // -> u32 gmsg_ld01Size;
}

// Range: 0x80009984 -> 0x80009A34
void simulatorReset(s32 IPL, s32 forceMenu) {
    // Parameters
    // s32 IPL; // r30
    // s32 forceMenu; // r31

    // References
    // -> struct _MCARD mCard;
}

// Range: 0x80009828 -> 0x80009984
void simulatorResetAndPlayMovie() {
    // Local variables
    struct _GXColor color; // r1+0x14
    struct _GXRenderModeObj* simrmode; // r31

    // References
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
    // -> s32 gMovieErrorToggle;
    // -> struct _GXRenderModeObj* rmode;
    // -> struct _MCARD mCard;
}

// Erased
static s32 simulatorSetPart() {}

// Erased
static s32 simulatorAddXtraTime() {}

// Erased
static s32 simulatorShowParts() {}

// Erased
static enum __anon_0xCA44 simulatorGetView() {
    // References
    // -> static struct __anon_0x57EC* gpCode;
    // -> struct __anon_0x8841* gpFrame;
}

// Erased
static s32 simulatorSetView(enum __anon_0xCA44 eView) {
    // Parameters
    // enum __anon_0xCA44 eView; // r1+0x8

    // References
    // -> static struct __anon_0x57EC* gpCode;
    // -> struct __anon_0x8841* gpFrame;
}

// Range: 0x80009750 -> 0x80009828
s32 simulatorSetControllerMap(u32* mapData, s32 channel) {
    // Parameters
    // u32* mapData; // r1+0x0
    // s32 channel; // r1+0x4

    // Local variables
    s32 i; // r7

    // References
    // -> static u32 gContMap[4][20];
}

// Range: 0x80009688 -> 0x80009750
s32 simulatorCopyControllerMap(u32* mapDataOutput, u32* mapDataInput) {
    // Parameters
    // u32* mapDataOutput; // r1+0x0
    // u32* mapDataInput; // r1+0x4

    // Local variables
    s32 i; // r7
}

// Erased
static s32 simulatorChangeControllerConfig(s32 channel, s32 nCurrButton) {
    // Parameters
    // s32 channel; // r31
    // s32 nCurrButton; // r1+0xC

    // References
    // -> static u32 gContMap[4][20];
    // -> static struct __anon_0xC69F gSystemRomConfigurationList[1];
    // -> struct __anon_0x6EEF* gpSystem;
    // -> struct _MCARD mCard;
}

// Range: 0x80009114 -> 0x80009688
s32 simulatorReadController(s32 channel, u32* anData) {
    // Parameters
    // s32 channel; // r29
    // u32* anData; // r30

    // Local variables
    f32 subStickTest; // f1
    s32 stickX; // r1+0x8
    s32 stickY; // r1+0x8
    s32 subStickX; // r6
    s32 subStickY; // r7
    s32 nDirButton; // r3

    // References
    // -> static u32 gContMap[4][20];
    // -> static u32 nCurrButton$702;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> s32 gButtonDownToggle;
    // -> static u32 nPrevButton$701;
}

// Erased
static void DEMOInitWindow(s32 nSizeX, s32 nSizeY, s32 nColorR, s32 nColorG, s32 nColorB) {
    // Parameters
    // s32 nSizeX; // r3
    // s32 nSizeY; // r1+0xC
    // s32 nColorR; // r29
    // s32 nColorG; // r30
    // s32 nColorB; // r31

    // Local variables
    struct _GXColor color; // r1+0x20
}

// Range: 0x8000910C -> 0x80009114
s32 simulatorShowLoad() {}

// Erased
static s32 simulatorResetController() {}

// Range: 0x800090B8 -> 0x8000910C
s32 simulatorDetectController(s32 channel) {
    // Parameters
    // s32 channel; // r31

    // Local variables
    struct PADStatus status[4]; // r1+0xC
}

// Range: 0x8000903C -> 0x800090B8
s32 simulatorReadPak(s32 channel, u16 address, u8* data) {
    // Parameters
    // s32 channel; // r29
    // u16 address; // r30
    // u8* data; // r31

    // Local variables
    enum __anon_0xC04E type; // r1+0x14

    // References
    // -> struct __anon_0x6EEF* gpSystem;
}

// Range: 0x80008FC0 -> 0x8000903C
s32 simulatorWritePak(s32 channel, u16 address, u8* data) {
    // Parameters
    // s32 channel; // r29
    // u16 address; // r30
    // u8* data; // r31

    // Local variables
    enum __anon_0xC04E type; // r1+0x14

    // References
    // -> struct __anon_0x6EEF* gpSystem;
}

// Range: 0x80008F50 -> 0x80008FC0
s32 simulatorReadEEPROM(u8 address, u8* data) {
    // Parameters
    // u8 address; // r30
    // u8* data; // r31

    // Local variables
    s32 size; // r1+0x10

    // References
    // -> struct _MCARD mCard;
    // -> struct __anon_0x6EEF* gpSystem;
}

// Range: 0x80008EE0 -> 0x80008F50
s32 simulatorWriteEEPROM(u8 address, u8* data) {
    // Parameters
    // u8 address; // r30
    // u8* data; // r31

    // Local variables
    s32 size; // r1+0x10

    // References
    // -> struct _MCARD mCard;
    // -> struct __anon_0x6EEF* gpSystem;
}

// Range: 0x80008EAC -> 0x80008EE0
s32 simulatorReadSRAM(u32 address, u8* data, s32 size) {
    // Parameters
    // u32 address; // r4
    // u8* data; // r6
    // s32 size; // r5

    // References
    // -> struct _MCARD mCard;
}

// Range: 0x80008E78 -> 0x80008EAC
s32 simulatorWriteSRAM(u32 address, u8* data, s32 size) {
    // Parameters
    // u32 address; // r4
    // u8* data; // r6
    // s32 size; // r5

    // References
    // -> struct _MCARD mCard;
}

// Range: 0x80008E44 -> 0x80008E78
s32 simulatorReadFLASH(u32 address, u8* data, s32 size) {
    // Parameters
    // u32 address; // r4
    // u8* data; // r6
    // s32 size; // r5

    // References
    // -> struct _MCARD mCard;
}

// Range: 0x80008E10 -> 0x80008E44
s32 simulatorWriteFLASH(u32 address, u8* data, s32 size) {
    // Parameters
    // u32 address; // r4
    // u8* data; // r6
    // s32 size; // r5

    // References
    // -> struct _MCARD mCard;
}

// Range: 0x80008DE8 -> 0x80008E10
s32 simulatorRumbleStart(s32 channel) {
    // Parameters
    // s32 channel; // r3
}

// Range: 0x80008DC0 -> 0x80008DE8
s32 simulatorRumbleStop(s32 channel) {
    // Parameters
    // s32 channel; // r3
}

// Erased
static void* sScreenshotAlloc() {}

// Erased
static void sScreenshotFree() {}

// Range: 0x80008BE0 -> 0x80008DC0
s32 simulatorTestReset(s32 IPL, s32 forceMenu, s32 allowReset, s32 usePreviousSettings) {
    // Parameters
    // s32 IPL; // r24
    // s32 forceMenu; // r25
    // s32 allowReset; // r26
    // s32 usePreviousSettings; // r27

    // Local variables
    u32 bFlag; // r1+0x8
    u32 nTick; // r1+0x8
    s32 prevIPLSetting; // r28
    s32 prevForceMenuSetting; // r27
    s32 prevAllowResetSetting; // r1+0x8

    // References
    // -> static u32 gnTickReset;
    // -> static s32 gbReset;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> s32 gResetBeginFlag;
    // -> s32 gPreviousAllowResetSetting;
    // -> s32 gPreviousForceMenuSetting;
    // -> s32 gPreviousIPLSetting;
}

// Erased
static s32 simulatorDrawText(s32 nX, s32 nY, char* szText, s32 nColorR, s32 nColorG, s32 nColorB) {
    // Parameters
    // s32 nX; // r26
    // s32 nY; // r27
    // char* szText; // r28
    // s32 nColorR; // r29
    // s32 nColorG; // r30
    // s32 nColorB; // r31

    // Local variables
    struct _GXColor color; // r1+0x24
}

// Range: 0x80008B48 -> 0x80008BE0
s32 simulatorDrawMCardText() {
    // References
    // -> char gpErrorMessageBuffer[20480];
}

// Range: 0x80008A18 -> 0x80008B48
s32 simulatorMCardPollDrawBar() {
    // Local variables
    f32 rate; // r1+0x8
    s32 nBytes; // r1+0x8

    // References
    // -> char gpErrorMessageBuffer[20480];
    // -> struct _MCARD mCard;
}

// Range: 0x800088E8 -> 0x80008A18
s32 simulatorMCardPollDrawFormatBar() {
    // Local variables
    f32 rate; // r1+0x8
    s32 nBytes; // r1+0x8

    // References
    // -> char gpErrorMessageBuffer[20480];
    // -> struct _MCARD mCard;
}

// Range: 0x800086E0 -> 0x800088E8
static s32 simulatorDrawCursor(s32 nX, s32 nY) {
    // Parameters
    // s32 nX; // r30
    // s32 nY; // r31

    // Local variables
    struct _GXColor color; // r1+0x18
    s32 nTick; // r4
}

// Erased
static s32 simulatorDrawYesNoScreen(char* line1, char* line2, char* line3, s32* yes) {
    // Parameters
    // char* line1; // r21
    // char* line2; // r22
    // char* line3; // r23
    // s32* yes; // r24

    // Local variables
    s32 nCount; // r25

    // References
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> s32 gButtonDownToggle;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
}

// Erased
static s32 simulatorDrawOKScreen(char* line1, char* line2, char* line3) {
    // Parameters
    // char* line1; // r22
    // char* line2; // r23
    // char* line3; // r24

    // Local variables
    s32 nCount; // r25

    // References
    // -> s32 gButtonDownToggle;
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
}

// Erased
static s32 simulatorPickROM() {}

// Erased
static s32 simulatorMenu() {}

// Erased
static void MyGXInit() {
    // Local variables
    s32 i; // r31
    f32 identity_mtx[3][4]; // r1+0x50
}

// Erased
static s32 editSoundMenu() {
    // Local variables
    s32* menuValues[3]; // r1+0x94
    s32 menuMinMax[3][2]; // r1+0x7C
    char* menuNames[3]; // r1+0x70
    char* menuHelp[3]; // r1+0x64
    char str[32]; // r1+0x44
    s32 curItem; // r24
    s32 bDone; // r1+0xA0
    s32 i; // r6
    u32 heldButtons; // r7
    u32 buttons; // r8
    u32 downButtons; // r1+0x8
    u8 holdCount[16]; // r1+0x34
    struct _GXColor color[3]; // r1+0x28
    s32 step; // r20
    u32 bit; // r1+0x8
    struct _GXColor* colorP; // r31

    // References
    // -> struct __anon_0xAD7A DemoPad[4];
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> void* DemoFrameBuffer1;
    // -> u8 DemoStatEnable;
}

// Range: 0x8000857C -> 0x800086E0
static s32 simulatorParseArguments() {
    // Local variables
    s32 iArgument; // r23
    char* szText; // r1+0x14
    char* szValue; // r1+0x10

    // References
    // -> static char* gaszArgument[8];
}

// Range: 0x8000853C -> 0x8000857C
s32 simulatorGetArgument(enum __anon_0xA9CD eType, char** pszArgument) {
    // Parameters
    // enum __anon_0xA9CD eType; // r1+0x0
    // char** pszArgument; // r1+0x4

    // References
    // -> static char* gaszArgument[8];
}

// Range: 0x80007F80 -> 0x8000853C
s32 xlMain() {
    // Local variables
    struct _GXColor color; // r1+0x3C
    enum __anon_0xA732 eMode; // r1+0x38
    s32 nSize0; // r1+0x34
    s32 nSize1; // r1+0x30
    s32 iName; // r5
    char* szNameROM; // r1+0x2C
    char acNameROM[32]; // r1+0xC
    s32 rumbleYes; // r1+0x8

    // References
    // -> static struct __anon_0x57EC* gpCode;
    // -> struct __anon_0x8841* gpFrame;
    // -> struct __anon_0x71CC* gpSound;
    // -> struct __anon_0x6EEF* gpSystem;
    // -> struct _XL_OBJECTTYPE gClassSystem;
    // -> struct _XL_OBJECTTYPE gClassSound;
    // -> struct _XL_OBJECTTYPE gClassFrame;
    // -> struct _XL_OBJECTTYPE gClassCode;
    // -> static char* gaszArgument[8];
    // -> struct _MCARD mCard;
    // -> static u32 gnTickReset;
    // -> static s32 gbReset;
    // -> u8 gmesgOK[353];
    // -> u8 gno[257];
    // -> u8 gyes[321];
    // -> u8 gbar[1857];
    // -> u8 greadingDisk[2945];
    // -> u8 gwrongDisk[8705];
    // -> u8 gfatalErr[19265];
    // -> u8 gretryErr[13313];
    // -> u8 gnoDisk[8705];
    // -> u8 gcoverOpen[11009];
    // -> void* DemoFrameBuffer1;
    // -> void* DemoCurrentBuffer;
    // -> void* DemoFrameBuffer2;
    // -> u8 DemoStatEnable;
    // -> s32 gResetBeginFlag;
    // -> s32 gButtonDownToggle;
    // -> s32 gbDisplayedError;
    // -> s32 gDVDResetToggle;
}
