#include <string.h>

int numDistinct(char *s, char *t)
{
	int M = strlen(s), N = strlen(t);
	long dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < M; ++i)
		dp[i][0] = 1;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (s[i] == t[j])
				dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
			else
				dp[i + 1][j + 1] = dp[i][j + 1];
		}
	}
	return dp[M][N];
}