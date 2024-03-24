/*
    Compile unit: C:\WINDOWS\Profiles\slee\Desktop\EUROPE ZELDA\Core\xlList.c
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x800061A4 -> 0x8000656C
*/

#include "types.h"

typedef struct tXL_LIST {
    /* 0x0 */ s32 nItemSize;
    /* 0x4 */ s32 nItemCount;
    /* 0x8 */ void* pNodeHead;
    /* 0xC */ void* pNodeNext;
} __anon_0x2EDB; // size = 0x10

// size = 0x10, address = 0x801402A0
static struct tXL_LIST gListList;

// Erased
static s32 xlListWipe(struct tXL_LIST* pList) {
    // Parameters
    // struct tXL_LIST* pList; // r30

    // Local variables
    void* pNode; // r1+0xC
    void* pNodeNext; // r31
}

// Range: 0x80006474 -> 0x8000656C
s32 xlListMake(struct tXL_LIST** ppList, s32 nItemSize) {
    // Parameters
    // struct tXL_LIST** ppList; // r31
    // s32 nItemSize; // r29

    // References
    // -> static struct tXL_LIST gListList;
}

// Range: 0x800063B8 -> 0x80006474
s32 xlListFree(struct tXL_LIST** ppList) {
    // Parameters
    // struct tXL_LIST** ppList; // r29

    // References
    // -> static struct tXL_LIST gListList;
}

// Erased
static s32 xlListTest(struct tXL_LIST* pList) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0

    // Local variables
    void* pNode; // r4

    // References
    // -> static struct tXL_LIST gListList;
}

// Range: 0x8000630C -> 0x800063B8
s32 xlListMakeItem(struct tXL_LIST* pList, void* ppItem) {
    // Parameters
    // struct tXL_LIST* pList; // r30
    // void* ppItem; // r31

    // Local variables
    s32 nSize; // r4
    void* pListNode; // r1+0x10
    void* pNode; // r4
    void* pNodeNext; // r1+0x8
}

// Range: 0x80006260 -> 0x8000630C
s32 xlListFreeItem(struct tXL_LIST* pList, void* ppItem) {
    // Parameters
    // struct tXL_LIST* pList; // r31
    // void* ppItem; // r1+0xC

    // Local variables
    void* pNode; // r6
    void* pNodeNext; // r1+0x10
}

// Range: 0x800061D4 -> 0x80006260
s32 xlListTestItem(struct tXL_LIST* pList, void* pItem) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // void* pItem; // r1+0x4

    // Local variables
    void* pListNode; // r3

    // References
    // -> static struct tXL_LIST gListList;
}

// Erased
static s32 xlListFindItem(struct tXL_LIST* pList, s32 iItem, void* ppItem) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // s32 iItem; // r1+0x4
    // void* ppItem; // r1+0x8

    // Local variables
    s32 nItemCount; // r3
    void* pListNode; // r6
}

// Erased
static s32 xlListFindItemIndex(struct tXL_LIST* pList, s32* piItem, void* pItem) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // s32* piItem; // r1+0x4
    // void* pItem; // r1+0x8

    // Local variables
    s32 iItem; // r3
    void* pListNode; // r6
}

// Erased
static s32 xlListEnumerate(struct tXL_LIST* pList, s32 (* pfCallback)(void*)) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x8
    // s32 (* pfCallback)(void*); // r30

    // Local variables
    void* pNode; // r31
}

// Erased
static s32 xlListNodeGetHead(struct tXL_LIST* pList, void* ppListNode) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // void* ppListNode; // r1+0x4

    // References
    // -> static struct tXL_LIST gListList;
}

// Erased
static s32 xlListNodeGetNext(struct tXL_LIST* pList, void* ppListNode) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // void* ppListNode; // r1+0x4

    // References
    // -> static struct tXL_LIST gListList;
}

// Erased
static s32 xlListMoveItemToHead(struct tXL_LIST* pList, void* pItem) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // void* pItem; // r1+0x4

    // Local variables
    void* pNode; // r5
    void* pNodeLast; // r6
}

// Erased
static s32 xlListMoveItemToTail(struct tXL_LIST* pList, void* pItem) {
    // Parameters
    // struct tXL_LIST* pList; // r1+0x0
    // void* pItem; // r1+0x4

    // Local variables
    void* pNode; // r5
    void* pNodeLast; // r6
    void* pNodeItem; // r7
    void* pNodeItemLast; // r8
}

// Range: 0x800061AC -> 0x800061D4
s32 xlListSetup() {
    // References
    // -> static struct tXL_LIST gListList;
}

// Range: 0x800061A4 -> 0x800061AC
s32 xlListReset() {}
