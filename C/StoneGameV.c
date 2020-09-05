#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int stoneGameV(int *stoneValue, int stoneValueSize)
{
	int N = stoneValueSize;
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	int prefixsum[N + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < N; ++i)
		prefixsum[i + 1] = prefixsum[i] + stoneValue[i];
	for (int n = 1; n < N; ++n)
	{
		for (int i = 0, j = n; j < N; ++i, ++j)
		{
			for (int k = i; k < j; ++k)
			{
				int L = prefixsum[k + 1] - prefixsum[i], R = prefixsum[j + 1] - prefixsum[k + 1];
				if (L >= R)
					dp[i][j] = max(dp[i][j], dp[k + 1][j] + R);
				if (L <= R)
					dp[i][j] = max(dp[i][j], dp[i][k] + L);
			}
		}
	}
	return dp[0][N - 1];
}