#include <string.h>

bool isScramble(char *s1, char *s2)
{
	int size = strlen(s1);
	if (size == 0)
		return true;
	bool dp[size][size][size + 1];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			dp[i][j][1] = (s1[i] == s2[j]);
	}
	for (int len = 2; len <= size; len++)
	{
		for (int i = 0; i <= size - len; i++)
			for (int j = 0; j <= size - len; j++)
			{
				dp[i][j][len] = false;
				for (int k = 1; k < len && !dp[i][j][len]; k++)
				{
					dp[i][j][len] = dp[i][j][len] || (dp[i][j][k] && dp[i + k][j + k][len - k]);
					dp[i][j][len] = dp[i][j][len] || (dp[i + len - k][j][k] && dp[i][j + k][len - k]);
				}
			}
	}
	return dp[0][0][size];
}