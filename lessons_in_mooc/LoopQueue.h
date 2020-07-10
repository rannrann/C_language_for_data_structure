#ifndef LOOP_QUEUE
#define LOOP_QUEUE
#include <stdio.h>
#include <stdbool.h>

#define C LoopQueue_C

typedef struct C *C;
typedef struct LoopQueue LoopQueue;

void dequeue_empty();
void getFront_empty();

LoopQueue* create_loop_queue(int capacity);
int LoopQueue_getCapacity(LoopQueue *lq);
int LoopQueue_getSize(LoopQueue *lq);
bool LoopQueue_isEmpty(LoopQueue *lq);

void LoopQueue_resize(LoopQueue *lq, int newCapacity);

void LoopQueue_enqueue(LoopQueue *lq, C e);
//Q一定是要和继承的Queue.h中的Q是一样的，不一样的话会被系统认为是重复定义
C LoopQueue_dequeue(LoopQueue *lq);
C LoopQueue_getFront(LoopQueue *lq);

void release_loop_queue(LoopQueue *lq);

void loopQueue_toString(LoopQueue *lq);
#endif
