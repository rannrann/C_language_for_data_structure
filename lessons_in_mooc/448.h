#ifndef _OBJ_H_A
#define _OBJ_H_A

#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize,int* returnSize) {
	int *arr = (int*)malloc((numsSize + 1) * sizeof(int));
	int i, j, count = 0;
	for (i = 0; i <= numsSize; i++)
		arr[i] = 0;

	for (i = 0; i < numsSize; i++) {
		arr[nums[i]]++;
	}
	arr[0] = 1;
	for (i = 1; i <= numsSize; i++) {
		if (arr[i] == 0)
			count++;
	}
	*returnSize = count;
	int* re = (int*)malloc(count * sizeof(int));
	for (i = 0; i < count; i++) {
		re[i] = 0;
	}
	for (i = 1; i <= numsSize; i++)
	{
		if (arr[i] == 0)
		{
			for (j = 0; j < count; j++) {
				if (re[j] == 0) {
					re[j] = i;
					break;
				}
			}
		}
	}
	free(arr);
	arr = NULL;
	return re;
}
#endif
