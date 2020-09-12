#ifndef _SEGMENT_TREE_
#define _SEGMENT_TREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*�����߶������������Ϊ��*/

#define S SegmentTree_S

typedef struct S *S;

typedef struct SegmentTree SegmentTree;
struct SegmentTree {
	S *tree;
	S *data;
	int data_size;
};

//��treeIndex��λ�ô�����ʾ����[l...r]���߶���
void buildSegmentTree(SegmentTree *st,int treeIndex, int l, int r) {
	if (l == r) {
		st->tree[treeIndex] = st->data[l];
		return;
	}
	int leftTreeIndex = SegmentTree_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree_rightChild(treeIndex);

	int mid = l + (r - l) / 2;//ʵ���Ͼ���(r+l)/2������д���Ա��ⳬ���������ֵ

	buildSegmentTree(st, leftTreeIndex, l, mid);
	buildSegmentTree(st,rightTreeIndex, mid + 1, r);

	st->tree[treeIndex] = (int)st->tree[leftTreeIndex] + (int)st->tree[rightTreeIndex];//δ֪���͵�������ӱ�������ǿ������ת��
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

//������ȫ�������������ʾ�У�һ����������ʾ��Ԫ�ص����ӽڵ������
int SegmentTree_leftChild(int index) {
	return 2 * index + 1;
}

//������ȫ�������������ʾ�У�һ����������ʾ��Ԫ�ص��Һ��ӽڵ������
int SegmentTree_rightChild(int index) {
	return 2 * index + 2;
}

//����treeIndexΪ�����߶�����[l...r]�ķ�Χ���������[queryL...queryR]��ֵ
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

//����treeIndexΪ�����߶����и���index��ֵΪe
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

	st->tree[treeIndex] = (int)st->tree[leftTreeIndex] + (int)st->tree[rightTreeIndex];//δ֪���͵�������ӱ�������ǿ������ת��
}

//��indexλ�õ�ֵ������Ϊe
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
		if ((int)st->tree[i] > -10)//���ﱾ��д��st->tree[i]!=NULL�ģ����Ƕ���C������˵0����NULL��NULL����0.������(int)��ԭ����Ҫ��Sǿ��ת��Ϊint����Ȼ����0��1��2��������-10���������ΪNULL�����
			printf("%d", st->tree[i]);
		else
			printf("NULL");
		if (i != st->data_size * 4 - 1)
			printf(", ");
	}
	printf("]\n");
}

#endif