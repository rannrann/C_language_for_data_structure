#include "Array.h"
#include "448.h"
#include <string.h>
#include "665.h"
#include "189.h"
#include "ArrayStack.h"
#include "155.h"

#include "LoopQueue.h"
#include"457.h"

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
	int numsSize=4,*nums = (int*)malloc(numsSize * sizeof(int)),i;
	nums[0] = -1;
	nums[1] = -100;
	nums[2] = 3;
	nums[3] = 99;
	rotate(nums, numsSize, 2);
	for (i = 0; i < numsSize; i++)
		printf("%d,",nums[i]);
	free(nums);
	nums = NULL;*/

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
		enqueue(queue, i);
		arrayQueue_toString(queue);
		if (i % 3 == 2) {
			dequeue(queue);
			arrayQueue_toString(queue);
		}
	}
	release_array_queue(queue);*/
	/*LoopQueue
	LoopQueue *queue = create_loop_queue(10);
	int i;
	for (i = 0; i < 10; i++) {
		enqueue(queue, i);//使用的时候要隐藏#include "ArrayQueue.h"，因为ArrayQueue和LoopQueue都继承可Queue。C语言对于不同对象的相同方法名不能区分
		loopQueue_toString(queue);
		if (i % 3 == 2) {
			dequeue(queue);
			loopQueue_toString(queue);
		}
	}
	release_loop_queue(queue);*/

	/*457*/
	int numsSize = 7, *arr = (int*)malloc(numsSize * sizeof(int));
	arr[0] = 2;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 2;
	arr[5] = 4;
	arr[6] = 7;


	printf("%d",circularArrayLoop(arr, numsSize));
	free(arr);
	arr = NULL;

	return 0;

}