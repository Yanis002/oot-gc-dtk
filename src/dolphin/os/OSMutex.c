#include "dolphin/os.h"

#define PushTail(queue, mutex, link)     \
    do {                                 \
        OSMutex* __prev;                 \
                                         \
        __prev = (queue)->tail;          \
        if (__prev == NULL)              \
            (queue)->head = (mutex);     \
        else                             \
            __prev->link.next = (mutex); \
        (mutex)->link.prev = __prev;     \
        (mutex)->link.next = NULL;       \
        (queue)->tail = (mutex);         \
    } while (0)

#define PopHead(queue, mutex, link)   \
    do {                              \
        OSMutex* __next;              \
                                      \
        (mutex) = (queue)->head;      \
        __next = (mutex)->link.next;  \
        if (__next == NULL)           \
            (queue)->tail = NULL;     \
        else                          \
            __next->link.prev = NULL; \
        (queue)->head = __next;       \
    } while (0)

#define PopItem(queue, mutex, link)     \
    do {                                \
        OSMutex* __next;                \
        OSMutex* __prev;                \
                                        \
        __next = (mutex)->link.next;    \
        __prev = (mutex)->link.prev;    \
                                        \
        if (__next == NULL)             \
            (queue)->tail = __prev;     \
        else                            \
            __next->link.prev = __prev; \
                                        \
        if (__prev == NULL)             \
            (queue)->head = __next;     \
        else                            \
            __prev->link.next = __next; \
    } while (0)

void OSInitMutex(OSMutex* mutex) {
    OSInitThreadQueue(&mutex->queue);
    mutex->thread = 0;
    mutex->count = 0;
}

void OSLockMutex(OSMutex* mutex) {
    bool enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();
    OSThread* ownerThread;

    while (true) {
        ownerThread = ((OSMutex*)mutex)->thread;
        if (ownerThread == 0) {
            mutex->thread = currentThread;
            mutex->count++;
            PushTail(&currentThread->queueMutex, mutex, link);
            break;
        } else if (ownerThread == currentThread) {
            mutex->count++;
            break;
        } else {
            currentThread->mutex = mutex;
            __OSPromoteThread(mutex->thread, currentThread->priority);
            OSSleepThread(&mutex->queue);
            currentThread->mutex = 0;
        }
    }
    OSRestoreInterrupts(enabled);
}

void OSUnlockMutex(OSMutex* mutex) {
    bool enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();

    if (mutex->thread == currentThread && --mutex->count == 0) {
        PopItem(&currentThread->queueMutex, mutex, link);
        mutex->thread = NULL;
        if (currentThread->priority < currentThread->base) {
            currentThread->priority = __OSGetEffectivePriority(currentThread);
        }

        OSWakeupThread(&mutex->queue);
    }
    OSRestoreInterrupts(enabled);
}

void __OSUnlockAllMutex(OSThread* thread) {
    OSMutex* mutex;

    while (thread->queueMutex.head) {
        PopHead(&thread->queueMutex, mutex, link);
        mutex->count = 0;
        mutex->thread = NULL;
        OSWakeupThread(&mutex->queue);
    }
}

bool OSTryLockMutex(OSMutex* mutex) {
    bool enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();
    bool locked;
    if (mutex->thread == 0) {
        mutex->thread = currentThread;
        mutex->count++;
        PushTail(&currentThread->queueMutex, mutex, link);
        locked = true;
    } else if (mutex->thread == currentThread) {
        mutex->count++;
        locked = true;
    } else {
        locked = false;
    }
    OSRestoreInterrupts(enabled);
    return locked;
}

void OSInitCond(OSCond* cond) { OSInitThreadQueue(&cond->queue); }

void OSWaitCond(OSCond* cond, OSMutex* mutex) {
    bool enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();
    s32 count;

    if (mutex->thread == currentThread) {
        count = mutex->count;
        mutex->count = 0;
        PopItem(&currentThread->queueMutex, mutex, link);
        mutex->thread = NULL;

        if (currentThread->priority < currentThread->base) {
            currentThread->priority = __OSGetEffectivePriority(currentThread);
        }

        OSDisableScheduler();
        OSWakeupThread(&mutex->queue);
        OSEnableScheduler();
        OSSleepThread(&cond->queue);
        OSLockMutex(mutex);
        mutex->count = count;
    }

    OSRestoreInterrupts(enabled);
}

void OSSignalCond(OSCond* cond) { OSWakeupThread(&cond->queue); }

static bool IsMember(OSMutexQueue* queue, OSMutex* mutex) {
    OSMutex* member;

    for (member = queue->head; member; member = member->link.next) {
        if (mutex == member)
            return true;
    }
    return false;
}

bool __OSCheckMutex(OSMutex* mutex) {
    OSThread* thread;
    OSThreadQueue* queue;
    OSPriority priority = 0;

    queue = &mutex->queue;
    if (!(queue->head == NULL || queue->head->link.prev == NULL))
        return false;
    if (!(queue->tail == NULL || queue->tail->link.next == NULL))
        return false;
    for (thread = queue->head; thread; thread = thread->link.next) {
        if (!(thread->link.next == NULL || thread == thread->link.next->link.prev))
            return false;
        if (!(thread->link.prev == NULL || thread == thread->link.prev->link.next))
            return false;

        if (thread->state != OS_THREAD_STATE_WAITING)
            return false;

        if (thread->priority < priority)
            return false;
        priority = thread->priority;
    }

    if (mutex->thread) {
        if (mutex->count <= 0)
            return false;
    } else {
        if (0 != mutex->count)
            return false;
    }

    return true;
}

bool __OSCheckDeadLock(OSThread* thread) {
    OSMutex* mutex;

    mutex = thread->mutex;
    while (mutex && mutex->thread) {
        if (mutex->thread == thread)
            return true;
        mutex = mutex->thread->mutex;
    }
    return false;
}

bool __OSCheckMutexes(OSThread* thread) {
    OSMutex* mutex;

    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        if (mutex->thread != thread)
            return false;
        if (!__OSCheckMutex(mutex))
            return false;
    }
    return true;
}
