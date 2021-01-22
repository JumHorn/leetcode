#include <string.h>

/*
dp[k][N] means minimal number with k substring in [0,N]
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))

int palindromePartition(char *s, int k)
{
	int N = strlen(s);
	if (k >= N)
		return 0;
	int palindrome[N][N];
	memset(palindrome, 0, sizeof(palindrome));
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
			palindrome[i][j] = palindrome[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
	}

	int dp[k][N];
	memset(dp, 1u << 6, sizeof(dp));
	memcpy(dp[0], palindrome[0], sizeof(dp[0]));
	for (int i = 0; i < k - 1; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int n = i + 1; n <= j; ++n)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][n - 1] + palindrome[n][j]);
		}
	}
	return dp[k - 1][N - 1];
}