#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestPalindromeSubseq(char* s)
{
	int N = strlen(s);
	int dp[N][N];
	memset(dp, 0, sizeof(dp));
	for (int i = N - 1; i >= 0; --i)
	{
		dp[i][i] = 1;
		for (int j = i + 1; j < N; ++j)
		{
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][N - 1];
}
