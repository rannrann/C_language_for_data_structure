#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include "Array.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define Q ArrayQueue_Q

typedef struct Q *Q;

typedef struct ArrayQueue ArrayQueue;

ArrayQueue* create_array_queue(int capacity);

int arrayQueue_getSize(ArrayQueue *aq);
bool arrayQueue_isEmpty(ArrayQueue *aq);

int arrayQueue_getCapacity(ArrayQueue *aq);

void arrayQueue_enqueue(ArrayQueue *aq, Q q);
Q arrayQueue_dequeue(ArrayQueue *aq);
Q arrayQueue_getFront(ArrayQueue *aq);

void arrayQueue_toString(ArrayQueue* aq);

void release_array_queue(ArrayQueue* aq);
#endif