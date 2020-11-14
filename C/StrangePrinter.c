#include <string.h>

int strangePrinter(char *s)
{
	if (!*s)
		return 0;
	int N = strlen(s);
	int dp[N + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
		dp[i][i] = 1;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			dp[i][j] = dp[i + 1][j] + 1;
			for (int k = i + 1; k <= j; ++k)
			{
				if (s[i] == s[k] && dp[i][j] > dp[i][k - 1] + dp[k + 1][j])
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j];
			}
		}
	}
	return dp[0][N - 1];
}