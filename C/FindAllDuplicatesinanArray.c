#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * numsSize / 2);
	*returnSize = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		int index = abs(nums[i]) - 1;
		nums[index] = -nums[index];
		if (nums[index] > 0)
			res[(*returnSize)++] = abs(nums[i]);
	}
	return res;
}
