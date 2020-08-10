#include "LinkedList.h"



struct LinkedList {
	Node *dummyHead;
	int size;
};




void illegal_index() {
	printf("Add failed, illegal index.\n");
}

Node* create_node_with_no_empty_next(B e, Node *next) {
	Node *node = NULL;
	node = malloc(sizeof(Node));
	node->e = e;
	node->next = next;
	return node;
}

Node* create_node_with_empty_next(B e) {
	return create_node_with_no_empty_next(e, NULL);
}

LinkedList *create_linked_list() {
	LinkedList *ll = NULL;
	ll = malloc(sizeof(LinkedList));
	ll->dummyHead = create_node_with_no_empty_next(NULL, NULL);
	ll->size = 0;
}

//��ȡ�����е�Ԫ�ظ���
int linkedList_getSize(LinkedList *ll) {
	return ll->size;
}

//���������Ƿ�Ϊ��
bool linkedList_isEmpty(LinkedList *ll) {
	return ll->size == 0;
}


//������ĵ�index(0-based)λ������µ�Ԫ��e
//�������в���һ�����õĲ�������ϰ��
void linkedList_add(LinkedList *ll, int index, B e) {
	if (index<0 || index > ll->size) {
		atexit(illegal_index);
		exit(EXIT_FAILURE);
	}

	Node *prev = ll->dummyHead;
	for (int i = 0; i < index; i++)
		prev = prev->next;
	prev->next = create_node_with_no_empty_next(e, prev->next);
	ll->size++;
}


//������ͷ����µ�Ԫ��e
void linkedList_addFirst(LinkedList *ll, B e) {
	linkedList_add(ll, 0, e);
}

void linkedList_addLast(LinkedList *ll, B e) {
	linkedList_add(ll, ll->size, e);
}


//������ĵ�index(0-based)λ�õ�Ԫ��e
//�������в���һ�����õĲ�������ϰ��
B linkedList_get(LinkedList *ll, int index) {
	if (index<0 || index > ll->size) {
		atexit(illegal_index);
		exit(EXIT_FAILURE);
	}
	Node *cur = ll->dummyHead->next;
	int i;
	for (i = 0; i < index; i++)
		cur = cur->next;
	return cur->e;
}

//�������ĵ�һ��Ԫ��
B linkedList_getFirst(LinkedList *ll) {
	return linkedList_get(ll, 0);
}

B linkedList_getLast(LinkedList *ll) {
	return linkedList_get(ll, ll->size - 1);
}

//�޸�����ĵ�index(0-based)λ�õ�Ԫ��Ϊe
//�������в���һ�����õĲ�������ϰ��
void linkedList_set(LinkedList *ll, int index, B e) {
	if (index<0 || index > ll->size) {
		atexit(illegal_index);
		exit(EXIT_FAILURE);
	}
	Node *cur = ll->dummyHead->next;
	int i;
	for (i = 0; i < index; i++)
		cur = cur->next;
	cur->e = e;
}

//�����������Ƿ���Ԫ��e
bool linkedList_contains(LinkedList *ll, B e) {
	Node *cur = ll->dummyHead->next;
	while (cur != NULL) {
		if (cur->e == e) return true;
		cur = cur->next;
	}
	return false;
}

void linkedList_toString(LinkedList *ll) {
	for (Node *cur = ll->dummyHead->next; cur != NULL; cur = cur->next)
		printf("%d->", cur->e);
	printf("NULL\n");
}

//��������ɾ����index(0-based)λ�õ�Ԫ�أ�����ɾ����Ԫ��
//�������в���һ�����õĲ�������ϰ��
B linkedList_remove(LinkedList *ll, int index) {
	if (index<0 || index > ll->size) {
		atexit(illegal_index);
		exit(EXIT_FAILURE);
	}
	B returnE;
	Node *prev = ll->dummyHead;
	for (int i = 0; i < index; i++)
		prev = prev->next;
	Node *retNode = prev->next;
	prev->next = retNode->next;
	retNode->next = NULL;
	returnE = retNode->e;
	free(retNode);
	retNode = NULL;
	ll->size--;
	return returnE;
}

//��������ɾ����һ��Ԫ�أ�����ɾ����Ԫ��
B linkedList_removeFirst(LinkedList *ll) {
	return linkedList_remove(ll, 0);
}

//��������ɾ������Ԫ�أ�����ɾ����Ԫ��
B linkedList_removeLast(LinkedList *ll) {
	return linkedList_remove(ll, ll->size - 1);
}

void linkedList_removeElement(LinkedList *ll, B e) {
	for (Node *prev = ll->dummyHead; prev->next != NULL; prev = prev->next) {
		if (prev->next->e == e) {
			Node *target = prev->next;
			prev->next = target->next;
			target->next = NULL;
			free(target);
			target = NULL;
		}
	}
}

void release_linked_list(LinkedList *ll) {
	int i, j, length;
	Node *prev;
	for (i = ll->size / 2, length = ll->size; i > 0; i--, length -= 2) {
		prev = ll->dummyHead->next;
		for (j = 0; j < length - 2; j++)
			prev = prev->next;
		printf("%d\n", prev->next->e);
		free(prev->next);
		prev->next = NULL;
		printf("%d\n", prev->e);
		free(prev);
		prev = NULL;
	}
	if (ll->size % 2 == 1) {
		printf("%d\n", ll->dummyHead->next->e);
		free(ll->dummyHead->next);
		ll->dummyHead->next = NULL;
	}
	printf("%d\n", ll->dummyHead->e);
	free(ll->dummyHead);
	ll->dummyHead = NULL;
	free(ll);
	ll = NULL;

}
