#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
	int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
	if (len1 + len2 != len3)
		return false;
	if (!*s1)
		return strcmp(s2, s3) == 0;
	if (!*s2)
		return strcmp(s1, s3) == 0;
	bool dp[len1 + 1][len2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i < len1 && s1[i] == s3[i]; i++)
		dp[i + 1][0] = true;
	for (int j = 0; j < len2 && s2[j] == s3[j]; j++)
		dp[0][j + 1] = true;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
			dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) || (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
	}
	return dp[len1][len2];
}
