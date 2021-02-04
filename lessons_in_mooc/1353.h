#ifndef _ONETHREEFIVETHREE_
#define _ONETHREEFIVETHREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct ThinkingResult ThinkingResult;
struct ThinkingResult {
	int *tree;
	int *data;
	int data_size;
};

//step 1
int leftChild(int index) {
	return 2 * index + 1;
}

int rightChild(int index) {
	return 2 * index + 2;
}

void buildThinkingResult(ThinkingResult *tr, int treeIndex, int l, int r) {
	if (r == l) {
		tr->tree[treeIndex] = (tr->data[l] == 0) ? 0 : -1;
		return;
	}
	int leftTreeIndex = leftChild(treeIndex);
	int rightTreeIndex = rightChild(treeIndex);
	int mid = l + (r - l) / 2;
	buildThinkingResult(tr, leftTreeIndex, l, mid);
	buildThinkingResult(tr, rightTreeIndex, mid + 1, r);

	if (tr->tree[leftTreeIndex] == 0 || tr->tree[rightTreeIndex] == 0)
		tr->tree[treeIndex] = 0;
	else if (tr->tree[leftTreeIndex] == 0 && tr->tree[rightTreeIndex] == 0)
		tr->tree[treeIndex] = 0;
	else
		tr->tree[treeIndex] = -1;
}

ThinkingResult* create_ThinkingResult(int size) {
	ThinkingResult *tr = NULL;
	tr = malloc(sizeof(ThinkingResult));
	tr->data = malloc(sizeof(int)*size);
	tr->data_size = size;
	memset(tr->data, 0, sizeof(int)*size);
	tr->tree = malloc(sizeof(int)*size * 4);
	buildThinkingResult(tr, 0, 0, size - 1);
	return tr;
}


//step 3

void swap_element1(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_element2(int *a, int *b) {
	int tmp1 = *a;
	int tmp2 = *(a + 1);
	*a = *b;
	*(a + 1) = *(b + 1);
	*b = tmp1;
	*(b + 1) = tmp2;

}

int random_partition(int *arr, int **doer, int start, int end) {
	int pIndex1 = rand() % (end - start + 1) + start;
	swap_element1(arr + pIndex1, arr + end);
	swap_element2(doer[pIndex1], doer[end]);
	int pivot = arr[end];
	int pIndex2 = start;
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			swap_element1(arr + i, arr + pIndex2);
			swap_element2(doer[i], doer[pIndex2]);
			pIndex2++;
		}
	}
	swap_element1(arr + pIndex2, arr + end);
	swap_element2(doer[pIndex2], doer[end]);
	return pIndex2;
}
void quick_sort2(int *arr, int **doer, int start, int end) {
	if (start < end) {
		int pIndex = random_partition(arr, doer, start, end);
		quick_sort2(arr, doer, start, pIndex - 1);
		quick_sort2(arr, doer, pIndex + 1, end);
	}
}

int tree_query2(int *tree, int treeIndex, int l, int r, int queryL, int queryR) {
	if (l == queryL && r == queryR)
		return tree[treeIndex];
	int mid = l + (r - l) / 2;
	int leftTreeIndex = leftChild(treeIndex);
	int rightTreeIndex = rightChild(treeIndex);
	if (queryL >= mid + 1)
		return tree_query2(tree, rightTreeIndex, mid + 1, r, queryL, queryR);
	else if (queryR <= mid)
		return tree_query2(tree, leftTreeIndex, l, mid, queryL, queryR);

	int leftResult = tree_query2(tree, leftTreeIndex, l, mid, queryL, mid);
	int rightResult = tree_query2(tree, rightTreeIndex, mid + 1, r, mid + 1, queryR);

	if (leftResult == 0 && rightResult == 0)
		return 0;
	else if (leftResult == 0 || rightResult == 0)
		return 0;
	else
		return -1;

}

int query(ThinkingResult *tr, int queryL, int queryR) {
	queryL--;
	queryR--;
	if (queryL < 0 || queryL >= tr->data_size || queryR < 0 || queryR >= tr->data_size) {
		printf("Index is illegal.queryL=%d,queryR=%d\n", queryL, queryR);
		exit(EXIT_FAILURE);
	}
	return tree_query2(tr->tree, 0, 0, tr->data_size - 1, queryL, queryR);
}

int update_tree2(ThinkingResult *tr,int treeIndex, int update_index, int l, int r) {
	if (l == r) {
		tr->tree[treeIndex] = -1;
		return -1;
	}

	int mid = l + (r - l) / 2;
	int leftTreeIndex = leftChild(treeIndex);
	int rightTreeIndex = rightChild(treeIndex);

	int leftRet, rightRet;
	if (update_index <= mid)
	{
		leftRet= update_tree2(tr, leftTreeIndex, update_index, l, mid);
		rightRet = tr->tree[rightTreeIndex];
	}		
	else{
		rightRet= update_tree2(tr, rightTreeIndex, update_index, mid + 1, r);
		leftRet= tr->tree[leftTreeIndex];
	}
		
	if (leftRet == 0 && rightRet == 0)
		tr->tree[treeIndex] = 0;
	else if (leftRet == 0 || rightRet == 0)
		tr->tree[treeIndex] = 0;
	else
		tr->tree[treeIndex] = -1;
	return 0;

}

void update_tree(ThinkingResult *tr, int update_index) {
	update_tree2(tr, 0, update_index, 0, tr->data_size - 1);
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
	//step 1
	int length = events[0][1];
	for (int i = 0; i < eventsSize; i++) {
		if (events[i][1] > length)
			length = events[i][1];
	}
	ThinkingResult* tr = create_ThinkingResult(length);
	printf("step 1\n");
	//step 2
	int *weight = malloc(sizeof(int)*eventsSize);
	for (int i = 0; i < eventsSize; i++)
	{
		if (events[i][0] != events[i][1])
			weight[i] = events[i][0] * 10 + events[i][1] * 10;
		else
			weight[i] = events[1][0];
	}
		

	printf("step 2\n");
	//step 3
	quick_sort2(weight, events, 0, eventsSize - 1);
	for (int i = 0; i < eventsSize; i++)
	{
		printf("[%d,%d],weight[%d]=%d\n", events[i][0], events[i][1], i, weight[i]);
	}
	int count = 0;
	for (int i = 0; i < eventsSize; i++)
	{
		int ret = query(tr, events[i][0], events[i][1]);
		if (ret == 0)
		{
			for (int j = events[i][0] - 1; j < events[i][1]; j++)
			{
				if (tr->data[j] == 0)
				{
					count++;
					tr->data[j] = -1;
					update_tree(tr, j);
					break;
				}
			}
		}
	}
	printf("step 3\n");

	free(tr->tree);
	free(tr->data);
	free(tr);
	tr = NULL;
	free(weight);
	weight = NULL;
	return count;
}
#endif