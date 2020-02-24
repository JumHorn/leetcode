#include <vector>
using namespace std;

class Solution
{
public:
	int numRollsToTarget(int d, int f, int target)
	{
		vector<vector<int>> dp(d, vector<int>(target + 1));
		for (int i = 1; i <= f; i++)
		{
			if (i > target)
				break;
			dp[0][i] = 1;
		}
		for (int i = 1; i < d; i++)
		{
			for (int j = 1; j <= target; j++)
			{
				for (int k = 1; k <= f; k++)
				{
					if (k >= j)
						break;
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
				}
			}
		}
		return dp[d - 1][target];
	}

private:
	static const int MOD = 1e9 + 7;
};
