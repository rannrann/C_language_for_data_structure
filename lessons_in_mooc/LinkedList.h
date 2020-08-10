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
/*放在LinkedList.h是因为LinkedListQueue也要用，只能破坏隐私性*/
struct Node {
	B e;
	Node *next;
};

void illegal_index();

Node* create_node_with_no_empty_next(B e, Node *next);

Node* create_node_with_empty_next(B e);

LinkedList *create_linked_list();

//获取链表中的元素个数
int linkedList_getSize(LinkedList *ll);

//返回链表是否为空
bool linkedList_isEmpty(LinkedList *ll);


//在链表的第index(0-based)位置添加新的元素e
//在链表中不是一个常用的操作，练习用
void linkedList_add(LinkedList *ll, int index, B e);


//在链表头添加新的元素e
void linkedList_addFirst(LinkedList *ll, B e);

void linkedList_addLast(LinkedList *ll, B e);

//在链表的第index(0-based)位置的元素e
//在链表中不是一个常用的操作，练习用
B linkedList_get(LinkedList *ll, int index);

//获得链表的第一个元素
B linkedList_getFirst(LinkedList *ll);

B linkedList_getLast(LinkedList *ll);

//修改链表的第index(0-based)位置的元素为e
//在链表中不是一个常用的操作，练习用
void linkedList_set(LinkedList *ll, int index, B e);

//查找链表中是否有元素e
bool linkedList_contains(LinkedList *ll, B e);

void linkedList_toString(LinkedList *ll);

//从链表中删除第index(0-based)位置的元素，返回删除的元素
//在链表中不是一个常用的操作，练习用
B linkedList_remove(LinkedList *ll, int index);

//从链表中删除第一个元素，返回删除的元素
B linkedList_removeFirst(LinkedList *ll);

//从链表中删除最后的元素，返回删除的元素
B linkedList_removeLast(LinkedList *ll);

void linkedList_removeElement(LinkedList *ll, B e);

void release_linked_list(LinkedList *ll);
#endif