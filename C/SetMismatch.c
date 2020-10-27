#include <stdlib.h>

void swap(int* lhs, int* rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < numsSize;)
	{
		if (i + 1 == nums[i] || nums[nums[i] - 1] == nums[i])
			++i;
		else
			swap(&nums[nums[i] - 1], &nums[i]);
	}
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != i + 1)
		{
			res[0] = nums[i];
			res[1] = i + 1;
			break;
		}
	}
	return res;
}
