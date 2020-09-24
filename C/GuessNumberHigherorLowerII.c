#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int getMoneyAmount(int n)
{
	int dp[n + 1][n + 1];
	memset(dp, 1 << 6, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		dp[i + 1][i + 1] = 0;
		dp[i][i + 1] = i;
	}
	for (int l = 2; l <= n; ++l)
	{
		for (int i = 0, j = l; j <= n; ++i, ++j)
		{
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
		}
	}
	return dp[1][n];
}
