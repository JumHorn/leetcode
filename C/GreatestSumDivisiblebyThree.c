#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSumDivThree(int* nums, int numsSize)
{
	int dp[] = {0, 0, 0}, pre_dp[3];
	for (int i = 0; i < numsSize; ++i)
	{
		memcpy(pre_dp, dp, sizeof(dp));
		for (int j = 0; j < 3; ++j)
			dp[(pre_dp[j] + nums[i]) % 3] = max(dp[(pre_dp[j] + nums[i]) % 3], pre_dp[j] + nums[i]);
	}
	return dp[0];
}
