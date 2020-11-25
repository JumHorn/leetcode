#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minInsertions(char *s)
{
	int N = strlen(s);
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	for (int i = N - 2; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	return dp[0][N - 1];
}