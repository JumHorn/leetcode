#include <string.h>

/*
dp[i][k] accumulate [0,k] inverse pairs until index i
*/

int kInversePairs(int n, int k)
{
	static const int MOD = 1e9 + 7;
	if (k == 0)
		return 1;
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i)
		dp[i][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= i)
				dp[i][j] = (dp[i][j - 1] + (dp[i - 1][j] + MOD - dp[i - 1][j - i]) % MOD) % MOD;
			else
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	return (dp[n][k] + MOD - dp[n][k - 1]) % MOD;
}