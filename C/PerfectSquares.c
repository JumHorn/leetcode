#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int numSquares(int n)
{
	int dp[n + 1];
	memset(dp, 1 << 6, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2, j; i <= n; ++i)
	{
		for (j = 1; j * j < i; ++j)
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		if (j * j == i)
			dp[i] = 1;
	}
	return dp[n];
}
