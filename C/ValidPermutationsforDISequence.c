#include <string.h>

int numPermsDISequence(char *S)
{
	static const int MOD = 1e9 + 7;
	int N = strlen(S);
	int dp[N + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (S[i - 1] == 'D')
			{
				for (int k = j; k < i; ++k)
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
			else
			{
				for (int k = 0; k < j; ++k)
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= N; ++i)
		res = (res + dp[N][i]) % MOD;
	return res;
}