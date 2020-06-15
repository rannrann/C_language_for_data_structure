#ifndef _OBJ_H_C
#define _OBJ_H_C



void rotate(int* nums, int numsSize, int k) {
	int i, count, change, j;
	for (i = 0, count = 1, j = 1; count < numsSize; count++, j++) {
		change = nums[i];
		if (i + j * k - (i + j * k) / numsSize * numsSize == i) {
			i++;
			j = 0;
			continue;
		}
		nums[i] = nums[i + j * k - (i + j * k) / numsSize * numsSize];
		nums[i + j * k - (i + j * k) / numsSize * numsSize] = change;
	}
}
#endif
