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
//Qһ����Ҫ�ͼ̳е�Queue.h�е�Q��һ���ģ���һ���Ļ��ᱻϵͳ��Ϊ���ظ�����
Q dequeue(LoopQueue *lq);
Q queue_getFront(LoopQueue *lq);

void release_loop_queue(LoopQueue *lq);

void loopQueue_toString(LoopQueue *lq);
#endif
