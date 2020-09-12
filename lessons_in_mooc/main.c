#include "Array.h"
#include "448.h"
#include <string.h>
#include "665.h"
#include "189.h"
#include "ArrayStack.h"
#include "155.h"
#include "LoopQueue.h"
#include "ArrayQueue.h"
#include"457.h"
#include "LinkedList.h"
#include "LinkedListStack.h"
#include "LinkedListQueue.h"
#include "203.h"
#include "BST.h"

#include <time.h>
#include "804.h"
#include "1309.h"
#include "MaxHeap.h"
#include "SortMethod.h"
#include <windows.h>
#include "973.h"
#include "SegmentTree.h"
typedef struct TestMap TestMap;
struct TestMap {
	int k;
	int v;
};

double testHeap(Array* testData, int length,bool isHeapify) {
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	double interval;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);

	MaxHeap *maxHeap;
	if (isHeapify)
		maxHeap = create_maxheap_with_array(retData(testData), length);
	else {
		maxHeap = create_maxheap(length);
		for (int i = 0; i < length; i++)
			MaxHeap_add(maxHeap, get(testData, i));
	}
	release_maxheap(maxHeap);

	QueryPerformanceCounter(&end);
	interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

	return interval;
	

}

double testSortTime(int *arr, int size,int mode) {
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	double interval;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	switch(mode) {
		case 1:bubble_sort(arr, size); break;
		case 2:quick_sort(arr, 0, size - 1); break;
	}

	QueryPerformanceCounter(&end);
	interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

	return interval;
}

int main() {
	/*ArrayStack
	ArrayStack *stack = NULL;
	stack = creat_array_stack(5);
	int i;
	for (i = 0;i<5;i++) {
		push(stack, i);
		arrayStack_toString(stack);
	}
	pop(stack);
	arrayStack_toString(stack);
	release_array_stack(stack);*/

	/*Array
	Array *array = NULL;
	array = create_array(10);
	int i;
	for (i = 0; i < 10; i++) {
		addLast(array, i);
	}
	add(array, 1, 100);
	array_toString(array);
	
	remove_in_array(array, 0);
	array_toString(array);
	release_array(array);*/

	/*448
	int i,*nums = (int*)malloc(8 * sizeof(int)),*returnSize;
	nums[0] = 4;
	nums[1] = 3;
	nums[2] = 2;
	nums[3] = 7;
	nums[4] = 8;
	nums[5] = 2;
	nums[6] = 3;
	nums[7] = 1;
	
	int returnLength = 2;
	returnSize = &returnLength;

	int *re = findDisappearedNumbers(nums, 8, returnSize);
	for (i = 0; i < 2; i++)
	{
		printf("%d\n", re[i]);
	}


	free(nums);
	nums = NULL;*/

	/*665
	int *nums = (int*)malloc(4 * sizeof(int));
	nums[0] = 3;
	nums[1] = 4;
	nums[2] = 2;
	nums[3] = 3;


	printf("%d", checkPossibility(nums, 4));
	free(nums);
	nums = NULL;
	*/
	/*189
	int numsSize = 7, nums[numsSize] = {1,2,3,4,5,6,7};
	rotate(nums, numsSize, 3);
	for (int i = 0; i < numsSize; i++)
		printf("%d,",nums[i]);*/


	/*155
	MinStack *minStack = minStackCreate();
	minStackPush(minStack,-2);
	minStackPush(minStack,0);
	minStackPush(minStack,-3);
	StringStack(minStack);//toString
	printf("%d\n",minStackGetMin(minStack)); // return -3
	minStackPop(minStack);
	printf("%d\n",minStackTop(minStack));    // return 0
	StringStack(minStack);//toString
	minStackFree(minStack);*/

	/*ArrayQueue
	#include "ArrayQueue.h"
	ArrayQueue *queue = create_array_queue(10);
	int i;
	for (i = 0; i < 10; i++) {
		ArrayQueue_enqueue(queue, i);
		arrayQueue_toString(queue);
		if (i % 3 == 2) {
			ArrayQueue_dequeue(queue);
			arrayQueue_toString(queue);
		}
	}
	release_array_queue(queue);*/

	/*LoopQueue
	
	LoopQueue *queue = create_loop_queue(10);
	int i;
	for (i = 0; i < 10; i++) {
		LoopQueue_enqueue(queue, i);//使用的时候只能删除ArrayQueue.h和ArrayQueue.c,因为在这两个文件已经定义了Queue.h中声明的方法
		loopQueue_toString(queue);
		if (i % 3 == 2) {
			LoopQueue_dequeue(queue);
			loopQueue_toString(queue);
		}
	}
	release_loop_queue(queue);*/

	/*457
	int numsSize = 10, *arr = (int*)malloc(numsSize * sizeof(int));
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 1;
	arr[5] = 1;
	arr[6] = 1;
	arr[7] = 1;
	arr[8] = 1;
	arr[9] = -5;



	printf("%d",circularArrayLoop(arr, numsSize));
	free(arr);
	arr = NULL;*/
	
	/*LinkedList
	LinkedList *ll = create_linked_list();
	for (int i = 0; i < 5; i++) {
		linkedList_addFirst(ll,i);
		linkedList_toString(ll);
	}
	linkedList_add(ll, 2, 666);
	linkedList_toString(ll);
	
	linkedList_removeElement(ll, 666);
	linkedList_toString(ll);

	release_linked_list(ll);*/

	/*LinkedListStack
	LinkedListStack *lls = create_linked_list_stack();
	for (int i = 0; i < 5; i++) {
		linkedListStack_push(lls,i);
		linkedListStack_toString(lls);
	}
	linkedListStack_pop(lls);
	linkedListStack_toString(lls);
	release_linked_list_stack(lls);*/


	/*LinkedListQueue
	LinkedListQueue *queue = create_linked_list_queue();
	for (int i = 0; i < 10; i++) {
		linkedListQueue_enqueue(queue, i);
		linkedListQueue_toString(queue);
		if (i % 3 == 2) {
			linkedListQueue_dequeue(queue);
			linkedListQueue_toString(queue);
		}
	}
	release_linked_list_queue(queue);*/
	

	/*203
struct ListNode* head=malloc(sizeof(struct ListNode));
head->val = 1;
head->next = NULL;
addElements(head, 2);
addElements(head, 6);
addElements(head, 3);
addElements(head, 4);
addElements(head, 5);
addElements(head, 6);

removeElements(head, 6);
release_listNode(head);*/


/*BST

BST *bst = create_BST();
int array[6] = { 5,3,6,8,4,2 };
for (int i = 0; i < 6; i++)
	BST_add(bst, array[i]);
BST_toString(bst);
printf("----------------------------\n");
printf("%d\n",BST_removeMax(bst));
BST_toString(bst);
printf("----------------------------\n");
BST_add(bst, 8);
printf("%d\n", BST_removeMaxNR(bst));
BST_toString(bst);
release_BST(bst);*/

	/*804
	char *input[4] = { "gin", "zen", "gig", "msg" };
	printf("%d\n", uniqueMorseRepresentations(input, 4));*/

	/*1309
	char *s = "10#11#12";
	char *re = freqAlphabets(s);
	printf("%s\n", re);*/

	/*strcat不能放字符
	char *s = "123";
	char a[3] = {0};
	char *b = "b\0";
	a[0] = s[0] - '0' + 'a';
	//printf("%c", re);
	//strcat(a,b);
	char test[100] = { 0 };
	test[0] = 'a';//test[0] = "a";test[0]是d
	printf("test:%s",test);*/
	
	/*MaxHeap
	int arr[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand()%100+1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("after sorting \n");
	bubble_sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	MaxHeap *mh = create_maxheap(10);
	for (int i = 0; i < 10; i++) {
		MaxHeap_add(mh, arr[i]);
	}
	printf("MaxHeap-size=%d\n", MaxHeap_getSize(mh));
	printf("adding into Heap finished.\n");
	int arr2[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr2[i] = MaxHeap_extractMax(mh);
		printf("%d\n", arr2[i]);
	}
	for (int i = 1; i < 10; i++) {
		if (arr2[i - 1] < arr2[i])
		{
			printf("error");
			break;
		}
	}
	printf("Test MaxHeap completed.");
	release_maxheap(mh);*/

	/*MaxHeap-heapify
	int n = 1000;
	Array *testData1 = create_array(n);
	
	for (int i = 0; i < n; i++)
	{
		add(testData1,i,rand() % n + 1);
		for (int j = 0; j < i; j++)
		{
			if (get(testData1,i) == get(testData1,j))
			{
				i--;
			}
		}
	}
	Array *testData2 = create_array_with_array(retData(testData1), n);
	
	double time1 = testHeap(testData1,n, false);
	printf("Without heapify: %f s\n", time1);
	double time2 = testHeap(testData2,n, true);
	printf("With heapify: %f s", time2);

	release_array(testData1);
	release_array(testData2);*/


	/*973
int **ret = malloc(sizeof(int)*2);
for (int i = 0; i < 1; i++)
	ret[i] = malloc(sizeof(int) * 2);
ret[0][0] = 1;
ret[0][1] = 3;
ret[1][0] = -2;
ret[1][1] = 2;
int *pointsColSize=NULL, *returnSize=NULL,** returnColumnSizes=NULL;
kClosest(ret, 2, pointsColSize, 1, returnSize, returnColumnSizes);
for (int i = 0; i < 2; i++)
	free(ret[i]);
free(ret);*/


/*test quick sort
	int n = 10;
	int array[10];
	
	for (int i = 0; i < n; i++) {
		srand(i);
		array[i] = rand() % 100 + 1;
	}

	
	quick_sort(array, 0, n - 1);
	printf("after sorting \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", array[i]);
	}
	*/

/*Bubblesort vs  Quicksort
int n = 10000;
int array[10000];

for (int i = 0; i < n; i++) {
	srand(i);
	array[i] = rand() % 20000 + 1;
}
printf("%f\n", testSortTime(array, n, 1));
printf("%f\n", testSortTime(array, n, 2));*/


/*SegmentTree.h*/
int nums[6] = { -2,0,3,-5,2,-1 };
SegmentTree *st = create_segmentTree(nums, 6);
SegmentTree_toString(st);

printf("%d\n", SegmentTree_query(st, 0, 2));
printf("%d\n", SegmentTree_query(st, 2, 5));

release_SegmentTree(st);
	return 0;
}