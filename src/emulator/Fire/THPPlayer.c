#include "emulator/THPPlayer.h"
#include "dolphin.h"
#include "dolphin/ai.h"
#include "dolphin/thp.h"
#include "emulator/THPRead.h"
#include "macros.h"

// clang-format off
static u16 VolumeTable[128] = {
	0, 2, 8, 18, 32, 50, 73, 99, 130,
	164, 203, 245, 292, 343, 398, 457, 520,
	587, 658, 733, 812, 895, 983, 1074, 1170,
	1269, 1373, 1481, 1592, 1708, 1828, 1952, 2080,
	2212, 2348, 2488, 2632, 2781, 2933, 3090, 3250,
	3415, 3583, 3756, 3933, 4114, 4298, 4487, 4680,
	4877, 5079, 5284, 5493, 5706, 5924, 6145, 6371,
	6600, 6834, 7072, 7313, 7559, 7809, 8063, 8321,
	8583, 8849, 9119, 9394, 9672, 9954, 10241, 10531,
	10826, 11125, 11427, 11734, 12045, 12360, 12679, 13002,
	13329, 13660, 13995, 14335, 14678, 15025, 15377, 15732,
	16092, 16456, 16823, 17195, 17571, 17951, 18335, 18723,
	19115, 19511, 19911, 20316, 20724, 21136, 21553, 21974,
	22398, 22827, 23260, 23696, 24137, 24582, 25031, 25484,
	25941, 26402, 26868, 27337, 27810, 28288, 28769, 29255,
	29744, 30238, 30736, 31238, 31744, 32254, -32768
};
// clang-format on

static BOOL Initialized;
static s32 WorkBuffer[16];
static OSMessageQueue PrepareReadyQueue;
static OSMessageQueue UsedTextureSetQueue;
static void* PrepareReadyMessage;
static OSMessage UsedTextureSetMessage[3];
static VIRetraceCallback OldVIPostCallback;
static s16 SoundBuffer[2][320] ALIGNAS(32);
static s32 SoundBufferIndex;
static AIDCallback OldAIDCallback;
static s16* LastAudioBuffer;
static s16* CurAudioBuffer;
static s32 AudioSystem;

THPPlayer ActivePlayer;

// forward declare statics
static s16* audioCallbackWithMSound(s32 p1);
static void PlayControl(u32);
static BOOL ProperTimingForStart();
static BOOL ProperTimingForGettingNextFrame();
static void PushUsedTextureSet(OSMessage msg);
static OSMessage PopUsedTextureSet();
static void MixAudio(s16*, s16*, u32);
void THPGXYuv2RgbSetup(GXRenderModeObj* rmode);
void THPGXYuv2RgbDraw(u8* y_data, u8* u_data, u8* v_data, s16 x, s16 y, s16 textureWidth, s16 textureHeight,
                      s16 polygonWidth, s16 polygonHeight);
void THPGXRestore();

s32 movieDVDRead(DVDFileInfo* pFileInfo, void* anData, s32 nSizeRead, s32 nOffset);
static void THPAudioMixCallback();

BOOL THPPlayerInit(s32 audioSystem) {
    s32 old;

    memset(&ActivePlayer, 0, sizeof(THPPlayer));
    LCEnable();
    OSInitMessageQueue(&UsedTextureSetQueue, UsedTextureSetMessage, 3);

    if (!THPInit()) {
        return FALSE;
    }

    old = OSDisableInterrupts();

    AudioSystem = audioSystem;
    SoundBufferIndex = 0;
    LastAudioBuffer = NULL;
    CurAudioBuffer = NULL;
    OldAIDCallback = AIRegisterDMACallback(THPAudioMixCallback);
    if (OldAIDCallback == NULL && AudioSystem != 0) {
        AIRegisterDMACallback(NULL);
        OSRestoreInterrupts(old);
        OSReport("Pleae call AXInit or sndInit before you call THPPlayerInit\n");
        return 0;
    }

    OSRestoreInterrupts(old);

    if (AudioSystem == 0) {
        memset(SoundBuffer, 0, sizeof(SoundBuffer));
        DCFlushRange(SoundBuffer, sizeof(SoundBuffer));
        AIInitDMA((u32)&SoundBuffer[SoundBufferIndex], 320 * 2);
        AIStartDMA();
    }

    Initialized = TRUE;
    return TRUE;
}

#ifdef UNUSED
void THPPlayerQuit() {
    LCDisable();
    audioQuitWithMSound();
    Initialized = FALSE;
}
#endif

s32 THPPlayerOpen(char* fileName, s32 onMemory) {
    u32 readOffset;
    s32 i;

    if (Initialized == FALSE) {
        OSReport("You must call THPPlayerInit before you call this function\n");
        return FALSE;
    }

    if (ActivePlayer.open) {
        OSReport("Can't open %s because a thp file is already opened.\n");
        return FALSE;
    }

    memset(&ActivePlayer.videoInfo, 0, sizeof(THPVideoInfo));
    memset(&ActivePlayer.audioInfo, 0, sizeof(THPAudioInfo));

    if (DVDOpen((char*)fileName, &ActivePlayer.fileInfo) == FALSE) {
        OSReport("Can't open %s.\n", fileName);
        return FALSE;
    }

    // gTHPReaderDvdAccess = 1;
    // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 64, 0, 2) < 0) {
    // 	DVDClose(&ActivePlayer.fileInfo);
    // 	return FALSE;
    // }
    // gTHPReaderDvdAccess = 0;
    movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 64, 0);

    memcpy(&ActivePlayer.header.magic, WorkBuffer, sizeof(THPHeader));

    if (strcmp(ActivePlayer.header.magic, "THP") != 0) {
        OSReport("This file is not a THP file.\n");
        DVDClose(&ActivePlayer.fileInfo);
        return FALSE;
    }

    if (ActivePlayer.header.version != 0x11000) {
        OSReport("invalid version.\n");
        DVDClose(&ActivePlayer.fileInfo);
        return FALSE;
    }

    // gTHPReaderDvdAccess = 1;
    readOffset = ActivePlayer.header.compInfoDataOffsets;
    // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset, 2) < 0) {
    // 	DVDClose(&ActivePlayer.fileInfo);
    // 	return FALSE;
    // }
    // gTHPReaderDvdAccess = 0;
    movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset);

    memcpy(&ActivePlayer.compInfo, WorkBuffer, sizeof(THPFrameCompInfo));
    readOffset += sizeof(THPFrameCompInfo);
    ActivePlayer.audioExist = 0;

    for (i = 0; i < ActivePlayer.compInfo.numComponents; i++) {
        switch (ActivePlayer.compInfo.frameComp[i]) {
            case 0: {
                // gTHPReaderDvdAccess = 1;
                // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset, 2) < 0) {
                // 	DVDClose(&ActivePlayer.fileInfo);
                // 	return FALSE;
                // }
                // gTHPReaderDvdAccess = 0;
                movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset);

                memcpy(&ActivePlayer.videoInfo, WorkBuffer, sizeof(THPVideoInfo));
                readOffset += sizeof(THPVideoInfo);
                break;
            }
            case 1: {
                // gTHPReaderDvdAccess = 1;
                // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset, 2) < 0) {
                // 	DVDClose(&ActivePlayer.fileInfo);
                // 	return FALSE;
                // }
                // gTHPReaderDvdAccess = 0;
                movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset);

                memcpy(&ActivePlayer.audioInfo, WorkBuffer, sizeof(THPAudioInfo));
                readOffset += sizeof(THPAudioInfo);
                ActivePlayer.audioExist = 1;
                break;
            }

            default:
                OSReport("Unknown frame components.\n");
                return FALSE;
        }
    }

    ActivePlayer.internalState = 0;
    ActivePlayer.state = 0;
    ActivePlayer.playFlag = 0;
    ActivePlayer.onMemory = onMemory;
    ActivePlayer.open = TRUE;
    ActivePlayer.curVolume = 127.0f;
    ActivePlayer.targetVolume = ActivePlayer.curVolume;
    ActivePlayer.rampCount = 0;

    return TRUE;
}


#ifdef UNUSED
BOOL THPPlayerClose() {
    if (ActivePlayer.open && ActivePlayer.state == 0) {
        ActivePlayer.open = FALSE;
        DVDClose(&ActivePlayer.fileInfo);
        return TRUE;
    }

    return FALSE;
}
#endif

u32 THPPlayerCalcNeedMemory() {
    u32 size;

    if (ActivePlayer.open) {
        size = ActivePlayer.onMemory ? ALIGN_NEXT(ActivePlayer.header.movieDataSize, 32)
                                         : ALIGN_NEXT(ActivePlayer.header.bufSize, 32) * 10;

        size += ALIGN_NEXT(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize, 32) * 3;
        size += ALIGN_NEXT(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize / 4, 32) * 3;
        size += ALIGN_NEXT(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize / 4, 32) * 3;

        if (ActivePlayer.audioExist) {
            size += ALIGN_NEXT(ActivePlayer.header.audioMaxSamples * 4, 32) * 3;
        }

        return size + 0x1000;
    }

    return 0;
}

BOOL THPPlayerSetBuffer(u8* data) {
    u32 i;
    u8* workPtr;
    u32 ySampleSize;
    u32 uvSampleSize;

    if (ActivePlayer.open && ActivePlayer.state == 0) {
        workPtr = data;

        if (ActivePlayer.onMemory) {
            ActivePlayer.movieData = data;
            workPtr += ActivePlayer.header.movieDataSize;
        } else {
            for (i = 0; i < ARRAY_COUNT(ActivePlayer.readBuffer); i++) {
                ActivePlayer.readBuffer[i].ptr = workPtr;
                workPtr += ALIGN_NEXT(ActivePlayer.header.bufSize, 32);
            }
        }

        ySampleSize = ALIGN_NEXT(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize, 32);
        uvSampleSize = ALIGN_NEXT(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize / 4, 32);

        for (i = 0; i < ARRAY_COUNT(ActivePlayer.textureSet); i++) {
            ActivePlayer.textureSet[i].yTexture = workPtr;

            DCInvalidateRange(workPtr, ySampleSize);
            workPtr += ySampleSize;

            ActivePlayer.textureSet[i].uTexture = workPtr;
            DCInvalidateRange(workPtr, uvSampleSize);
            workPtr += uvSampleSize;

            ActivePlayer.textureSet[i].vTexture = workPtr;
            DCInvalidateRange(workPtr, uvSampleSize);
            workPtr += uvSampleSize;
        }

        if (ActivePlayer.audioExist) {
            for (i = 0; i < ARRAY_COUNT(ActivePlayer.audioBuffer); i++) {
                ActivePlayer.audioBuffer[i].buffer = (s16*)workPtr;
                ActivePlayer.audioBuffer[i].curPtr = (s16*)workPtr;
                ActivePlayer.audioBuffer[i].validSample = 0;
                workPtr += ALIGN_NEXT(ActivePlayer.header.audioMaxSamples * 4, 32);
            }
        }

        ActivePlayer.thpWork = workPtr;
        return TRUE;
    }

    return FALSE;
}

void InitAllMessageQueue() {
    s32 i;
    THPReadBuffer* readBuffer;
    THPTextureSet* textureSet;
    THPAudioBuffer* audioBuffer;

    if (ActivePlayer.onMemory == FALSE) {
        for (i = 0; i < 10; i++) {
            PushFreeReadBuffer((OSMessage*)&ActivePlayer.readBuffer[i]);
        }
    }

    for (i = 0; i < 3; i++) {
        PushFreeTextureSet((OSMessage*)&ActivePlayer.textureSet[i]);
    }

    if (ActivePlayer.audioExist) {
        for (i = 0; i < 3; i++) {
            PushFreeAudioBuffer((OSMessage*)&ActivePlayer.audioBuffer[i]);
        }
    }
    OSInitMessageQueue(&PrepareReadyQueue, &PrepareReadyMessage, 1);
}

inline BOOL WaitUntilPrepare() {
    OSMessage msg;

    OSReceiveMessage(&PrepareReadyQueue, &msg, OS_MESSAGE_BLOCK);

    if ((BOOL)msg) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void PrepareReady(s32 msg) { OSSendMessage(&PrepareReadyQueue, (OSMessage)msg, OS_MESSAGE_BLOCK); }

BOOL THPPlayerPrepare(s32 frame, s32 flag, s32 audioTrack) {
    u8* threadData;

    if (ActivePlayer.open && ActivePlayer.state == 0) {
        if (frame > 0) {
            if (ActivePlayer.header.offsetDataOffsets == 0) {
                OSReport("This thp file doesn't have the offset data\n");
                return FALSE;
            }

            if (ActivePlayer.header.numFrames > frame) {
                // gTHPReaderDvdAccess = 1;
                // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 0x20, ActivePlayer.header.offsetDataOffsets +
                // (frame - 1) * 4, 2) if (movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 0x20,
                // ActivePlayer.header.offsetDataOffsets + (frame - 1) * 4)
                //     < 0) {
                // 	return FALSE;
                // }
                // gTHPReaderDvdAccess = 0;
                movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 0x20,
                             ActivePlayer.header.offsetDataOffsets + (frame - 1) * 4);
                ActivePlayer.initOffset = ActivePlayer.header.movieDataOffsets + WorkBuffer[0];
                ActivePlayer.initReadFrame = frame;
                ActivePlayer.initReadSize = WorkBuffer[1] - WorkBuffer[0];

            } else {
                OSReport("Specified frame number is over total frame number\n");
                return FALSE;
            }

        } else {
            ActivePlayer.initOffset = ActivePlayer.header.movieDataOffsets;
            ActivePlayer.initReadSize = ActivePlayer.header.firstFrameSize;
            ActivePlayer.initReadFrame = frame;
        }

        if (ActivePlayer.audioExist) {
            if (audioTrack < 0 || audioTrack >= ActivePlayer.audioInfo.sndNumTracks) {
                OSReport("Specified audio track number is invalid\n");
                return FALSE;
            }
            ActivePlayer.curAudioTrack = audioTrack;
        }

        ActivePlayer.playFlag = flag & 1;
        ActivePlayer.videoAhead = 0;

        if (ActivePlayer.onMemory) {
            // gTHPReaderDvdAccess = 1;
            // if (DVDReadPrio(&ActivePlayer.fileInfo, ActivePlayer.movieData, ActivePlayer.header.movieDataSize,
            //                 ActivePlayer.header.movieDataOffsets, 2)
            //     < 0) {
            // 	return FALSE;
            // }
            // gTHPReaderDvdAccess = 0;
            movieDVDRead(&ActivePlayer.fileInfo, ActivePlayer.movieData, ActivePlayer.header.movieDataSize,
                         ActivePlayer.header.movieDataOffsets);

            threadData = ActivePlayer.movieData + ActivePlayer.initOffset - ActivePlayer.header.movieDataOffsets;
            CreateVideoDecodeThread(14, threadData);

            if (ActivePlayer.audioExist) {
                CreateAudioDecodeThread(12, threadData);
            }

        } else {
            CreateVideoDecodeThread(14, 0);
            // JUT_ASSERTLINE(789, CreateVideoDecodeThread(14, 0), "CreateVideoDecodeThread failure.\n");

            if (ActivePlayer.audioExist) {
                CreateAudioDecodeThread(12, NULL);
                // JUT_ASSERTLINE(801, CreateAudioDecodeThread(12, NULL), "CreateAudioDecodeThread failure.\n");
            }
            CreateReadThread(8);
            // JUT_ASSERTLINE(812, CreateReadThread(8), "CreateReadThread failure.\n");
        }

        // ActivePlayer.curVideoNumber = -1;
        // ActivePlayer.curAudioNumber = 0;

        InitAllMessageQueue();
        VideoDecodeThreadStart();

        if (ActivePlayer.audioExist) {
            AudioDecodeThreadStart();
        }

        if (ActivePlayer.onMemory == 0) {
            ReadThreadStart();
        }

        if (!WaitUntilPrepare()) {
            return FALSE;
        }

        ActivePlayer.state = 1;
        ActivePlayer.internalState = 0;
        ActivePlayer.dispTextureSet = NULL;
        ActivePlayer.playAudioBuffer = NULL;
        ActivePlayer.curVideoNumber = 0;
        ActivePlayer.curAudioNumber = 0;

        OldVIPostCallback = VISetPostRetraceCallback(PlayControl);

        // OSReport("THPPlayerPrepare()�I��\n"); // 'THPPlayerPrepare end'

        return TRUE;
    }

    return FALSE;
}

BOOL THPPlayerPlay() {
    if (ActivePlayer.open && (ActivePlayer.state == 1 || ActivePlayer.state == 4)) {
        ActivePlayer.state = 2;
        ActivePlayer.prevCount = 0;
        ActivePlayer.curCount = 0;
        ActivePlayer.retraceCount = -1;

        return TRUE;
    }
    return FALSE;
}

#ifdef UNUSED
void THPPlayerStop() {
    if (ActivePlayer.open && ActivePlayer.state != 0) {
        ActivePlayer.internalState = 0;
        ActivePlayer.state = 0;

        VISetPostRetraceCallback(OldVIPostCallback);

        if (ActivePlayer.onMemory == 0) {
            DVDCancel(&ActivePlayer.fileInfo.cBlock);
            ReadThreadCancel();
        }

        VideoDecodeThreadCancel();

        if (ActivePlayer.audioExist) {
            AudioDecodeThreadCancel();
            audioQuitWithMSound();

            OSReport("�I�[�f�B�I�֌W��������\n"); // 'initialize audio-related information'
        }

        while (PopUsedTextureSet() != 0) {
            ;
        }

        ActivePlayer.rampCount = 0;
        ActivePlayer.curVolume = ActivePlayer.targetVolume;
        ActivePlayer.dvdError = 0;
        ActivePlayer.videoError = 0;
    }
}

BOOL THPPlayerPause() {
    if (ActivePlayer.open && ActivePlayer.state == 2) {
        ActivePlayer.internalState = 4;
        ActivePlayer.state = 4;
        return TRUE;
    }
    return FALSE;
}
#endif

static void PlayControl(u32 retraceCnt) {
    THPTextureSet* decodedTexture;

    if (OldVIPostCallback != NULL) {
        OldVIPostCallback(retraceCnt);
    }

    decodedTexture = (THPTextureSet*)-1;
    if (ActivePlayer.open && ActivePlayer.state == 2) {
        if (ActivePlayer.dvdError || ActivePlayer.videoError) {
            ActivePlayer.state = 5;
            ActivePlayer.internalState = 5;
            return;
        }

        if (++ActivePlayer.retraceCount == 0) {
            if (ProperTimingForStart()) {
                if (ActivePlayer.audioExist) {
                    if (ActivePlayer.curVideoNumber - ActivePlayer.curAudioNumber <= 1) {
                        decodedTexture = (THPTextureSet*)PopDecodedTextureSet(0);

                        ActivePlayer.videoAhead--;
                        ActivePlayer.curVideoNumber++;

                    } else {
                        ActivePlayer.internalState = 2;
                    }
                } else {
                    decodedTexture = (THPTextureSet*)PopDecodedTextureSet(0);
                }

            } else {
                ActivePlayer.retraceCount = -1;
            }

        } else {
            if (ActivePlayer.retraceCount == 1) {
                ActivePlayer.internalState = 2;
            }

            if (ProperTimingForGettingNextFrame()) {
                if (ActivePlayer.audioExist) {
                    if (ActivePlayer.curVideoNumber - ActivePlayer.curAudioNumber <= 1) {
                        decodedTexture = (THPTextureSet*)PopDecodedTextureSet(0);
                        ActivePlayer.videoAhead--;
                        ActivePlayer.curVideoNumber++;
                    }

                } else {
                    decodedTexture = (THPTextureSet*)PopDecodedTextureSet(0);
                }
            }
        }

        if (decodedTexture && decodedTexture != (THPTextureSet*)-1) {
            if (ActivePlayer.dispTextureSet) {
                PushUsedTextureSet(ActivePlayer.dispTextureSet);
            }
            ActivePlayer.dispTextureSet = decodedTexture;
        }

        if ((ActivePlayer.playFlag & 1) == 0) {
            if (ActivePlayer.audioExist) {
                s32 audioFrame = ActivePlayer.curAudioNumber + ActivePlayer.initReadFrame;
                if (audioFrame == ActivePlayer.header.numFrames && ActivePlayer.playAudioBuffer == NULL) {
                    ActivePlayer.internalState = 3;
                    ActivePlayer.state = 3;
                }
            } else {
                s32 curFrame = ActivePlayer.dispTextureSet != NULL
                                   ? ActivePlayer.dispTextureSet->frameNumber + ActivePlayer.initReadFrame
                                   : ActivePlayer.initReadFrame - 1;
                if (curFrame == ActivePlayer.header.numFrames - 1 && decodedTexture == NULL) {
                    ActivePlayer.internalState = 3;
                    ActivePlayer.state = 3;
                }
            }
        }
    }
}

static BOOL ProperTimingForStart() {
    if (ActivePlayer.videoInfo.videoType & 1) {
        if (VIGetNextField() == 0) {
            return TRUE;
        }
    } else if (ActivePlayer.videoInfo.videoType & 2) {
        if (VIGetNextField() == 1) {
            return TRUE;
        }
    } else {
        return TRUE;
    }

    return FALSE;
}

static BOOL ProperTimingForGettingNextFrame() {
    s32 frameRate;

    if (ActivePlayer.videoInfo.videoType & 1) {
        if (VIGetNextField() == 0) {
            return TRUE;
        }
    } else if (ActivePlayer.videoInfo.videoType & 2) {
        if (VIGetNextField() == 1) {
            return TRUE;
        }
    } else {
        frameRate = ActivePlayer.header.frameRate * 100.0f;
        if (VIGetTvFormat() == VI_PAL) {
            ActivePlayer.curCount = ActivePlayer.retraceCount * frameRate / 5000;
        } else {
            ActivePlayer.curCount = ActivePlayer.retraceCount * frameRate / 5994;
        }

        if (ActivePlayer.prevCount != ActivePlayer.curCount) {
            ActivePlayer.prevCount = ActivePlayer.curCount;
            return TRUE;
        }
    }

    return FALSE;
}

s32 THPPlayerDrawCurrentFrame(GXRenderModeObj* obj, u32 x, u32 y, u32 polyWidth, u32 polyHeight) {
    if (ActivePlayer.open && ActivePlayer.state != 0 && ActivePlayer.dispTextureSet) {
        THPGXYuv2RgbSetup(obj);
        THPGXYuv2RgbDraw(ActivePlayer.dispTextureSet->yTexture, ActivePlayer.dispTextureSet->uTexture,
                         ActivePlayer.dispTextureSet->vTexture, x, y, ActivePlayer.videoInfo.xSize,
                         ActivePlayer.videoInfo.ySize, polyWidth, polyHeight);
        THPGXRestore();
        return (ActivePlayer.dispTextureSet->frameNumber + ActivePlayer.initReadFrame) % ActivePlayer.header.numFrames;
    }
    return -1;
}

#ifdef UNUSED
BOOL THPPlayerGetVideoInfo(void* dst) {
    if (ActivePlayer.open) {
        memcpy(dst, &ActivePlayer.videoInfo, sizeof(THPVideoInfo));
        return TRUE;
    }

    return FALSE;
}

BOOL THPPlayerGetAudioInfo(void* dst) {
    if (ActivePlayer.open) {
        memcpy(dst, &ActivePlayer.audioInfo, sizeof(THPAudioInfo));
        return TRUE;
    }

    return FALSE;
}

u32 THPPlayerGetTotalFrame() {
    if (ActivePlayer.open) {
        return ActivePlayer.header.numFrames;
    }

    return 0;
}

u8 THPPlayerGetState(void) { return ActivePlayer.state; }
#endif

static void PushUsedTextureSet(OSMessage msg) { OSSendMessage(&UsedTextureSetQueue, msg, OS_MESSAGE_NOBLOCK); }

static inline OSMessage PopUsedTextureSet() {
    OSMessage msg;
    if (OSReceiveMessage(&UsedTextureSetQueue, &msg, OS_MESSAGE_NOBLOCK) == 1)
        return msg;

    return NULL;
}

void THPPlayerDrawDone() {
    // GXDrawDone();
    if (Initialized) {
        while (TRUE) {
            OSMessage msg = PopUsedTextureSet();
            if (msg) {
                PushFreeTextureSet((OSMessage*)msg);
            } else {
                break;
            }
        }
    }
}

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

    if (AudioSystem == 0) {
        SoundBufferIndex ^= 1;
        AIInitDMA((u32)&SoundBuffer[SoundBufferIndex], 0x280);
        old = OSEnableInterrupts();
        MixAudio(SoundBuffer[SoundBufferIndex], NULL, 0xA0);
        DCFlushRange(SoundBuffer[SoundBufferIndex], 0x280);
        OSRestoreInterrupts(old);
        return;
    }

    if (AudioSystem == 1) {
        if (LastAudioBuffer != NULL) {
            CurAudioBuffer = LastAudioBuffer;
        }
        OldAIDCallback();
        LastAudioBuffer = (s16*)(AIGetDMAStartAddr() + 0x80000000);
    } else {
        OldAIDCallback();
        CurAudioBuffer = (s16*)(AIGetDMAStartAddr() + 0x80000000);
    }

    SoundBufferIndex ^= 1;
    AIInitDMA((u32)&SoundBuffer[SoundBufferIndex], 0x280);
    old = OSEnableInterrupts();

    if (CurAudioBuffer != NULL) {
        DCInvalidateRange(CurAudioBuffer, 0x280);
    }

    MixAudio(SoundBuffer[SoundBufferIndex], CurAudioBuffer, 0xA0U);
    DCFlushRange(SoundBuffer[SoundBufferIndex], 0x280);
    OSRestoreInterrupts(old);
}

static void MixAudio(s16* buf, s16* buf2, u32 n) {
    if (ActivePlayer.open && ActivePlayer.internalState == 2 && ActivePlayer.audioExist) {
        u32 lastSample;
        u32 n2;
        s32 i;
        s16* aBuf;
        s16* curPtr;
        s32 vol2;
        s32 vol1;
        u16 volFromTable;
        n2 = n;
        aBuf = buf;

        do {
            do {
                if (ActivePlayer.playAudioBuffer == NULL) {
                    ActivePlayer.playAudioBuffer = (THPAudioBuffer*)PopDecodedAudioBuffer(0);
                    if (ActivePlayer.playAudioBuffer == NULL) {
                        memset(aBuf, 0, n2 * 4);
                        return;
                    }
                    ActivePlayer.curAudioNumber++;
                }
            } while ((lastSample = ActivePlayer.playAudioBuffer->validSample) == 0);

            if (lastSample >= n2) {
                lastSample = n2;
            }

            curPtr = ActivePlayer.playAudioBuffer->curPtr;

            for (i = 0; i < lastSample; i++) {
                if (ActivePlayer.rampCount != 0) {
                    ActivePlayer.rampCount--;
                    ActivePlayer.curVolume += ActivePlayer.deltaVolume;
                } else {
                    ActivePlayer.curVolume = ActivePlayer.targetVolume;
                }

                volFromTable = VolumeTable[(s32)ActivePlayer.curVolume];
                // vol1         = 32768.0f * PSM::sTHPDinamicsProc.dinamics((volFromTable * curPtr[0] >> 15) /
                // 32768.0f); clamp volume
                if (vol1 < -32768) {
                    vol1 = -32768;
                }
                if (vol1 > 32767) {
                    vol1 = 32767;
                }
                *aBuf++ = vol1;

                // vol2 = 32768.0f * PSM::sTHPDinamicsProc.dinamics((volFromTable * curPtr[1] >> 15) / 32768.0f);
                if (vol2 < -32768) {
                    vol2 = -32768;
                }
                if (vol2 > 32767) {
                    vol2 = 32767;
                }
                *aBuf++ = vol2;

                curPtr += 2;
            }

            n2 -= lastSample;
            ActivePlayer.playAudioBuffer->validSample -= lastSample;
            ActivePlayer.playAudioBuffer->curPtr = curPtr;

            if ((ActivePlayer.playAudioBuffer)->validSample == 0) {
                PushFreeAudioBuffer(ActivePlayer.playAudioBuffer);
                ActivePlayer.playAudioBuffer = NULL;
            }

            if (n2 == 0) {
                break;
            }

        } while (TRUE);

    } else {
        memset(buf, 0, n * 4);
    }
}

#ifdef UNUSED
BOOL THPPlayerSetVolume(s32 vol, s32 duration) {
    u32 numSamples;
    BOOL interrupt;
    if (ActivePlayer.open && ActivePlayer.audioExist) {
        numSamples = AIGetDSPSampleRate() == 0 ? 32 : 48;

        // clamp volume
        if (vol > 127) {
            vol = 127;
        }
        if (vol < 0) {
            vol = 0;
        }

        // clamp duration
        if (duration > 60000) {
            duration = 60000;
        }
        if (duration < 0) {
            duration = 0;
        }

        interrupt = OSDisableInterrupts();

        ActivePlayer.targetVolume = vol;
        if (duration != 0) {
            ActivePlayer.rampCount = numSamples * duration;
            ActivePlayer.deltaVolume = (ActivePlayer.targetVolume - ActivePlayer.curVolume) / ActivePlayer.rampCount;
        } else {
            ActivePlayer.rampCount = 0;
            ActivePlayer.curVolume = ActivePlayer.targetVolume;
        }
        OSRestoreInterrupts(interrupt);

        return TRUE;
    }
    return FALSE;
}
#endif
