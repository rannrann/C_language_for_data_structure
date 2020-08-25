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
//����Ԫ�ظ���
int MaxHeap_getSize(MaxHeap* mh) {
	return array_getSize(mh->data);
}

//����һ������ֵ����ʾ�����Ƿ�Ϊ��
bool MaxHeap_isEmpty(MaxHeap* mh) {
	return array_isEmpty(mh->data);
}

//������ȫ�������������ʾ�У�һ����������ʾ��Ԫ�صĸ��׽ڵ������
int MaxHeap_getParentIndex(int index) {
	if (index == 0) {
		atexit(index_is_zero);
		exit(EXIT_FAILURE);
	}
	return (index - 1) / 2;
}

//������ȫ�������������ʾ�У�һ����������ʾ��Ԫ�ص����ӽڵ������
int MaxHeap_getLeftChildIndex(int index) {
	return index * 2 + 1;
}

//������ȫ�������������ʾ�У�һ����������ʾ��Ԫ�ص��Һ��ӽڵ������
int MaxHeap_getRightChildIndex(int index) {
	return index * 2 + 2;
}

void siftUp(MaxHeap *mh, int k) {
	while (k > 0 && get(mh->data, MaxHeap_getParentIndex(k)) < get(mh->data, k)) {
		array_swap(mh->data, k, MaxHeap_getParentIndex(k));
		k = MaxHeap_getParentIndex(k);
	}
}

//��������Ԫ��
void MaxHeap_add(MaxHeap *mh, E e) {
	addLast(mh->data, e);
	siftUp(mh,MaxHeap_getSize(mh) - 1);
}



//�����е����Ԫ��
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
		//mh->data[j]��leftchild��rightchild�е����ֵ

		if (get(mh->data, k) >= get(mh->data, j))
			break;
		array_swap(mh->data,k, j);
		k = j;
	}
}

//ȡ���������Ԫ��
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

