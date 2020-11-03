#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define trimin(a, b, c) (min(min(a, b), c))

int minDistance(char *word1, char *word2)
{
	int len1 = strlen(word1), len2 = strlen(word2);
	int dp[len1 + 1][len2 + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len1; ++i)
		dp[i + 1][0] = dp[i][0] + 1;
	for (int j = 0; j < len2; j++)
		dp[0][j + 1] = dp[0][j] + 1;
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; j++)
		{
			if (word1[i] == word2[j])
				dp[i + 1][j + 1] = dp[i][j];
			else
				dp[i + 1][j + 1] = trimin(dp[i + 1][j], dp[i][j + 1], dp[i][j]) + 1;
		}
	}
	return dp[len1][len2];
}
