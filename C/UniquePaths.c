#include <string.h>

int uniquePaths(int m, int n)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			dp[j + 1] += dp[j];
		dp[0] = 0;
	}
	return dp[n];
}