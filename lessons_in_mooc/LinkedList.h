#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B LinkedList_B
typedef struct B *B;
typedef struct LinkedList {
	Node *head;
	int size;
}LinkedList;

typedef struct Node {
	B e;
	Node *next;
}Node;


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
	ll->head = NULL;
	ll->size = 0;
}

//��ȡ�����е�Ԫ�ظ���
int getSize(LinkedList *ll) {
	return ll->size;
}

//���������Ƿ�Ϊ��
bool isEmpty(LinkedList *ll) {
	return ll->size == 0;
}

//������ͷ����µ�Ԫ��e
void addFirst(LinkedList *ll,B e){
	//Node *node = create_node_with_empty_next(e);
	//node->next = ll->head;
	//ll->head = node;
	ll->head = create_node_with_no_empty_next(e, ll->head);
	ll->size;
}

//�������index(0-based)λ������µ�Ԫ��e
//�������в���һ�����õĲ�������ϵ��
void add(LinkedList *ll, int index, B e) {
	if (index<0 || index > ll->size) {
		atexit(illegal_index);
		exit(EXIT_FAILURE);
	}
}

void release_linked_list(LinkedList *ll) {
	int step = ll->size,i;
	Node *prev = ll->head;
	for (i=0; i<step-2; i++) {
		free(prev->next);
		free(prev);
	}
}
#endif