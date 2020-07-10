#include "LoopQueue.h"
#include <string.h>
#include <stdlib.h>



struct LoopQueue {
	C *data;
	int front;
	int tail;
	int size;
	int capacity;
};

void dequeue_empty() {
	printf("Cannot dequeue from an empty queue.\n");
}
void getFront_empty() {
	printf("Queue is empty.\n");
}

LoopQueue* create_loop_queue(int capacity) {
	LoopQueue *lq = NULL;
	lq = malloc(sizeof(LoopQueue));
	lq->data = (C*)malloc((capacity + 1) * sizeof(C));
	lq->front = 0;
	lq->tail = 0;
	lq->size = 0;
	lq->capacity = capacity;
	return lq;
}

int LoopQueue_getCapacity(LoopQueue *lq) {
	return lq->capacity;
}
int LoopQueue_getSize(LoopQueue *lq) {
	return lq->size;
}
bool LoopQueue_isEmpty(LoopQueue *lq) {
	return lq->front == lq->tail;
}

void LoopQueue_resize(LoopQueue *lq, int newCapacity) {
	C *newData = (C*)malloc((newCapacity + 1) * sizeof(C));
	int i;
	for (int i = 0; i < lq->size; i++)
		newData[i] = lq->data[(i + lq->front) % (lq->capacity + 1)];
	free(lq->data);
	lq->data = NULL;
	lq->data = newData;
	newData = NULL;
	lq->capacity = newCapacity;
	lq->front = 0;
	lq->tail = lq->size;
}

void LoopQueue_enqueue(LoopQueue *lq, C e)
{
	int length = lq->capacity + 1;
	if ((lq->tail + 1) % length == lq->front)
		LoopQueue_resize(lq, lq->capacity * 2);
	lq->data[lq->tail] = e;
	lq->tail = (lq->tail + 1) % (lq->capacity + 1);
	lq->size++;
}
//Q一定是要和继承的Queue.h中的Q是一样的，不一样的话会被系统认为是重复定义
C LoopQueue_dequeue(LoopQueue *lq) {
	if (LoopQueue_isEmpty(lq)) {
		atexit(dequeue_empty);
		exit(EXIT_FAILURE);
	}
	C ret = lq->data[lq->front];
	lq->data[lq->front] = NULL;
	lq->front = (lq->front + 1) % (lq->capacity + 1);
	lq->size--;
	if (lq->size == lq->capacity / 4 && lq->capacity / 2 != 0)
		LoopQueue_resize(lq, lq->capacity / 2);
	return ret;
}
C queue_getFront(LoopQueue *lq) {
	if (LoopQueue_isEmpty(lq)) {
		atexit(getFront_empty);
		exit(EXIT_FAILURE);
	}
	return lq->data[lq->front];
}

void release_loop_queue(LoopQueue *lq) {
	if (!lq) return;
	if (lq->data) {
		free(lq->data);
		lq->data = NULL;
	}
	free(lq);
	lq = NULL;
}

void loopQueue_toString(LoopQueue *lq) {
	printf("Queue:size=%d,capacity=%d.\n", lq->size, lq->capacity);
	printf("front [");
	int i;
	for (i = lq->front; i != lq->tail; i = (i + 1) % (lq->capacity + 1)) {
		printf("%d", lq->data[i]);
		if ((i + 1) % (lq->capacity + 1) != lq->tail)
			printf(",");
	}
	printf("] tail\n");
}

