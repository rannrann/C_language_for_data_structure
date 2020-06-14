#ifndef _OBJ_H_B
#define _OBJ_H_B

#include <stdlib.h>
bool checkPossibility(int* nums, int numsSize) {
	int i, mark = -1, repeat, j, isRepeat = 0;
	if (numsSize == 1) return true;
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
		if (i == numsSize - 1 && mark == -1)
			return true;
	}
	if (mark != 1) {
		int arr[3];//int arr[numsSize-1]报错，但其实没错，调试时需填入明确数字
		if (nums[mark - 2] > nums[mark])
		{
			for (i = 0, j = 0; i < numsSize; i++, j++) {
				if (i == mark)
				{
					i++;
					arr[j] = nums[i];
				}
				else
					arr[j] = nums[i];
			}
		}
		else {
			for (i = 0, j = 0; i < numsSize; i++, j++) {
				if (i == mark - 1)
				{
					i++;
					arr[j] = nums[i];
				}
				else
					arr[j] = nums[i];
			}
		}
		for (i = 1; i < numsSize - 1; i++) {
			if (arr[i] < arr[i - 1])
				return false;
		}
		return true;
	}
	else
		return true;

}


#endif