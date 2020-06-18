#include "Array.h"
#include "448.h"
#include <string.h>
#include "665.h"
#include "189.h"

int main() {
	
	Array *array = NULL;
	array = create_array(10);
	int i;
	for (i = 0; i < 10; i++) {
		addLast(array, i);
	}
	add(array, 1, 100);
	toString(array);
	
	remove_in_array(array, 0);
	toString(array);
	release_array(array);
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
	return 0;
}