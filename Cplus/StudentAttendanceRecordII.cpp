#include <cstring>
#include <vector>
using namespace std;

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

class Solution
{
public:
	int checkRecord(int n)
	{
		int dp[2][3] = {0};
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 3; ++j)
				dp[i][j] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			int next_dp[2][3] = {0};
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					int val = dp[j][2];
					if (j > 0)
						val = (val + dp[j - 1][2]) % MOD;
					if (k > 0)
						val = (val + dp[j][k - 1]) % MOD;
					next_dp[j][k] = val;
				}
			}
			memcpy(dp, next_dp, sizeof(dp));
		}
		return dp[1][2];
	}

private:
	static const int MOD = 1e9 + 7;
};