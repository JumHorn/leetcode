#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int numWays(int steps, int arrLen)
{
	static const int MOD = 1e9 + 7;
	int N = min(steps / 2 + 1, arrLen);
	int dp[N], dp_copy[N];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < steps; ++i)
	{
		memset(dp_copy, 0, sizeof(dp_copy));
		for (int j = 0; j < N; ++j)
		{
			for (int k = max(0, j - 1); k <= min(N - 1, j + 1); ++k)
				dp_copy[j] = (dp_copy[j] + dp[k]) % MOD;
		}
		memcpy(dp, dp_copy, sizeof(dp));
	}
	return dp[0];
}