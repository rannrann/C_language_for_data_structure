#include "ArrayQueue.h"
struct ArrayQueue {
	Array *array;
};

ArrayQueue* create_array_queue(int capacity) {
	ArrayQueue *aq = NULL;
	aq = malloc(sizeof(ArrayQueue));//第一次写，这块报错，执行后无错
	aq->array = create_array(capacity);
	return aq;
}

int arrayQueue_getSize(ArrayQueue *aq)
{
	return array_getSize(aq->array);
}

bool arrayQueue_isEmpty(ArrayQueue *aq) {
	return array_isEmpty(aq->array);
}

int arrayQueue_getCapacity(ArrayQueue *aq) {
	return array_getCapacity(aq->array);
}

void arrayQueue_enqueue(ArrayQueue *aq, Q q) {
	addLast(aq->array, q);//第一次写，这块报错，执行后无错
}
Q arrayQueue_dequeue(ArrayQueue *aq) {
	removeFirst(aq->array);
}
Q arrayQueue_getFront(ArrayQueue *aq) {
	getFirst(aq->array);
}

void arrayQueue_toString(ArrayQueue* aq) {
	printf("Queue:front[");
	int i;
	for (i = 0; i < array_getSize(aq->array); i++) {
		printf("%d", get(aq->array,i));
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