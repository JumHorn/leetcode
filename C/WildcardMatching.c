#include <string.h>

#define MAXLEN 1501

bool doIsMatch(char* s, int i, char* p, int j, int (*dp)[MAXLEN])
{
	if (dp[i][j] != -1)
		return dp[i][j];
	if (!*s && !*p)
		return dp[i][j] = 1;
	if (!*p)
		return dp[i][j] = 0;
	if (!*s)
	{
		while (*p && *p == '*')
			++p;
		return !*p;
	}
	if (*p == '?' || *p == *s)
		return dp[i][j] = doIsMatch(s + 1, i + 1, p + 1, j + 1, dp);
	if (*p == '*')
		return dp[i][j] = doIsMatch(s + 1, i + 1, p, j, dp) || doIsMatch(s, i, p + 1, j + 1, dp) || doIsMatch(s + 1, i + 1, p + 1, j + 1, dp);
	return dp[i][j] = 0;
}

bool isMatch(char* s, char* p)
{
	int dp[MAXLEN][MAXLEN];
	memset(dp, -1, sizeof(dp));
	return doIsMatch(s, 0, p, 0, dp);
}
