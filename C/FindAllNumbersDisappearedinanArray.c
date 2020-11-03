#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
	for (int i = 0; i < numsSize; ++i)
	{
		int index = abs(nums[i]) - 1; // index start from 0
		nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
	}
	int *res = (int *)malloc(sizeof(int) * (numsSize));
	*returnSize = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > 0)
			res[(*returnSize)++] = i + 1;
	}
	return res;
}
