#include <stdbool.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

bool backTracking(int *nums, int numsSize, int index, int sum)
{
	if (sum == 0)
		return true;
	if (sum < 0)
		return false;
	for (int i = index; i < numsSize; ++i)
	{
		if (backTracking(nums, numsSize, i + 1, sum - nums[i]))
			return true;
	}
	return false;
}

bool canPartition(int *nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
		sum += nums[i];
	if (sum & 1)
		return false;
	qsort(nums, numsSize, sizeof(int), cmp);
	if (nums[0] * 2 > sum)
		return false;
	return backTracking(nums, numsSize, 0, sum / 2);
}