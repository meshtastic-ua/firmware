#pragma once

#include <cassert>
#include <type_traits>

#include "concurrency/OSThread.h"
#include "freertosinc.h"

#ifdef HAS_FREE_RTOS

/**
 * A wrapper for freertos queues.  Note: each element object should be small
 * and POD (Plain Old Data type) as elements are memcpied by value.
 */
template <class T> class TypedQueue
{
    static_assert(std::is_pod<T>::value, "T must be pod");
    QueueHandle_t h;
    concurrency::OSThread *reader = NULL;

  public:
    explicit TypedQueue(int maxElements) : h(xQueueCreate(maxElements, sizeof(T))) { assert(h); }

    ~TypedQueue() { vQueueDelete(h); }

    int numFree() { return uxQueueSpacesAvailable(h); }

    bool isEmpty() { return uxQueueMessagesWaiting(h) == 0; }

    /** euqueue a packet.  Also, maxWait used to default to portMAX_DELAY, but we now want to callers to THINK about what blocking
     * they want */
    bool enqueue(T x, TickType_t maxWait)
    {
        if (reader) {
            reader->setInterval(0);
            concurrency::mainDelay.interrupt();
        }
        return xQueueSendToBack(h, &x, maxWait) == pdTRUE;
    }

    bool enqueueFromISR(T x, BaseType_t *higherPriWoken)
    {
        if (reader) {
            reader->setInterval(0);
            concurrency::mainDelay.interruptFromISR(higherPriWoken);
        }
        return xQueueSendToBackFromISR(h, &x, higherPriWoken) == pdTRUE;
    }

    bool dequeue(T *p, TickType_t maxWait = portMAX_DELAY) { return xQueueReceive(h, p, maxWait) == pdTRUE; }

    bool dequeueFromISR(T *p, BaseType_t *higherPriWoken) { return xQueueReceiveFromISR(h, p, higherPriWoken); }

    /**
     * Set a thread that is reading from this queue
     * If a message is pushed to this queue that thread will be scheduled to run ASAP.
     *
     * Note: thread will not be automatically enabled, just have its interval set to 0
     */
    void setReader(concurrency::OSThread *t) { reader = t; }
};

#else

#include <queue>

/**
 * A wrapper for freertos queues.  Note: each element object should be small
 * and POD (Plain Old Data type) as elements are memcpied by value.
 */
template <class T> class TypedQueue
{
    std::queue<T> q;
    concurrency::OSThread *reader = NULL;
    int maxElements;

  public:
    explicit TypedQueue(int maxElements) {
        maxElements = maxElements;
    }

    int numFree() {
        return maxElements - q.size();
    } // return real size of elements allowed to be added to queue

    bool isEmpty() { return q.empty(); }

    bool enqueue(T x, TickType_t maxWait = portMAX_DELAY)
    {
        if (reader) {
            reader->setInterval(0);
            concurrency::mainDelay.interrupt();
        }

        q.push(x);
        return true;
    }

    // bool enqueueFromISR(T x, BaseType_t *higherPriWoken) { return xQueueSendToBackFromISR(h, &x, higherPriWoken) == pdTRUE; }

    bool dequeue(T *p, TickType_t maxWait = portMAX_DELAY)
    {
        if (isEmpty())
            return false;
        else {
            *p = q.front();
            q.pop();
            return true;
        }
    }

    // bool dequeueFromISR(T *p, BaseType_t *higherPriWoken) { return xQueueReceiveFromISR(h, p, higherPriWoken); }

    void setReader(concurrency::OSThread *t) { reader = t; }
};
#endif
