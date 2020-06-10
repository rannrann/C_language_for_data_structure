#ifndef _OBJ_H_B
#define _OBJ_H_B

#include <stdlib.h>
bool checkPossibility(int* nums, int numsSize) {
	int i, mark, repeat, j, isRepeat = 0;
	if (numsSize == 1) return true;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] != nums[i - 1])
			break;
		if (i == numsSize - 1)
			return true;
		else
			continue;
	}
	for (i = 1; i < numsSize; i++) {
		if (nums[i] < nums[i - 1]) {
			mark = i;
			for (j = i + 1; j < numsSize; j++)
			{
				if (nums[j] < nums[j - 1])
					return false;
			}
			if (numsSize <= 3 || mark == numsSize - 1)
				return true;
			else
				break;
		}
		if (i == numsSize - 1)
			return true;
	}


	//下面是只有一个拐点和无拐点的情况
	//判断有没有重复数字。有，进行下面的判断；没有，还要进行一系列判断
	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[j] == nums[i]) {
				isRepeat++;
				break;
			}
		}
		if (isRepeat > 0)
			break;
		else {

			if (i == numsSize - 2)
			{
				int arr1[numsSize - 1], arr2[numsSize - 1];
				for (i = 0, j = 0; i < numsSize; i++, j++) {
					if (i != mark - 1)
						arr1[j] = nums[i];
					else
					{
						i++;
						arr1[j] = nums[i];
					}
				}
				for (i = 0, j = 0; i < numsSize; i++, j++) {
					if (i != mark)
						arr2[j] = nums[i];
					else
					{
						i++;
						arr2[j] = nums[i];
					}
				}

				for (i = 1; i < numsSize - 1; i++) {
					if (arr1[i] < arr1[i - 1])
						break;
					else
					{
						if (i == numsSize - 2)
							return true;
					}
				}
				for (i = 1; i < numsSize - 1; i++) {
					if (arr2[i] < arr2[i - 1])
						break;
					else
					{
						if (i == numsSize - 2)
							return true;
					}
				}
				return false;

			}
			else
				continue;
		}
	}
	//这是既是拐点，又是重复的情况
	for (i = 0; i < numsSize; i++) {
		if (i != mark && nums[i] == nums[mark])
		{
			if (mark > 1 && nums[mark - 2] > nums[mark + 1])
				return false;
			return true;
		}

	}
	//以下是拐点和重复是不同元素的情况
	//考虑拐点在数组尾部的情况
	if (mark == numsSize - 1) {
		if (nums[numsSize - 2] == nums[numsSize - 3])
		{
			repeat = nums[numsSize - 3];
			for (i = numsSize - 4; i > 0; i--) {
				if (nums[i] != repeat) {
					for (j = 0; j < i; j++) {
						if (nums[j] == repeat)
							return false;
					}
					return true;
				}
			}

		}
		else {
			return false;
		}
	}
	else if (mark == 1) {
		if (nums[0] == nums[2]) {
			repeat = nums[0];
			for (i = 3; i < numsSize; i++) {
				if (nums[i] != repeat) {
					for (j = i + 1; j < numsSize; j++) {
						if (nums[j] == repeat)
							return false;
					}
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else {
		if (nums[mark - 1] == nums[mark + 1]) {
			repeat = nums[mark - 1];
			for (i = mark - 2; i > 0; i--) {
				if (nums[i] != repeat) {
					if (i == 0)
						return true;
					else {
						for (j = i - 1; j > 0; j--) {
							if (nums[j] == repeat)
								return false;
						}
					}
				}
			}
			for (i = mark + 2; i < numsSize; i++) {
				if (nums[i] != repeat) {
					if (i == numsSize - 1)
						return true;
					else {
						for (j = i + 1; j < numsSize; j++)
							if (nums[j] == repeat)
								return false;
					}
				}
			}
			return true;
		}
		else {
			return false;
		}
	}

	return true;
}



#endif