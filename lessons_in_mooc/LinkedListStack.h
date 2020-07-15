#ifndef _LINKED_LIST_STACK_
#define _LINKED_LIST_STACK_
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedListStack LinkedListStack;


LinkedListStack* create_linked_list_stack();

int linkedListStack_getSize(LinkedListStack *lls);

bool linkedListStack_isEmpty(LinkedListStack *lls);

void linkedListStack_push(LinkedListStack *lls, B e);

B linkedListStack_pop(LinkedListStack *lls);

B linkedListStack_peek(LinkedListStack *lls);

void linkedListStack_toString(LinkedListStack *lls);

void release_linked_list_stack(LinkedListStack *lls);

#endif