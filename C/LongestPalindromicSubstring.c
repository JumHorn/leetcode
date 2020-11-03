#include <stdbool.h>
#include <string.h>

char *longestPalindrome(char *s)
{
	int n = strlen(s);
	if (n == 0)
		return "";
	bool dp[n][n];
	for (int i = 0; i < n; ++i)
		dp[i][i] = true;
	for (int i = 0; i < n - 1; ++i)
		dp[i][i + 1] = (s[i] == s[i + 1]);
	for (int len = 2; len < n; len++)
	{
		for (int i = 0, j = len; j < n; i++, j++)
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
	}

	char *res = NULL;
	int len = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; j++)
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
