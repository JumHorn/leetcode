#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minInsertions(char* s)
{
	int N = strlen(s);
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	for (int n = 1; n < N; ++n)
	{
		for (int i = 0, j = n; j < N; ++i, ++j)
		{
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	return dp[0][N - 1];
}
