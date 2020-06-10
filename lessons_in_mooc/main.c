#include "Array.h"
#include "448.h"
#include <string.h>
#include "665.h"

int main() {
	/*
	Array *array = NULL;
	array = create_array(10);
	int i;
	for (i = 0; i < 10; i++) {
		addLast(array, i);
	}
	add(array, 1, 100);
	toString(array);
	
	remove_in_array(array, 0);
	toString(array);*/
	
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

	int *nums = (int*)malloc(7 * sizeof(int));
	nums[0] = 1;
	nums[1] = 5;
	nums[2] = 4;
	nums[3] = 6;
	nums[4] = 7;
	nums[5] = 8;
	nums[6] = 9;

	printf("%d", checkPossibility(nums, 7));
	free(nums);
	nums = NULL;
	return 0;
}