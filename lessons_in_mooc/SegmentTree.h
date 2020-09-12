#ifndef _SEGMENT_TREE_
#define _SEGMENT_TREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*以下线段树是以区间和为例*/

#define S SegmentTree_S

typedef struct S *S;

typedef struct SegmentTree SegmentTree;
struct SegmentTree {
	S *tree;
	S *data;
	int data_size;
};

//在treeIndex的位置创建表示区间[l...r]的线段树
void buildSegmentTree(SegmentTree *st,int treeIndex, int l, int r) {
	if (l == r) {
		st->tree[treeIndex] = st->data[l];
		return;
	}
	int leftTreeIndex = SegmentTree_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree_rightChild(treeIndex);

	int mid = l + (r - l) / 2;//实际上就是(r+l)/2。这样写可以避免超过整型最大值

	buildSegmentTree(st, leftTreeIndex, l, mid);
	buildSegmentTree(st,rightTreeIndex, mid + 1, r);

	st->tree[treeIndex] = (int)st->tree[leftTreeIndex] + (int)st->tree[rightTreeIndex];//未知类型的数组相加报错，所以强制类型转换
}

SegmentTree* create_segmentTree(S* arr,int size) {
	SegmentTree *st = NULL;
	st = malloc(sizeof(SegmentTree));
	st->data = malloc(sizeof(S)*size);
	st->data_size = size;
	for (int i = 0; i < size; i++)
		st->data[i] = arr[i];
	st->tree = malloc(sizeof(S)*size * 4);
	buildSegmentTree(st, 0, 0,size - 1);
	return st;
}

int SegmentTree_getSize(SegmentTree *st) {
	return st->data_size;
}

S SegmentTree_get(SegmentTree *st,int index) {
	if (index < 0 || index >= st->data_size) {
		printf("Index is illegal\n");
		exit(EXIT_FAILURE);
	}
	return st->data[index];
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
int SegmentTree_leftChild(int index) {
	return 2 * index + 1;
}

//返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
int SegmentTree_rightChild(int index) {
	return 2 * index + 2;
}

//在以treeIndex为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
int tree_query(S *tree, int treeIndex, int l, int r, int queryL, int queryR) {
	if (l == queryL && r == queryR)
		return tree[treeIndex];
	int mid = l + (r - l) / 2;
	int leftTreeIndex = SegmentTree_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree_rightChild(treeIndex);

	if (queryL >= mid + 1)
		return tree_query(tree, rightTreeIndex, mid + 1, r, queryL, queryR);
	else if (queryR <= mid)
		return tree_query(tree, leftTreeIndex, l, mid, queryL, queryR);
	int leftResult = tree_query(tree, leftTreeIndex, l, mid, queryL, mid);
	int rightResult = tree_query(tree, rightTreeIndex, mid + 1, r, mid + 1, queryR);

	return leftResult + rightResult;

}


int SegmentTree_query(SegmentTree *st, int queryL, int queryR)
{
	if (queryL < 0 || queryL >= st->data_size || queryR < 0 || queryR >= st->data_size) {
		printf("Index is illegal\n");
		exit(EXIT_FAILURE);
	}
	return tree_query(st->tree, 0, 0, st->data_size - 1, queryL, queryR);
}

//在以treeIndex为根的线段树中更新index的值为e
void tree_set(SegmentTree *st,int treeIndex, int l, int r, int index, S e) {
	if (l == r) {
		st->tree[treeIndex] = e;
		return;
	}

	int mid = l + (r - l) / 2;
	int leftTreeIndex = SegmentTree_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree_rightChild(treeIndex);

	if (index >= mid + 1)
		tree_set(st, rightTreeIndex, mid + 1, r, index, e);
	else
		tree_set(st, leftTreeIndex, l, mid, index, e);

	st->tree[treeIndex] = (int)st->tree[leftTreeIndex] + (int)st->tree[rightTreeIndex];//未知类型的数组相加报错，所以强制类型转换
}

//将index位置的值，更新为e
void SegmentTree_set(SegmentTree *st, int index, S e) {
	if (index < 0 || index >= st->data_size)
	{
		printf("Index is illegal\n");
		exit(EXIT_FAILURE);
	}
	st->data[index] = e;
	tree_set(st, 0, 0, st->data_size - 1, index, e);
}


void release_SegmentTree(SegmentTree *st) {
	free(st->tree);
	free(st->data);
	st->tree = NULL;
	st->data = NULL;
	free(st);
	st = NULL;
}

void SegmentTree_toString(SegmentTree *st) {
	printf("[");
	for (int i = 0; i < st->data_size * 4; i++) {
		if ((int)st->tree[i] > -10)//这里本该写成st->tree[i]!=NULL的，但是对于C语言来说0就是NULL，NULL就是0.而加上(int)的原因是要将S强制转换为int，不然会有0、1和2明明大于-10，但是输出为NULL的情况
			printf("%d", st->tree[i]);
		else
			printf("NULL");
		if (i != st->data_size * 4 - 1)
			printf(", ");
	}
	printf("]\n");
}

#endif