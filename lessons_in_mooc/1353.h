#ifndef _ONETHREEFIVETHREE_
#define _ONETHREEFIVETHREE_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//step 3
typedef struct SegmentTree2 SegmentTree2;
struct SegmentTree2 {
	bool *tree;
	int *data;
	int data_size;
};

int SegmentTree2_leftChild(int index) {
	return 2 * index + 1;
}

int SegmentTree2_rightChild(int index) {
	return 2 * index + 2;
}

void buildSegmentTree2(SegmentTree2 *st, int treeIndex, int l, int r) {
	if (r == l) {
		//printf("r==l时,l=%d\n", l);
		st->tree[treeIndex] = (st->data[l] == 0) ? false : true;
		return;
	}
	int leftTreeIndex = SegmentTree2_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree2_rightChild(treeIndex);

	int mid = l + (r - l) / 2;
	//printf("treeIndex=%d, l=%d, r=%d,leftTreeIndex=%d, rightTreeIndex=%d, mid=%d\n", treeIndex, l, r, leftTreeIndex, rightTreeIndex, mid);

	buildSegmentTree2(st, leftTreeIndex, l, mid);
	buildSegmentTree2(st, rightTreeIndex, mid+1, r);

	if (st->tree[leftTreeIndex]==true &&  st->tree[rightTreeIndex]==true)
		st->tree[treeIndex] = true;
	else
		st->tree[treeIndex] = false;
}

SegmentTree2* create_segmentTree2(int *arr, int size) {
	SegmentTree2 *st = NULL;
	st = malloc(sizeof(SegmentTree2));
	st->data = malloc(sizeof(int)*size);
	st->data_size = size;
	for (int i = 0; i < size; i++)
		st->data[i] = arr[i];
	st->tree = malloc(sizeof(bool)*size * 4);
	memset(st->tree, -1, sizeof(bool)*size * 4);
	buildSegmentTree2(st, 0, 0, size - 1);
	return st;
}

void refresh(SegmentTree2* st,int *arr, int size) {
	for (int i = 0; i < size; i++)
		st->data[i] = arr[i];
	buildSegmentTree2(st, 0, 0, size - 1);
}

//step2-function
int toNoneValue(int*** IntervalIndex, int start,int max) {
	for (int i = 0; i < max; i++) {
		if (IntervalIndex[start][i][0]< 0)
			return i;
	}
	return 0;
}

//step 5
bool tree_query2(bool *tree, int treeIndex, int l, int r, int queryL, int queryR) {
	if (l == queryL && r == queryR)
		return tree[treeIndex];
	int mid = l + (r - l) / 2;
	int leftTreeIndex = SegmentTree2_leftChild(treeIndex);
	int rightTreeIndex = SegmentTree2_rightChild(treeIndex);
	if (queryL >= mid + 1)
		return tree_query2(tree, rightTreeIndex, mid+1, r, queryL, queryR);
	else if (queryR <= mid)
		return tree_query2(tree, leftTreeIndex, l, mid, queryL, queryR);
	bool leftResult = tree_query2(tree, leftTreeIndex, l, mid, queryL, mid);
	bool rightResult = tree_query2(tree, rightTreeIndex, mid+1, r, mid+1, queryR);

	if (leftResult==true && rightResult==true)
		return true;
	else
		return false;
}

bool SegmentTree2_query(SegmentTree2 *st, int queryL, int queryR) {
	if (queryL < 0 || queryL >= st->data_size || queryR < 0 || queryR >= st->data_size) {
		printf("Index is illegal\n");
		exit(EXIT_FAILURE);
	}
	return tree_query2(st->tree, 0, 0, st->data_size - 1, queryL, queryR);
}

void step34_test(SegmentTree2 *st)
{
	printf("[");
	for (int i = 0; i < st->data_size * 4; i++) {
		//if ((int)st->tree[i] >=0)//这里本该写成st->tree[i]!=NULL的，但是对于C语言来说0就是NULL，NULL就是0.而加上(int)的原因是要将S强制转换为int，不然会有0、1和2明明大于-10，但是输出为NULL的情况
		printf("%d", st->tree[i]);

		if (i != st->data_size * 4 - 1)
			printf(", ");
	}
	printf("]\n");
}

//start
int maxEvents(int** events, int eventsSize, int* eventsColSize) {
	//step 1
	int max = events[0][1];
	for (int i = 0; i < eventsSize; i++)
	{
		if (events[i][1] > max)
			max = events[i][1];
	}
	int *EventAccount = malloc(sizeof(int)*max);
	int *CurrentEvents = malloc(sizeof(int)*max);
	memset(EventAccount, 0, sizeof(int)*max);
	printf("max=%d\n", max);
	for (int i = 0; i < eventsSize; i++) {
		int start = events[i][0] - 1;
		int end = events[i][1];
		for (int j = start; j < end; j++)
			EventAccount[j] += 1;
	}
	//step 1--test 
	// for(int i=0;i<max;i++)
	//     printf("%d ",EventAccount[i]);
	// printf("\n");

	for (int i = 0; i < max; i++)
		CurrentEvents[i] = EventAccount[i];

	//step 2
	int ***IntervalIndex = (int***)malloc(sizeof(int**)*max);
	for (int i = 0; i < max; i++)
	{
		IntervalIndex[i] = (int**)malloc(sizeof(int*)*EventAccount[i]);
		for (int j = 0; j < EventAccount[i]; j++)
		{
			IntervalIndex[i][j] = (int*)malloc(sizeof(int) * 2);
			memset(IntervalIndex[i][j], -1, sizeof(int) * 2);
		}

	}



	for (int i = 0; i < eventsSize; i++) {
		int start = events[i][0] - 1;//(1,2)->(0,2)
		int end = events[i][1];
		for (int j = start; j < end; j++)
		{
			int k = toNoneValue(IntervalIndex,j,max);
			//printf("j=%d,k=%d,start=%d,end=%d\n",j,k,start,end);
			IntervalIndex[j][k][0] = start;//(0,1)
			IntervalIndex[j][k][1] = end - 1;//(0,1)
		}

	}

	//step-2--test
	/*
	for(int i=0;i<max;i++)
	{
		 printf("day:%d\n",i+1);
         for(int j=0;j< EventAccount[i];j++)
         {
	       if(IntervalIndex[i][j][0]>=0)
             printf("[%d,%d]\n",IntervalIndex[i][j][0],IntervalIndex[i][j][1]);
         }
	 }*/

	SegmentTree2 *st = create_segmentTree2(EventAccount, max);
	

	//step46
	int ret = 0;
	int min_events_day,min_day;
	while (true) {
		min_events_day = 100000;
		min_day = 100000;
		for (int i = 0; i < max; i++)
		{
			if (CurrentEvents[i] < min_events_day && CurrentEvents[i]>0)
			{
				min_events_day = CurrentEvents[i];
				min_day = i;
			}
		}

		if (min_events_day == 100000)
			break;
		int events = EventAccount[min_day];
		for (int i = 0; i < events; i++)
		{
			int start = IntervalIndex[min_day][i][0];
			int end = IntervalIndex[min_day][i][1];
			if (SegmentTree2_query(st, start, end)==true)
			{
				for (int j = start; j < end + 1; j++)
					CurrentEvents[j]--;
				refresh(st, CurrentEvents, max);
				step34_test(st);
				ret++;
			}
			else
				continue;
		}
	}

	printf("ret=%d\n", ret);

	//release IntervalIndex
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < EventAccount[i]; j++)
		{
			free(IntervalIndex[i][j]);
			IntervalIndex[i][j] = NULL;
		}
		free(IntervalIndex[i]);
		IntervalIndex[i] = NULL;
	}

	//release EventAccount & CurrentEvents
	free(EventAccount);
	free(CurrentEvents);
	CurrentEvents = NULL;
	EventAccount = NULL;

	//release segmenttree
	free(st->tree);
	free(st->data);
	st->tree = NULL;
	st->data = NULL;
	free(st);
	st = NULL;

	if (ret > max)
		return max;
	else
		return ret;
}
#endif