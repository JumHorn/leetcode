#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxSumOfThreeSubarrays(int *nums, int numsSize, int k, int *returnSize)
{
	int dp[numsSize + 1][4];
	memset(dp, 0, sizeof(dp));
	int prefixsum[numsSize + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		prefixsum[i + 1] = prefixsum[i] + nums[i];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = k; j <= numsSize; ++j)
			dp[j][i + 1] = max(dp[j - 1][i + 1], dp[j - k][i] + prefixsum[j] - prefixsum[j - k]);
	}
	*returnSize = 3;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 3, j = numsSize; i >= 1; i--, j -= k)
	{
		while (dp[j][i] == dp[j - 1][i])
			--j;
		res[i - 1] = j - k;
	}
	return res;
}
