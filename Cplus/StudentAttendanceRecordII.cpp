#include <vector>
using namespace std;

class Solution
{
public:
	int checkRecord(int n)
	{
		int MOD = 1e9 + 7;
		int dp[2][3];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
				dp[i][j] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			int dp1[2][3] = {0};
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					int val = dp[j][2];
					if (j > 0)
						val = (val + dp[j - 1][2]) % MOD;
					if (k > 0)
						val = (val + dp[j][k - 1]) % MOD;
					dp1[j][k] = val;
				}
			}
			memcpy(dp, dp1, sizeof(dp));
		}
		return dp[1][2];
	}
};