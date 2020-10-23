#include <string.h>

int dieSimulator(int n, int* rollMax, int rollMaxSize)
{
	static const int MOD = 1e9 + 7;
	int faces = rollMaxSize;
	long dp[n + 1][faces + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][faces] = 1;
	for (int i = 0; i < faces; ++i)
		dp[1][i] = 1;
	dp[1][faces] = faces;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < faces; ++j)
		{
			for (int k = 1; k <= rollMax[j] && i - k >= 0; ++k)
				dp[i][j] = (dp[i][j] + dp[i - k][faces] - dp[i - k][j] + MOD) % MOD;
			dp[i][faces] = (dp[i][faces] + dp[i][j]) % MOD;
		}
	}
	return dp[n][faces];
}
