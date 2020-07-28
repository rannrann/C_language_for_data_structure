#ifndef _LINKED_LIST_QUEUE_
#define _LINKED_LIST_QUEUE_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h" 


typedef struct LinkedListQueue LinkedListQueue;

void empty_queue();


LinkedListQueue* create_linked_list_queue();

int linkedListQueue_getSize(LinkedListQueue *llq);

bool linkedListQueue_isEmpty(LinkedListQueue *llq);

void linkedListQueue_enqueue(LinkedListQueue *llq, B e);


B linkedListQueue_dequeue(LinkedListQueue *llq);

B getFront(LinkedListQueue *llq);
void linkedListQueue_toString(LinkedListQueue *llq);

void release_linked_list_queue(LinkedListQueue *llq);
#endif 