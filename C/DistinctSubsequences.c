#include <string.h>

int numDistinct(char* s, char* t)
{
	int len1 = strlen(s), len2 = strlen(t);
	long dp[len1 + 1][len2 + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len1; i++)
		dp[i][0] = 1;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (s[i] == t[j])
				dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
			else
				dp[i + 1][j + 1] = dp[i][j + 1];
		}
	}
	return dp[len1][len2];
}
