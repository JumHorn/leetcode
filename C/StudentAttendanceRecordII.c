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
	for (int i = 0; i < n; i++)
	{
		long dp1[6] = {0};
		dp1[0] = (dp[0] + dp[1] + dp[2]) % MOD;
		dp1[1] = dp[0];
		dp1[2] = dp[1];
		dp1[3] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % MOD;
		dp1[4] = dp[3];
		dp1[5] = dp[4];
		memcpy(dp, dp1, sizeof(dp));
	}
	int res = 0;
	for (int i = 0; i < 6; i++)
		res = (res + dp[i]) % MOD;
	return res;
}
