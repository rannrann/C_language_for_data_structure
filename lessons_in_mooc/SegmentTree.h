#ifndef _SEGMENT_TREE_
#define _SEGMENT_TREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define S SegmentTree_S

typedef struct S *S;

typedef struct SegmentTree SegmentTree;
struct SegmentTree {
	S *tree;
	S *data;
	int data_size;
};

void create_segmentTree(S[] arr,int size) {
	SegmentTree *st = NULL;
	st = malloc(sizeof(SegmentTree));
	st->data = malloc(sizeof(S)*size);
	st->data_size = size;
	for (int i = 0; i < size; i++)
		st->data[i] = arr[i];
	tree = malloc(sizeof(S)*size * 4);
}

int SegmentTree_getSize(SegmentTree *st) {
	return st->data_size;
}

S get(SegmentTree *st,int index) {
	if (index < 0 || index >= st->data_size) {
		printf("Index is illegal\n");
		exit(EXIT_FAILURE);
	}
	return st->data[index];
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
int SegmentTree_leftChild(SegmentTree *st, int index) {
	return 2 * index + 1;
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
int SegmentTree_rightChild(SegmentTree *st, int index) {
	return 2 * index + 2;
}

#endif