#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include "Array.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue ArrayQueue;

ArrayQueue* create_array_queue(int capacity);

int queue_getSize(ArrayQueue *aq);
bool queue_isEmpty(ArrayQueue *aq);

int getCapacity(ArrayQueue *aq);

void enqueue(ArrayQueue *aq, Q q);
Q dequeue(ArrayQueue *aq);
Q queue_getFront(ArrayQueue *aq);

void arrayQueue_toString(ArrayQueue* aq);

void release_array_queue(ArrayQueue* aq);
#endif