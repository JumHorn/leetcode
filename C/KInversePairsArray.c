#include <string.h>

int kInversePairs(int n, int k)
{
	static const int MOD = 1e9 + 7;
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int size = j;
			if (size > i)
				size = i;
			for (int m = 0; m <= size; m++)
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - m]) % MOD;
		}
	}
	return dp[n][k];
}