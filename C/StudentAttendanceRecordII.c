#include <string.h>
/*
state (absent,late)

		 A		P		L
(0,0)	(1,0)	(0,0)	(0,1)
(0,1)	(1,0)	(0,0)	(0,2)
(0,2)	(1,0)	(0,0)	X
(1,0)	X		(1,0)	(1,1)
(1,1)	X		(1,0)	(1,2)
(1,2)	X		(1,0)	X
*/

int checkRecord(int n)
{
	static const int MOD = 1e9 + 7;
	long dp[6] = {0};
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		long next_dp[6] = {0};
		next_dp[0] = (dp[0] + dp[1] + dp[2]) % MOD;
		next_dp[1] = dp[0];
		next_dp[2] = dp[1];
		next_dp[3] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % MOD;
		next_dp[4] = dp[3];
		next_dp[5] = dp[4];
		memcpy(dp, next_dp, sizeof(dp));
	}
	int res = 0;
	for (int i = 0; i < 6; ++i)
		res = (res + dp[i]) % MOD;
	return res;
}