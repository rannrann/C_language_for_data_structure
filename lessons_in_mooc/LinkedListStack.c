#include "LinkedListStack.h"
struct LinkedListStack {
	LinkedList *list;
};
LinkedListStack* create_linked_list_stack() {
	LinkedListStack *lls = NULL;
	lls = malloc(sizeof(LinkedListStack));
	lls->list = create_linked_list();
	return lls;
}

int linkedListStack_getSize(LinkedListStack *lls) {
	return linkedList_getSize(lls->list);
}

bool linkedListStack_isEmpty(LinkedListStack *lls) {
	return linkedList_isEmpty(lls->list);
}

void linkedListStack_push(LinkedListStack *lls, B e) {
	linkedList_addFirst(lls->list, e);
}

B linkedListStack_pop(LinkedListStack *lls) {
	return linkedList_removeFirst(lls->list);
}

B linkedListStack_peek(LinkedListStack *lls) {
	return linkedList_getFirst(lls->list);
}

void linkedListStack_toString(LinkedListStack *lls) {
	printf("Stack:top ");
	linkedList_toString(lls->list);
}

void release_linked_list_stack(LinkedListStack *lls) {
	release_linked_list(lls->list);
	free(lls);
	lls = NULL;
}
