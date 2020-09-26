#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int characterReplacement(char *s, int k)
{
	int N = strlen(s), res = 0;
	int dp[N + 1][26][k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (s[i] - 'A' != j)
			{
				for (int l = 0; l < k; ++l)
				{
					dp[i + 1][j][l + 1] = max(dp[i + 1][j][l + 1], dp[i][j][l] + 1);
					res = max(res, dp[i + 1][j][l + 1]);
				}
			}
			else
			{
				for (int l = 0; l <= k; ++l)
				{
					dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + 1);
					res = max(res, dp[i + 1][j][l]);
				}
			}
		}
	}
	return res;
}