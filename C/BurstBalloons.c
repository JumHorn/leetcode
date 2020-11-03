#include <string.h>

/*
dp[i][j] the max coins not include burst boundary i and j
dp[i][j] = max{nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]} (i<k<j)
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxCoins(int *nums, int numsSize)
{
	int n = numsSize + 2;
	int dp[n][n], dup[n];
	for (int i = 0; i < numsSize; ++i)
		dup[i + 1] = nums[i];
	dup[0] = dup[n - 1] = 1;
	memset(dp, 0, sizeof(dp));
	for (int len = 2; len < n; len++)
	{
		for (int i = 0; i < n - len; ++i)
		{
			int j = i + len;
			for (int k = i + 1; k < j; k++)
				dp[i][j] = max(dp[i][j], dup[i] * dup[k] * dup[j] + dp[i][k] + dp[k][j]);
		}
	}
	return dp[0][n - 1];
}