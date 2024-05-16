/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\_gspJPEG.c
    Producer: MW EABI PPC C-Compiler
    Language: C89
    Code range: 0x8007BE00 -> 0x80081C38
*/

#include "types.h"

// Range: 0x80081354 -> 0x80081C38
static s32 rspCreateJPEGArrays(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
}

// Erased
static s32 rspDestroyJPEGArrays() {}

// Erased
static void rspConvertBufferToRGBA(u8* buf, struct __anon_0x5BFBE* rgba) {
    // Parameters
    // u8* buf; // r1+0x4
    // struct __anon_0x5BFBE* rgba; // r1+0x8
}

// Range: 0x800811BC -> 0x80081354
static void rspConvertRGBAtoYUV(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 i; // r30
    s32 j; // r1+0x8
    s32 Y; // r20
    s32 U; // r20
    s32 V; // r12
}

// Range: 0x80080ACC -> 0x800811BC
static void rspYUVtoDCTBuf(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x0

    // Local variables
    s32 i; // r1+0x0
}

// Range: 0x800807FC -> 0x80080ACC
static void rspDCT(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 c; // r1+0xA4
    s32 i; // r1+0xA0
    s32 j; // r1+0x8
    s32 dd; // r6
    s16 t[8][8]; // r1+0x1C
}

// Range: 0x80080680 -> 0x800807FC
static void rspQuantize(struct __anon_0x5C0BC* pRSP, s32 scale) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s32 scale; // r1+0xC

    // Local variables
    s32 c; // r29
    s32 i; // r28
    s32 j; // r27
    s16 q; // r6
    s16 s; // r1+0x8
}

// Erased
static void rspZigzagData(struct __anon_0x5C0BC* pRSP, u8** databuf, s32 n, s32* preDc) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // u8** databuf; // r1+0xC
    // s32 n; // r1+0x10
    // s32* preDc; // r1+0x14

    // Local variables
    s16 Ac; // r30
    s32 i; // r6
    s32 z; // r7
}

// Erased
static void rspUndoZigzagData(struct __anon_0x5C0BC* pRSP, u8** databuf, s32 n, s32* preDc) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // u8** databuf; // r1+0xC
    // s32 n; // r1+0x10
    // s32* preDc; // r1+0x14

    // Local variables
    s16 Dc; // r12
    s16 Ac; // r12
    s32 i; // r7
    s32 z; // r31
}

// Range: 0x800804FC -> 0x80080680
void rspUndoQuantize(struct __anon_0x5C0BC* pRSP, s32 scale) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s32 scale; // r1+0xC

    // Local variables
    s32 c; // r29
    s32 i; // r28
    s32 j; // r27
    s16 q; // r6
    s16 s; // r1+0x8
}

// Range: 0x80080210 -> 0x800804FC
void rspUndoDCT(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 c; // r1+0xA4
    s32 i; // r1+0xA0
    s32 j; // r5
    s32 dd; // r6
    s16 t[8][8]; // r1+0x1C
}

// Range: 0x8007FA88 -> 0x80080210
void rspUndoYUVtoDCTBuf(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 i; // r1+0x8
    s32 j; // r1+0x8
}

// Range: 0x8007F8D8 -> 0x8007FA88
void rspFormatYUV(struct __anon_0x5C0BC* pRSP, char* imgBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // char* imgBuf; // r4

    // Local variables
    s32 i; // r10
    s32 j; // r11
}

// Range: 0x8007EEA0 -> 0x8007F8D8
static s32 rspParseJPEG_Encode(struct __anon_0x5C0BC* pRSP, struct __anon_0x5B21B* pTask) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r19
    // struct __anon_0x5B21B* pTask; // r16

    // Local variables
    u8* temp; // r24
    u8* temp2; // r23
    s32 i; // r10
    s32 j; // r11
    s32 x; // r22
    s32 y; // r21
    u8* system_imb; // r1+0x30
    u8* system_cfb; // r1+0x2C
    s32 scale; // r20
}

// Range: 0x8007E654 -> 0x8007EEA0
static s32 rspParseJPEG_Decode(struct __anon_0x5C0BC* pRSP, struct __anon_0x5B21B* pTask) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r30
    // struct __anon_0x5B21B* pTask; // r20

    // Local variables
    s32 i; // r3
    s32 y; // r25
    u8* temp; // r31
    u8* temp2; // r26
    u64* system_imb; // r1+0x1C
    s32 size; // r21
    s32 scale; // r22
}

// Range: 0x8007E35C -> 0x8007E654
static s32 rspCreateJPEGArraysZ(struct __anon_0x5C0BC* pRSP, s32 qYAddress, s32 qCbAddress, s32 qCrAddress) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r24
    // s32 qYAddress; // r4
    // s32 qCbAddress; // r25
    // s32 qCrAddress; // r26
}

// Erased
static s32 rspDestroyJPEGArraysZ() {}

// Range: 0x8007E08C -> 0x8007E35C
static void rspDCTZ(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 c; // r1+0xA4
    s32 i; // r1+0xA0
    s32 j; // r1+0x8
    s32 dd; // r6
    s16 t[8][8]; // r1+0x1C
}

// Range: 0x8007DA60 -> 0x8007E08C
static void rspQuantizeZ(struct __anon_0x5C0BC* pRSP, s16* dataBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s16* dataBuf; // r1+0xC

    // Local variables
    s32 c; // r12
    s32 i; // r1+0x8
}

// Range: 0x8007D538 -> 0x8007DA60
void rspZigzagDataZ(struct __anon_0x5C0BC* pRSP, s16* dataBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s16* dataBuf; // r4

    // Local variables
    s32 c; // r1+0x8
}

// Range: 0x8007CF6C -> 0x8007D538
void rspUndoQuantizeZ(struct __anon_0x5C0BC* pRSP, s16* dataBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s16* dataBuf; // r1+0xC

    // Local variables
    s32 c; // r12
    s32 i; // r1+0x8
}

// Range: 0x8007CB44 -> 0x8007CF6C
void rspUndoZigzagDataZ(struct __anon_0x5C0BC* pRSP, s16* dataBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s16* dataBuf; // r4

    // Local variables
    s32 c; // r1+0x8
}

// Range: 0x8007C874 -> 0x8007CB44
void rspUndoDCTZ(struct __anon_0x5C0BC* pRSP) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8

    // Local variables
    s32 c; // r1+0xA4
    s32 i; // r1+0xA0
    s32 j; // r5
    s32 dd; // r6
    s16 t[8][8]; // r1+0x1C
}

// Range: 0x8007C7E0 -> 0x8007C874
s32 rspUndoLoadColorBufferZ(s32 r, s32 g, s32 b, s16* imgBuf, s32 index) {
    // Parameters
    // s32 r; // r3
    // s32 g; // r1+0x8
    // s32 b; // r4
    // s16* imgBuf; // r1+0x10
    // s32 index; // r1+0x14
}

// Range: 0x8007C3D8 -> 0x8007C7E0
s32 rspUndoRecon420Z(struct __anon_0x5C0BC* pRSP, s16* imgBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r30
    // s16* imgBuf; // r29

    // Local variables
    s32 i; // r1+0x8
    s32 j; // r24
    s32 r; // r1+0x8
    s32 g; // r1+0x8
    s32 b; // r1+0x8
    s32 y; // r7
    s32 u; // r5
    s32 v; // r1+0x8
}

// Erased
static s32 rspLoadColorBufferZ(s32* r, s32* g, s32* b, s16* imgBuf, s32 index) {
    // Parameters
    // s32* r; // r1+0x4
    // s32* g; // r1+0x8
    // s32* b; // r1+0xC
    // s16* imgBuf; // r1+0x10
    // s32 index; // r1+0x14
}

// Range: 0x8007BFF8 -> 0x8007C3D8
s32 rspRecon420Z(struct __anon_0x5C0BC* pRSP, s16* imgBuf) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r1+0x8
    // s16* imgBuf; // r1+0xC

    // Local variables
    s32 i; // r1+0x10
    s32 j; // r26
    s32 r; // r10
    s32 g; // r7
    s32 b; // r11
    s32 y; // r6
    s32 u; // r9
    s32 v; // r1+0x8
}

// Range: 0x8007BEFC -> 0x8007BFF8
static s32 rspParseJPEG_EncodeZ(struct __anon_0x5C0BC* pRSP, struct __anon_0x5B21B* pTask) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r28
    // struct __anon_0x5B21B* pTask; // r4

    // Local variables
    s32 y; // r31
    s16* temp; // r1+0x8
    s16* temp2; // r30
    u64* system_imb; // r1+0x20
    u32* infoStruct; // r1+0x1C
    s32 size; // r29
}

// Range: 0x8007BE00 -> 0x8007BEFC
static s32 rspParseJPEG_DecodeZ(struct __anon_0x5C0BC* pRSP, struct __anon_0x5B21B* pTask) {
    // Parameters
    // struct __anon_0x5C0BC* pRSP; // r28
    // struct __anon_0x5B21B* pTask; // r4

    // Local variables
    s32 y; // r31
    s16* temp; // r1+0x8
    s16* temp2; // r30
    u64* system_imb; // r1+0x20
    u32* infoStruct; // r1+0x1C
    s32 size; // r29
}
