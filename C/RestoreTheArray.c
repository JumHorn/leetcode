#include <string.h>

int numberOfArrays(char* s, int k)
{
	static const int MOD = 1e9 + 7;
	int N = strlen(s);
	int dp[N + 1];
	memset(dp, 0, sizeof(dp));
	dp[N] = 1;
	for (int i = N - 1; i >= 0; --i)
	{
		if (s[i] == '0')
			continue;
		long val = s[i] - '0';
		for (int j = i; j < N && val <= k; ++j)
		{
			dp[i] = (dp[i] + dp[j + 1]) % MOD;
			val = val * 10 + s[j + 1] - '0';
		}
	}
	return dp[0];
}
