#include <string.h>

int combinationSum4(int* nums, int numsSize, int target)
{
	unsigned int dp[target + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i <= target; ++i)
	{
		for (int j = 0; j < numsSize; ++j)
		{
			if (i >= nums[j])
				dp[i] += dp[i - nums[j]];
		}
	}
	return dp[target];
}
