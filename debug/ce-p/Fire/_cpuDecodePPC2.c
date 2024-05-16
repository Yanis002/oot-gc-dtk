/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Fire\_cpuDecodePPC2.c
    Producer: MW EABI PPC C-Compiler
    Language: C89
    Code range: 0x800686B0 -> 0x8006C1B0
*/

#include "types.h"

// Range: 0x8006BFC8 -> 0x8006C1B0
static s32 cpuCompile_DSLLV(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r11
    s32 nSize; // r1+0x8
}

// Range: 0x8006BDE0 -> 0x8006BFC8
static s32 cpuCompile_DSRLV(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r11
    s32 nSize; // r1+0x8
}

// Range: 0x8006BBDC -> 0x8006BDE0
static s32 cpuCompile_DSRAV(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r1+0x8
    s32 nSize; // r1+0x8
}

// Range: 0x8006B6D8 -> 0x8006BBDC
static s32 cpuCompile_DMULT(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r31
    // s32* addressGCN; // r27

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x8006B3C4 -> 0x8006B6D8
static s32 cpuCompile_DMULTU(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r31
    // s32* addressGCN; // r30

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x8006AE08 -> 0x8006B3C4
static s32 cpuCompile_DDIV(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r16

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r23
    s32 nSize; // r1+0x8
}

// Range: 0x8006A9EC -> 0x8006AE08
static s32 cpuCompile_DDIVU(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r31
    // s32* addressGCN; // r24

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r9
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_DADD(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_DADDU(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_DSUB(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_DSUBU(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x8006A6AC -> 0x8006A9EC
static s32 cpuCompile_S_SQRT(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r19
    // s32* addressGCN; // r18

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r29
    s32 nSize; // r1+0x8
}

// Range: 0x8006A278 -> 0x8006A6AC
static s32 cpuCompile_D_SQRT(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r22
    // s32* addressGCN; // r21

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r21
    s32 nSize; // r1+0x8
}

// Range: 0x8006A0C8 -> 0x8006A278
static s32 cpuCompile_W_CVT_SD(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r31
    // s32* addressGCN; // r30

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r30
    s32 nSize; // r1+0x8
}

// Range: 0x80069B48 -> 0x8006A0C8
static s32 cpuCompile_L_CVT_SD(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x8006998C -> 0x80069B48
static s32 cpuCompile_CEIL_W(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x800697D0 -> 0x8006998C
static s32 cpuCompile_FLOOR_W(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_ROUND_W(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Erased
static s32 cpuCompile_TRUNC_W(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x80069664 -> 0x800697D0
static s32 cpuCompile_LB(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r9
    s32 nSize; // r1+0x8
}

// Range: 0x800694F8 -> 0x80069664
static s32 cpuCompile_LH(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r9
    s32 nSize; // r1+0x8
}

// Range: 0x800693A0 -> 0x800694F8
static s32 cpuCompile_LW(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x80069248 -> 0x800693A0
static s32 cpuCompile_LBU(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x800690F0 -> 0x80069248
static s32 cpuCompile_LHU(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x80068F94 -> 0x800690F0
static s32 cpuCompile_SB(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x80068E38 -> 0x80068F94
static s32 cpuCompile_SH(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x80068CDC -> 0x80068E38
static s32 cpuCompile_SW(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}

// Range: 0x80068B54 -> 0x80068CDC
static s32 cpuCompile_LDC(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x800689CC -> 0x80068B54
static s32 cpuCompile_SDC(struct _CPU* pCPU, s32* addressGCN) {
    // Parameters
    // struct _CPU* pCPU; // r30
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r5
    s32 nSize; // r1+0x8
}

// Range: 0x8006883C -> 0x800689CC
static s32 cpuCompile_LWL(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r9
    s32 nSize; // r1+0x8
}

// Range: 0x800686B0 -> 0x8006883C
static s32 cpuCompile_LWR(s32* addressGCN) {
    // Parameters
    // s32* addressGCN; // r31

    // Local variables
    s32* compile; // r1+0x10
    s32 count; // r7
    s32 nSize; // r1+0x8
}
