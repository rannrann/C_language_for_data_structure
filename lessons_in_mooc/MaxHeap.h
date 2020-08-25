#ifndef _MAX_HEAP_
#define _MAX_HEAP_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Array.h"

typedef struct MaxHeap MaxHeap;
struct MaxHeap {
	Array *data;
};

void index_is_zero() {
	printf("Index is zero. The element has not parents.\n");
}

void empty() {
	printf("Can not findMax when heap is empty.\n");
}

MaxHeap* create_maxheap(int capacity) {
	MaxHeap *mh = NULL;
	mh = (MaxHeap*)malloc(sizeof(MaxHeap));
	mh->data = create_array(capacity);
	return mh;
}
//返回元素个数
int MaxHeap_getSize(MaxHeap* mh) {
	return array_getSize(mh->data);
}

//返回一个布尔值，表示堆中是否为空
bool MaxHeap_isEmpty(MaxHeap* mh) {
	return array_isEmpty(mh->data);
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
int MaxHeap_getParentIndex(int index) {
	if (index == 0) {
		atexit(index_is_zero);
		exit(EXIT_FAILURE);
	}
	return (index - 1) / 2;
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
int MaxHeap_getLeftChildIndex(int index) {
	return index * 2 + 1;
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
int MaxHeap_getRightChildIndex(int index) {
	return index * 2 + 2;
}

void siftUp(MaxHeap *mh, int k) {
	while (k > 0 && get(mh->data, MaxHeap_getParentIndex(k)) < get(mh->data, k)) {
		array_swap(mh->data, k, MaxHeap_getParentIndex(k));
		k = MaxHeap_getParentIndex(k);
	}
}

//向堆中添加元素
void MaxHeap_add(MaxHeap *mh, E e) {
	addLast(mh->data, e);
	siftUp(mh,MaxHeap_getSize(mh) - 1);
}



//看堆中的最大元素
E MaxHeap_findMax(MaxHeap *mh) {
	if(MaxHeap_getSize(mh)==0) {
		atexit(empty);
		exit(EXIT_FAILURE);
	}
	return get(mh->data, 0);
}


void siftDown(MaxHeap *mh, int k) {
	while (MaxHeap_getLeftChildIndex(k) < MaxHeap_getSize(mh)) {
		int j = MaxHeap_getLeftChildIndex(k);
		if (j + 1 < MaxHeap_getSize(mh) && get(mh->data, j + 1) > get(mh->data,j))
			j++;
		//mh->data[j]是leftchild和rightchild中的最大值

		if (get(mh->data, k) >= get(mh->data, j))
			break;
		array_swap(mh->data,k, j);
		k = j;
	}
}

//取出堆中最大元素
E MaxHeap_extractMax(MaxHeap *mh) {
	E ret = MaxHeap_findMax(mh);

	array_swap(mh->data,0, MaxHeap_getSize(mh) - 1);
	removeLast(mh->data);
	siftDown(mh, 0);
	return ret;
}

void release_maxheap(MaxHeap* mh) {
	release_array(mh->data);
	free(mh);
	mh = NULL;
}
#endif

