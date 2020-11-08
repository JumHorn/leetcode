#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
	int N1 = strlen(s1), N2 = strlen(s2), N3 = strlen(s3);
	if (N1 + N2 != N3)
		return false;
	if (!*s1)
		return strcmp(s2, s3) == 0;
	if (!*s2)
		return strcmp(s1, s3) == 0;
	bool dp[N1 + 1][N2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i < N1 && s1[i] == s3[i]; ++i)
		dp[i + 1][0] = true;
	for (int j = 0; j < N2 && s2[j] == s3[j]; ++j)
		dp[0][j + 1] = true;
	for (int i = 0; i < N1; ++i)
	{
		for (int j = 0; j < N2; ++j)
			dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) ||
							   (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
	}
	return dp[N1][N2];
}