#include <string.h>

int countVowelPermutation(int n)
{
	static const int MOD = 1e9 + 7;
	long dp[5]; // a e i o u
	for (int i = 0; i < 5; ++i)
		dp[i] = 1;
	for (int i = 1; i < n; ++i)
	{
		long dp1[5];
		memcpy(dp1, dp, sizeof(dp));
		//a
		dp[0] = (dp1[1] + dp1[2] + dp1[4]) % MOD;
		//e
		dp[1] = (dp1[0] + dp1[2]) % MOD;
		//i
		dp[2] = (dp1[1] + dp1[3]) % MOD;
		//o
		dp[3] = dp1[2];
		//u
		dp[4] = (dp1[2] + dp1[3]) % MOD;
	}
	int res = 0;
	for (int i = 0; i < 5; ++i)
		res = (res + dp[i]) % MOD;
	return res;
}
