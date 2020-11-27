#include <string.h>

int numOfArrays(int n, int m, int k)
{
	static const int MOD = 1e9 + 7;
	int dp[n][k + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; ++i)
		dp[0][1][i] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			for (int l = 1; l <= m; ++l)
			{
				dp[i][j][l] = (dp[i][j][l] + (long)dp[i - 1][j][l] * l) % MOD;
				for (int t = l + 1; t <= m && j < k; ++t)
					dp[i][j + 1][t] = (dp[i][j + 1][t] + dp[i - 1][j][l]) % MOD;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= m; ++i)
		res = (res + dp[n - 1][k][i]) % MOD;
	return res;
}