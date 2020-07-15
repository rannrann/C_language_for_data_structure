#include "ArrayQueue.h"
#include <stdio.h>
#include <stdlib.h>
struct ArrayQueue {
	Array *array;
};

ArrayQueue* create_array_queue(int capacity) {
	ArrayQueue *aq = NULL;
	aq = malloc(sizeof(ArrayQueue));//��һ��д����鱨����ִ�к��޴�
	aq->array = create_array(capacity);
	return aq;
}

int ArrayQueue_getSize(ArrayQueue *aq)
{
	return array_getSize(aq->array);
}

bool ArrayQueue_isEmpty(ArrayQueue *aq) {
	return array_isEmpty(aq->array);
}

int ArrayQueue_getCapacity(ArrayQueue *aq) {
	return array_getCapacity(aq->array);
}

void ArrayQueue_enqueue(ArrayQueue *aq, Q q) {
	addLast(aq->array, q);//��һ��д����鱨����ִ�к��޴�
}
Q ArrayQueue_dequeue(ArrayQueue *aq) {
	removeFirst(aq->array);
}
Q ArrayQueue_getFront(ArrayQueue *aq) {
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

void release_array_queue(ArrayQueue* aq) {
	release_array(aq->array);
	free(aq);
	aq = NULL;
}