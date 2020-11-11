#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *largestDivisibleSubset(int *nums, int numsSize, int *returnSize)
{
	if (numsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	int dp[numsSize];
	memset(dp, 0, sizeof(dp));
	int len = 1, index = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] % nums[j] == 0)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		dp[i] = max(dp[i], 1);
		if (len < dp[i])
		{
			len = dp[i];
			index = i;
		}
	}
	*returnSize = len;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = index; i >= 0; --i)
	{
		if (len == dp[i] && nums[index] % nums[i] == 0)
		{
			res[--len] = nums[i];
			index = i;
		}
	}
	return res;
}