#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include "Array.h"
#include "Queue.h"
#include <stdio.h>

typedef struct ArrayQueue {
	Array *array;
}ArrayQueue;

ArrayQueue* create_array_queue(int capacity) {
	ArrayQueue *aq = NULL;
	aq = malloc(sizeof(ArrayQueue));
	aq->array = create_array(capacity);
	return aq;
}

int queue_getSize(ArrayQueue *aq)
{
	return array_getSize(aq->array);
}

bool queue_isEmpty(ArrayQueue *aq){
	return array_isEmpty(aq->array);
}

int getCapacity(ArrayQueue *aq) {
	return array_getCapacity(aq->array);
}

void enqueue(ArrayQueue *aq, Q q) {
	addLast(aq->array, q);
}
Q dequeue(ArrayQueue *aq) {
	removeFirst(aq->array);
}
Q queue_getFront(ArrayQueue *aq) {
	getFirst(aq->array);
}

void arrayQueue_toString(ArrayQueue* aq) {
	printf("Queue:front[");
	int i;
	for (i = 0; i < array_getSize(aq->array); i++) {
		printf("%d", aq->array->data[i]);
		if (i != array_getSize(aq->array) - 1)
			printf(",");
	}
	printf("]tail \n");
}
#endif