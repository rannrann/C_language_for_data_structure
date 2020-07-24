#ifndef _OBJ_H_FOUR_FIVE_SEVEN_
#define _OBJ_H_FOUR_FIVE_SEVEN_
/*bool circularArrayLoop(int* nums, int numsSize) {
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
}*/
/*方法二：快慢指针*/
int getNext(int* nums, int i, int numsSize) {
	return ((i + nums[i]) % numsSize + numsSize) % numsSize;
}

bool circularArrayLoop(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		int slow = i, fast = getNext(nums, slow, numsSize), val = nums[i];
		while (val*nums[fast] > 0 && val*nums[getNext(nums, fast, numsSize)] > 0) {
			if (slow == fast) {
				if (nums[slow] % numsSize == 0)
					break;
				return true;
			}
			slow = getNext(nums, slow, numsSize);
			fast = getNext(nums, getNext(nums, fast, numsSize), numsSize);
		}
		while (val*nums[slow] > 0) {
			nums[slow] = 0;
			slow = getNext(nums, slow, numsSize);
		}
	}
	return false;
}

#endif