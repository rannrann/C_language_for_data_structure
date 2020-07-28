#include "LinkedListQueue.h"
typedef struct LinkedListQueue LinkedListQueue;

struct LinkedListQueue {
	Node *head;
	Node *tail;
	int size;
};

void empty_queue() {
	printf("Queue is empty.\n");
}


LinkedListQueue* create_linked_list_queue() {
	LinkedListQueue *llq = NULL;
	llq = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
	llq->head = NULL;
	llq->tail = NULL;
	llq->size = 0;
	return llq;
}

int linkedListQueue_getSize(LinkedListQueue *llq) {
	return llq->size;
}

bool linkedListQueue_isEmpty(LinkedListQueue *llq) {
	return llq->size == 0;
}

void linkedListQueue_enqueue(LinkedListQueue *llq, B e) {
	if (llq->tail == NULL)
	{
		llq->tail = create_node_with_empty_next(e);
		llq->head = llq->tail;
	}
	else {
		llq->tail->next = create_node_with_empty_next(e);
		llq->tail = llq->tail->next;
	}
	llq->size++;
}


B linkedListQueue_dequeue(LinkedListQueue *llq) {
	if (linkedListQueue_isEmpty(llq)) {
		atexit(empty_queue);
		exit(EXIT_FAILURE);
	}
	Node *retNode = llq->head;
	B returnE;
	llq->head = llq->head->next;
	retNode->next = NULL;
	returnE = retNode->e;
	free(retNode);
	retNode = NULL;
	if (llq->head == NULL) llq->tail = NULL;
	llq->size--;
	return returnE;
}

B getFront(LinkedListQueue *llq) {
	if (linkedListQueue_isEmpty(llq)) {
		atexit(empty_queue);
		exit(EXIT_FAILURE);
	}
	return llq->head->e;
}

void linkedListQueue_toString(LinkedListQueue *llq) {
	printf("Queue: front ");
	for (Node *cur = llq->head; cur != NULL; cur = cur->next)
		printf("%d->", cur->e);
	printf("NULL tail\n");
}

void release_linked_list_queue(LinkedListQueue *llq) {
	llq->tail = NULL;
	int i, j, length;
	Node *prev;
	for (i = llq->size / 2, length = llq->size; i > 0; i--, length -= 2) {
		prev = llq->head;
		for (j = 0; j < length - 2; j++)
			prev = prev->next;
		printf("%d\n", prev->next->e);
		free(prev->next);
		prev->next = NULL;
		printf("%d\n", prev->e);
		free(prev);
		prev = NULL;
	}
	if (llq->size % 2 == 1) {
		printf("%d\n", llq->head->e);
		free(llq->head);
		llq->head = NULL;
	}
	free(llq);
	llq = NULL;
}