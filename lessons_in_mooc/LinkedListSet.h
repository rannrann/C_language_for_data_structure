#ifndef _LINKED_LIST_SET_
#define _LINKED_LIST_SET_
#include "LinkedList.h"
typedef struct LinkedListSet LinkedListSet;
struct LinkedListSet {
	LinkedList *ll;
};

LinkedListSet* create_linked_list_set() {
	LinkedListSet *lls = NULL;
	lls = (LinkedListSet*)malloc(sizeof(LinkedListSet));
	lls->ll = create_linked_list();
	return lls;
}

int LinkedListSet_getSize(LinkedListSet *lls) {
	return linkedList_getSize(lls->ll);
}

bool LinkedListSet_isEmpty(LinkedListSet *lls) {
	return linkedList_isEmpty(lls->ll);
}

bool LinkedListSet_contains(LinkedListSet *lls, B e) {
	return linkedList_contains(lls->ll, e);
}

void LinkedListSet_add(LinkedListSet *lls, B e) {
	if (!LinkedListSet_contains(lls, e))
		linkedList_addFirst(lls->ll,e);
}

void LinkedListSet_remove(LinkedListSet *lls, B e) {
	linkedList_remove(lls->ll, e);
}

void release_linked_list_set(LinkedListSet *lls) {
	release_linked_list(lls->ll);
	free(lls);
	lls = NULL;
}
#endif
