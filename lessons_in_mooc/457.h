#ifndef _OBJ_H_FOUR_FIVE_SEVEN_
#define _OBJ_H_FOUR_FIVE_SEVEN_

bool circularArrayLoop(int* nums, int numsSize) {
	int i, j = 0, steps;
	bool isCycle;
	for (i = 0; i < numsSize; i++) {
		steps = 0;
		isCycle = false;
		if (nums[i] % numsSize == 0) continue;
		for (j = i + nums[i]; steps <= numsSize; j = j + nums[j], steps++) {
			if (j / numsSize != 0)
			{
				isCycle = true;
				j = j % numsSize;
			}
			if (j < 0)
			{
				j = numsSize + j;
				isCycle = true;
			}
			if (nums[j] * nums[i] < 0) break;
			if (j == i && isCycle) return true;
		}
	}
	return false;
}
#endif