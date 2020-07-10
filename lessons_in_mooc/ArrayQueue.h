#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include "Array.h"
#include <stdio.h>
#include <stdlib.h>

#define Q ArrayQueue_Q

typedef struct Q *Q;

typedef struct ArrayQueue ArrayQueue;

ArrayQueue* create_array_queue(int capacity);

int ArrayQueue_queue_getSize(ArrayQueue *aq);
bool ArrayQueue_queue_isEmpty(ArrayQueue *aq);

int ArrayQueue_getCapacity(ArrayQueue *aq);

void ArrayQueue_enqueue(ArrayQueue *aq, Q q);
Q ArrayQueue_dequeue(ArrayQueue *aq);
Q ArrayQueue_getFront(ArrayQueue *aq);

void arrayQueue_toString(ArrayQueue* aq);

void release_array_queue(ArrayQueue* aq);
#endif