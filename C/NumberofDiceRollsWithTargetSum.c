#include <string.h>

int numRollsToTarget(int d, int f, int target)
{
	static const int MOD = 1e9 + 7;
	int dp[d][target + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= f && i <= target; ++i)
		dp[0][i] = 1;
	for (int i = 1; i < d; ++i)
	{
		for (int j = 1; j <= target; ++j)
		{
			for (int k = 1; k <= f && k < j; ++k)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
		}
	}
	return dp[d - 1][target];
}
