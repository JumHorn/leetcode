#include <stdbool.h>
#include <string.h>

char *longestPalindrome(char *s)
{
	int N = strlen(s);
	if (N == 0)
		return "";
	bool dp[N][N];
	for (int i = 0; i < N; ++i)
		dp[i][i] = true;
	for (int i = 0; i < N - 1; ++i)
		dp[i][i + 1] = (s[i] == s[i + 1]);
	for (int i = N - 3; i >= 0; --i)
	{
		for (int j = i + 2; j < N; ++j)
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
	}

	char *res = NULL;
	int len = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (dp[i][j] && len < j - i + 1)
			{
				len = j - i + 1;
				res = &s[i];
			}
		}
	}
	res[len] = '\0';
	return res;
}