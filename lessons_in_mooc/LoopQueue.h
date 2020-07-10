#ifndef LOOP_QUEUE
#define LOOP_QUEUE
#include "Queue.h"
#include <stdio.h>


typedef struct LoopQueue LoopQueue;

void dequeue_empty();
void getFront_empty();

LoopQueue* create_loop_queue(int capacity);
int loopQueue_getCapacity(LoopQueue *lq);
int queue_getSize(LoopQueue *lq);
bool queue_isEmpty(LoopQueue *lq);

void loopQueue_resize(LoopQueue *lq, int newCapacity);

void enqueue(LoopQueue *lq, Q e);
//Q一定是要和继承的Queue.h中的Q是一样的，不一样的话会被系统认为是重复定义
Q dequeue(LoopQueue *lq);
Q queue_getFront(LoopQueue *lq);

void release_loop_queue(LoopQueue *lq);

void loopQueue_toString(LoopQueue *lq);
#endif
