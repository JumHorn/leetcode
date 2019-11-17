#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
	int len1 = strlen(s), len2 = strlen(p);
	bool** dp = (bool**)malloc((len2 + 1) * sizeof(bool*));
	for (int i = 0; i <= len2; i++)
	{
		dp[i] = (bool*)malloc((len1 + 1) * sizeof(bool));
		memset(dp[i], 0, sizeof(bool) * (len1 + 1));
	}
	dp[0][0] = true;
	for (int i = 0; i < len2; i++)
		if (p[i] == '*' && dp[i - 1][0])
			dp[i + 1][0] = true;
	for (int i = 0; i < len2; i++)
		for (int j = 0; j < len1; j++)
		{
			if (p[i] == '.' || p[i] == s[j])
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[i] == '*')
			{
				if (p[i - 1] == '.' || p[i - 1] == s[j])
					dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i - 1][j + 1];
				else
					dp[i + 1][j + 1] = dp[i - 1][j + 1];
			}
		}
	return dp[len2][len1];
}

