#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int palindromePartition(char* s, int k)
{
	int N = strlen(s);
	int dp[k][N][N];
	if (k >= N)
		return 0;
	memset(dp, 0, sizeof(dp));
	for (int n = 0; n < N; ++n)
	{
		for (int i = 0, j = n; j < N; ++i, ++j)
		{
			if (i == j)
				dp[0][i][j] = 0;
			else
				dp[0][i][j] = dp[0][i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
		}
	}

	for (int m = 1; m < k; ++m)
	{
		for (int n = 1; n < N; ++n)
		{
			for (int i = 0, j = n; j < N; ++i, ++j)
			{
				dp[m][i][j] = N;
				for (int l = i; l < j; ++l)
					dp[m][i][j] = min(dp[m][i][j], dp[0][i][l] + dp[m - 1][l + 1][j]);
			}
		}
	}
	return dp[k - 1][0][N - 1];
}
