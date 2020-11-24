#include <string.h>

int countVowelPermutation(int n)
{
	static const int MOD = 1e9 + 7;
	long dp[5]; // a e i o u
	for (int i = 0; i < 5; ++i)
		dp[i] = 1;
	for (int i = 1; i < n; ++i)
	{
		long pre_dp[5];
		memcpy(pre_dp, dp, sizeof(dp));
		//a
		dp[0] = (pre_dp[1] + pre_dp[2] + pre_dp[4]) % MOD;
		//e
		dp[1] = (pre_dp[0] + pre_dp[2]) % MOD;
		//i
		dp[2] = (pre_dp[1] + pre_dp[3]) % MOD;
		//o
		dp[3] = pre_dp[2];
		//u
		dp[4] = (pre_dp[2] + pre_dp[3]) % MOD;
	}
	int res = 0;
	for (int i = 0; i < 5; ++i)
		res = (res + dp[i]) % MOD;
	return res;
}