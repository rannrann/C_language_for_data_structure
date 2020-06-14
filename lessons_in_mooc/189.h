#ifndef _OBJ_H_C
#define _OBJ_H_C


void rotate(int* nums, int numsSize, int k) {
	int i, change, mark;
	for (i = 0; (i + k + 1) < numsSize; i++) {
		change = nums[i];
		nums[i] = nums[i + k + 1];
		nums[i + k + 1] = change;
	}
	mark = nums[k];
	for (i = k; i < numsSize - 1; i++)
		nums[i] = nums[i + 1];
	nums[numsSize] = mark;
}
#endif
