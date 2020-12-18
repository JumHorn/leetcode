#include <stdbool.h>
#include <string.h>

//knapsack

bool canPartition(int *nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
		sum += nums[i];
	if (sum & 1)
		return false;
	bool dp[sum / 2 + 1][numsSize + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= numsSize; ++i)
		dp[0][i] = true;
	for (int i = 1; i <= sum / 2; ++i)
	{
		for (int j = 0; j < numsSize; ++j)
			dp[i][j + 1] = dp[i][j] || (nums[j] <= i && dp[i - nums[j]][j]);
	}
	return dp[sum / 2][numsSize];
}