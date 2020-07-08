#ifndef _OBJ_H_FOUR_FIVE_SEVEN_
#define _OBJ_H_FOUR_FIVE_SEVEN_

bool circularArrayLoop(int* nums, int numsSize) {
	int i, j = 0, steps;
	for (i = 0; i < numsSize; i++) {
		steps = 0;
		if (nums[i] % numsSize == 0) continue;
		for (j = (i + nums[i]) % numsSize; steps <= numsSize; j = (j + nums[j]) % numsSize, steps++) {
			if (j < 0)j = numsSize + j;
			if (nums[j] * nums[i] < 0) break;
			if (nums[j] % numsSize == 0) break;
			if (j == i) return true;
		}
	}
	return false;
}
#endif