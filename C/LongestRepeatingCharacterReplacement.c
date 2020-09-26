#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int characterReplacement(char *s, int k)
{
	int N = strlen(s), res = 0;
	int dp[26][k + 1], next_dp[26][k + 1];
	memset(next_dp, 0, sizeof(next_dp));
	for (int i = 0; i < N; ++i)
	{
		memcpy(dp, next_dp, sizeof(dp));
		memset(next_dp, 0, sizeof(next_dp));
		for (int j = 0; j < 26; ++j)
		{
			if (s[i] - 'A' != j)
			{
				for (int l = 0; l < k; ++l)
				{
					next_dp[j][l + 1] = max(next_dp[j][l + 1], dp[j][l] + 1);
					res = max(res, next_dp[j][l + 1]);
				}
			}
			else
			{
				for (int l = 0; l <= k; ++l)
				{
					next_dp[j][l] = max(next_dp[j][l], dp[j][l] + 1);
					res = max(res, next_dp[j][l]);
				}
			}
		}
	}
	return res;
}