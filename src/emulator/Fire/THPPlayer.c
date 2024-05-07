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

static bool Initialized;
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
static bool ProperTimingForStart();
static bool ProperTimingForGettingNextFrame();
static void PushUsedTextureSet(OSMessage msg);
static OSMessage PopUsedTextureSet();
static void MixAudio(s16*, s16*, u32);
void THPGXYuv2RgbSetup(GXRenderModeObj* rmode);
void THPGXYuv2RgbDraw(u8* y_data, u8* u_data, u8* v_data, s16 x, s16 y, s16 textureWidth, s16 textureHeight,
                      s16 polygonWidth, s16 polygonHeight);
void THPGXRestore();

s32 movieDVDRead(DVDFileInfo* pFileInfo, void* anData, s32 nSizeRead, s32 nOffset);
static void THPAudioMixCallback();

bool THPPlayerInit(s32 audioSystem) {
    s32 old;

    memset(&ActivePlayer, 0, sizeof(THPPlayer));
    LCEnable();
    OSInitMessageQueue(&UsedTextureSetQueue, UsedTextureSetMessage, 3);

    if (!THPInit()) {
        return false;
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

    Initialized = true;
    return true;
}

#ifdef UNUSED
void THPPlayerQuit() {
    LCDisable();
    audioQuitWithMSound();
    Initialized = false;
}
#endif

s32 THPPlayerOpen(char* fileName, s32 onMemory) {
    u32 readOffset;
    s32 i;

    if (Initialized == false) {
        OSReport("You must call THPPlayerInit before you call this function\n");
        return false;
    }

    if (ActivePlayer.open) {
        OSReport("Can't open %s because a thp file is already opened.\n");
        return false;
    }

    memset(&ActivePlayer.videoInfo, 0, sizeof(THPVideoInfo));
    memset(&ActivePlayer.audioInfo, 0, sizeof(THPAudioInfo));

    if (DVDOpen((char*)fileName, &ActivePlayer.fileInfo) == false) {
        OSReport("Can't open %s.\n", fileName);
        return false;
    }

    // gTHPReaderDvdAccess = 1;
    // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 64, 0, 2) < 0) {
    // 	DVDClose(&ActivePlayer.fileInfo);
    // 	return false;
    // }
    // gTHPReaderDvdAccess = 0;
    movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 64, 0);

    memcpy(&ActivePlayer.header.magic, WorkBuffer, sizeof(THPHeader));

    if (strcmp(ActivePlayer.header.magic, "THP") != 0) {
        OSReport("This file is not a THP file.\n");
        DVDClose(&ActivePlayer.fileInfo);
        return false;
    }

    if (ActivePlayer.header.version != 0x11000) {
        OSReport("invalid version.\n");
        DVDClose(&ActivePlayer.fileInfo);
        return false;
    }

    // gTHPReaderDvdAccess = 1;
    readOffset = ActivePlayer.header.compInfoDataOffsets;
    // if (DVDReadPrio(&ActivePlayer.fileInfo, WorkBuffer, 32, readOffset, 2) < 0) {
    // 	DVDClose(&ActivePlayer.fileInfo);
    // 	return false;
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
                // 	return false;
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
                // 	return false;
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
                return false;
        }
    }

    ActivePlayer.internalState = 0;
    ActivePlayer.state = 0;
    ActivePlayer.playFlag = 0;
    ActivePlayer.onMemory = onMemory;
    ActivePlayer.open = true;
    ActivePlayer.curVolume = 127.0f;
    ActivePlayer.targetVolume = ActivePlayer.curVolume;
    ActivePlayer.rampCount = 0;

    return true;
}

#ifdef UNUSED
bool THPPlayerClose() {
    if (ActivePlayer.open && ActivePlayer.state == 0) {
        ActivePlayer.open = false;
        DVDClose(&ActivePlayer.fileInfo);
        return true;
    }

    return false;
}
#endif

u32 THPPlayerCalcNeedMemory() {
    u32 size;

    if (ActivePlayer.open) {
        if (ActivePlayer.onMemory) {
            size = OSRoundUp32B(ActivePlayer.header.movieDataSize);
        } else {
            size = OSRoundUp32B(ActivePlayer.header.bufSize) * 10;
        }

        size += OSRoundUp32B(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize) * 3;
        size += OSRoundUp32B(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize / 4) * 3;
        size += OSRoundUp32B(ActivePlayer.videoInfo.xSize * ActivePlayer.videoInfo.ySize / 4) * 3;

        if (ActivePlayer.audioExist) {
            size += OSRoundUp32B(ActivePlayer.header.audioMaxSamples * 4) * 3;
        }

        size += 0x1000;
        return size;
    }

    return 0;
}

bool THPPlayerSetBuffer(u8* data) {
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
        return true;
    }

    return false;
}

void InitAllMessageQueue() {
    s32 i;
    THPReadBuffer* readBuffer;
    THPTextureSet* textureSet;
    THPAudioBuffer* audioBuffer;

    if (ActivePlayer.onMemory == false) {
        for (i = 0; i < 10; i++) {
            readBuffer = &ActivePlayer.readBuffer[i];
            PushFreeReadBuffer(readBuffer);
        }
    }

    for (i = 0; i < 3; i++) {
        textureSet = &ActivePlayer.textureSet[i];
        PushFreeTextureSet(textureSet);
    }

    if (ActivePlayer.audioExist) {
        for (i = 0; i < 3; i++) {
            audioBuffer = &ActivePlayer.audioBuffer[i];
            PushFreeAudioBuffer(audioBuffer);
        }
    }
    OSInitMessageQueue(&PrepareReadyQueue, &PrepareReadyMessage, 1);
}

inline bool WaitUntilPrepare() {
    OSMessage msg;

    OSReceiveMessage(&PrepareReadyQueue, &msg, OS_MESSAGE_BLOCK);

    if ((bool)msg) {
        return true;
    } else {
        return false;
    }
}

void PrepareReady(s32 msg) { OSSendMessage(&PrepareReadyQueue, (OSMessage)msg, OS_MESSAGE_BLOCK); }

bool THPPlayerPrepare(s32 frame, s32 flag, s32 audioTrack) {
    s32 offset;
    u8* threadData;

    if (ActivePlayer.open && ActivePlayer.state == 0) {
        if (frame > 0) {
            if (ActivePlayer.header.offsetDataOffsets == 0) {
                OSReport("This thp file doesn't have the offset data\n");
                return false;
            }

            if (ActivePlayer.header.numFrames > frame) {
                offset = ActivePlayer.header.offsetDataOffsets + (frame - 1) * 4;
                movieDVDRead(&ActivePlayer.fileInfo, WorkBuffer, 0x20, offset);
                ActivePlayer.initOffset = (s32)(ActivePlayer.header.movieDataOffsets + WorkBuffer[0]);
                ActivePlayer.initReadFrame = frame;
                ActivePlayer.initReadSize = (s32)(WorkBuffer[1] - WorkBuffer[0]);

            } else {
                OSReport("Specified frame number is over total frame number\n");
                return false;
            }

        } else {
            ActivePlayer.initOffset = ActivePlayer.header.movieDataOffsets;
            ActivePlayer.initReadSize = ActivePlayer.header.firstFrameSize;
            ActivePlayer.initReadFrame = frame;
        }

        if (ActivePlayer.audioExist) {
            if (audioTrack < 0 || audioTrack >= ActivePlayer.audioInfo.sndNumTracks) {
                OSReport("Specified audio track number is invalid\n");
                return false;
            }
            ActivePlayer.curAudioTrack = audioTrack;
        }

        flag &= 1;
        ActivePlayer.playFlag = flag;
        ActivePlayer.videoAhead = 0;

        if (ActivePlayer.onMemory) {
            // gTHPReaderDvdAccess = 1;
            // if (DVDReadPrio(&ActivePlayer.fileInfo, ActivePlayer.movieData, ActivePlayer.header.movieDataSize,
            //                 ActivePlayer.header.movieDataOffsets, 2)
            //     < 0) {
            // 	return false;
            // }
            // gTHPReaderDvdAccess = 0;
            movieDVDRead(&ActivePlayer.fileInfo, ActivePlayer.movieData, ActivePlayer.header.movieDataSize,
                         ActivePlayer.header.movieDataOffsets);

            threadData = ActivePlayer.movieData + ActivePlayer.initOffset - ActivePlayer.header.movieDataOffsets;
            CreateVideoDecodeThread(20, threadData);

            if (ActivePlayer.audioExist) {
                CreateAudioDecodeThread(12, threadData);
            }

        } else {
            CreateVideoDecodeThread(20, 0);
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
            return false;
        }

        ActivePlayer.state = 1;
        ActivePlayer.internalState = 0;
        ActivePlayer.dispTextureSet = NULL;
        ActivePlayer.playAudioBuffer = NULL;
        ActivePlayer.curVideoNumber = 0;
        ActivePlayer.curAudioNumber = 0;

        OldVIPostCallback = VISetPostRetraceCallback(PlayControl);

        // OSReport("THPPlayerPrepare()�I��\n"); // 'THPPlayerPrepare end'

        return true;
    }

    return false;
}

bool THPPlayerPlay() {
    if (ActivePlayer.open && (ActivePlayer.state == 1 || ActivePlayer.state == 4)) {
        ActivePlayer.state = 2;
        ActivePlayer.prevCount = 0;
        ActivePlayer.curCount = 0;
        ActivePlayer.retraceCount = -1;

        return true;
    }
    return false;
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

bool THPPlayerPause() {
    if (ActivePlayer.open && ActivePlayer.state == 2) {
        ActivePlayer.internalState = 4;
        ActivePlayer.state = 4;
        return true;
    }
    return false;
}
#endif

static void PlayControl(u32 retraceCnt) {
    s32 audioFrame;
    s32 curFrame;
    THPTextureSet* decodedTexture;

    if (OldVIPostCallback != NULL) {
        OldVIPostCallback(retraceCnt);
    }

    decodedTexture = (THPTextureSet*)0xFFFFFFFF;
    if (ActivePlayer.open && ActivePlayer.state == 2) {
        if (ActivePlayer.dvdError || ActivePlayer.videoError) {
            ActivePlayer.state = ActivePlayer.internalState = 5;
            return;
        }

        ActivePlayer.retraceCount++;
        if (ActivePlayer.retraceCount == 0) {
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
                audioFrame = ActivePlayer.curAudioNumber + ActivePlayer.initReadFrame;
                if (audioFrame == ActivePlayer.header.numFrames && ActivePlayer.playAudioBuffer == NULL) {
                    ActivePlayer.internalState = 3;
                    ActivePlayer.state = 3;
                }
            } else {
                if (ActivePlayer.dispTextureSet != NULL) {
                    curFrame = ActivePlayer.dispTextureSet->frameNumber + ActivePlayer.initReadFrame;
                } else {
                    curFrame = ActivePlayer.initReadFrame - 1;
                }

                if (curFrame == ActivePlayer.header.numFrames - 1 && decodedTexture == NULL) {
                    ActivePlayer.internalState = 3;
                    ActivePlayer.state = 3;
                }
            }
        }
    }
}

static bool ProperTimingForStart() {
    if (ActivePlayer.videoInfo.videoType & 1) {
        if (VIGetNextField() == 0) {
            return true;
        }
    } else if (ActivePlayer.videoInfo.videoType & 2) {
        if (VIGetNextField() == 1) {
            return true;
        }
    } else {
        return true;
    }

    return false;
}

static bool ProperTimingForGettingNextFrame() {
    s32 frameRate;

    if (ActivePlayer.videoInfo.videoType & 1) {
        if (VIGetNextField() == 0) {
            return true;
        }
    } else if (ActivePlayer.videoInfo.videoType & 2) {
        if (VIGetNextField() == 1) {
            return true;
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
            return true;
        }
    }

    return false;
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
bool THPPlayerGetVideoInfo(void* dst) {
    if (ActivePlayer.open) {
        memcpy(dst, &ActivePlayer.videoInfo, sizeof(THPVideoInfo));
        return true;
    }

    return false;
}

bool THPPlayerGetAudioInfo(void* dst) {
    if (ActivePlayer.open) {
        memcpy(dst, &ActivePlayer.audioInfo, sizeof(THPAudioInfo));
        return true;
    }

    return false;
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
        while (true) {
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
    s32 old;

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

static void MixAudio(s16* destination, s16* source, u32 sample) {
    u32 sampleNum;
    u32 requestSample;
    u32 i;
    s32 mix;
    s16* dst;
    s16* libsrc;
    s16* thpsrc;
    u16 attenuation;

    if (source != NULL) {
        if (ActivePlayer.open && ActivePlayer.internalState == 2 && ActivePlayer.audioExist) {
            requestSample = sample;
            dst = destination;
            libsrc = source;

            while (true) {
                if (ActivePlayer.playAudioBuffer == NULL) {
                    if ((ActivePlayer.playAudioBuffer = (THPAudioBuffer*)PopDecodedAudioBuffer(0)) == NULL) {
                        memcpy(dst, libsrc, requestSample << 2);
                        break;
                    } else {
                        ActivePlayer.curAudioNumber++;
                    }
                }

                if (ActivePlayer.playAudioBuffer->validSample) {
                    if (ActivePlayer.playAudioBuffer->validSample >= requestSample) {
                        sampleNum = requestSample;
                    } else {
                        sampleNum = ActivePlayer.playAudioBuffer->validSample;
                    }

                    thpsrc = ActivePlayer.playAudioBuffer->curPtr;

                    for (i = 0; i < sampleNum; i++) {
                        if (ActivePlayer.rampCount) {
                            ActivePlayer.rampCount--;
                            ActivePlayer.curVolume += ActivePlayer.deltaVolume;
                        } else {
                            ActivePlayer.curVolume = ActivePlayer.targetVolume;
                        }

                        attenuation = VolumeTable[(s32)ActivePlayer.curVolume];
                        mix = *libsrc + ((attenuation * (*thpsrc)) >> 15);

                        if (mix < -32768) {
                            mix = -32768;
                        }
                        if (mix > 32767) {
                            mix = 32767;
                        }

                        *dst = (s16)mix;
                        dst++;
                        libsrc++;
                        thpsrc++;
                        mix = *libsrc + ((attenuation * (*thpsrc)) >> 15);

                        if (mix < -32768) {
                            mix = -32768;
                        }
                        if (mix > 32767) {
                            mix = 32767;
                        }

                        *dst = (s16)mix;
                        dst++;
                        libsrc++;
                        thpsrc++;
                    }

                    requestSample -= sampleNum;
                    ActivePlayer.playAudioBuffer->validSample -= sampleNum;
                    ActivePlayer.playAudioBuffer->curPtr = thpsrc;
                    if (ActivePlayer.playAudioBuffer->validSample == 0) {
                        PushFreeAudioBuffer(ActivePlayer.playAudioBuffer);
                        ActivePlayer.playAudioBuffer = NULL;
                    }
                    if (!requestSample) {
                        break;
                    }
                }
            }
        } else {
            memcpy(destination, source, sample << 2);
        }
    } else {
        if (ActivePlayer.open && ActivePlayer.internalState == 2 && ActivePlayer.audioExist) {
            requestSample = sample;
            dst = destination;

            while (true) {
                if (ActivePlayer.playAudioBuffer == NULL) {
                    if ((ActivePlayer.playAudioBuffer = (THPAudioBuffer*)PopDecodedAudioBuffer(0)) == NULL) {
                        memset(dst, 0, requestSample * 4);
                        break;
                    } else {
                        ActivePlayer.curAudioNumber++;
                    }
                }

                if (ActivePlayer.playAudioBuffer->validSample) {
                    if (ActivePlayer.playAudioBuffer->validSample >= requestSample) {
                        sampleNum = requestSample;
                    } else {
                        sampleNum = ActivePlayer.playAudioBuffer->validSample;
                    }

                    thpsrc = ActivePlayer.playAudioBuffer->curPtr;
                    for (i = 0; i < sampleNum; i++) {
                        if (ActivePlayer.rampCount != 0) {
                            ActivePlayer.rampCount--;
                            ActivePlayer.curVolume += ActivePlayer.deltaVolume;
                        } else {
                            ActivePlayer.curVolume = ActivePlayer.targetVolume;
                        }

                        attenuation = VolumeTable[(s32)ActivePlayer.curVolume];
                        mix = (attenuation * (*thpsrc)) >> 15;
                        if (mix < -32768) {
                            mix = -32768;
                        }
                        if (mix > 32767) {
                            mix = 32767;
                        }

                        *dst = mix;
                        dst++;
                        thpsrc++;
                        mix = (attenuation * (*thpsrc)) >> 15;

                        if (mix < -32768) {
                            mix = -32768;
                        }
                        if (mix > 32767) {
                            mix = 32767;
                        }
                        *dst = mix;
                        dst++;
                        thpsrc++;
                    }

                    requestSample -= sampleNum;
                    ActivePlayer.playAudioBuffer->validSample -= sampleNum;
                    ActivePlayer.playAudioBuffer->curPtr = thpsrc;

                    if ((ActivePlayer.playAudioBuffer)->validSample == 0) {
                        PushFreeAudioBuffer(ActivePlayer.playAudioBuffer);
                        ActivePlayer.playAudioBuffer = NULL;
                    }

                    if (!requestSample) {
                        break;
                    }
                }
            }
        } else {
            memset(destination, 0, sample << 2);
        }
    }
}

#ifdef UNUSED
bool THPPlayerSetVolume(s32 vol, s32 duration) {
    u32 numSamples;
    bool interrupt;
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

        return true;
    }
    return false;
}
#endif
