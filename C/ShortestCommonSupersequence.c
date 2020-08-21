#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char *shortestCommonSupersequence(char *str1, char *str2)
{
	int M = strlen(str1), N = strlen(str2);
	int dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	int i = M - 1, j = N - 1, k = M + N - dp[M][N];
	char *res = (char *)malloc(sizeof(char) * (k + 1));
	res[k--] = '\0';
	while (i >= 0 || j >= 0)
	{
		if (i < 0 || j < 0)
			res[k--] = i >= 0 ? str1[i--] : str2[j--];
		else if (str1[i] == str2[j])
		{
			res[k--] = str1[i];
			--i;
			--j;
		}
		else
			res[k--] = dp[i][j + 1] > dp[i + 1][j] ? str1[i--] : str2[j--];
	}
	return res;
}