#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define B LinkedList_B
typedef struct B *B;
typedef struct Node Node;
typedef struct LinkedList LinkedList;
/*����LinkedList.h����ΪLinkedListQueueҲҪ�ã�ֻ���ƻ���˽��*/
struct Node {
	B e;
	Node *next;
};

void illegal_index();

Node* create_node_with_no_empty_next(B e, Node *next);

Node* create_node_with_empty_next(B e);

LinkedList *create_linked_list();

//��ȡ�����е�Ԫ�ظ���
int linkedList_getSize(LinkedList *ll);

//���������Ƿ�Ϊ��
bool linkedList_isEmpty(LinkedList *ll);


//������ĵ�index(0-based)λ������µ�Ԫ��e
//�������в���һ�����õĲ�������ϰ��
void linkedList_add(LinkedList *ll, int index, B e);


//������ͷ����µ�Ԫ��e
void linkedList_addFirst(LinkedList *ll, B e);

void linkedList_addLast(LinkedList *ll, B e);

//������ĵ�index(0-based)λ�õ�Ԫ��e
//�������в���һ�����õĲ�������ϰ��
B linkedList_get(LinkedList *ll, int index);

//�������ĵ�һ��Ԫ��
B linkedList_getFirst(LinkedList *ll);

B linkedList_getLast(LinkedList *ll);

//�޸�����ĵ�index(0-based)λ�õ�Ԫ��Ϊe
//�������в���һ�����õĲ�������ϰ��
void linkedList_set(LinkedList *ll, int index, B e);

//�����������Ƿ���Ԫ��e
bool linkedList_contains(LinkedList *ll, B e);

void linkedList_toString(LinkedList *ll);

//��������ɾ����index(0-based)λ�õ�Ԫ�أ�����ɾ����Ԫ��
//�������в���һ�����õĲ�������ϰ��
B linkedList_remove(LinkedList *ll, int index);

//��������ɾ����һ��Ԫ�أ�����ɾ����Ԫ��
B linkedList_removeFirst(LinkedList *ll);

//��������ɾ������Ԫ�أ�����ɾ����Ԫ��
B linkedList_removeLast(LinkedList *ll);

void linkedList_removeElement(LinkedList *ll, B e);

void release_linked_list(LinkedList *ll);
#endif