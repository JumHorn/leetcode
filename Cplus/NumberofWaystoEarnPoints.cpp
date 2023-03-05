#include <vector>
using namespace std;

class Solution
{
public:
	int waysToReachTarget(int target, vector<vector<int>> &types)
	{
		vector<int> dp(target + 1);
		dp[0] = 1;
		for (auto &t : types)
		{
			int c = t[0], m = t[1];
			vector<int> next_dp(target + 1);
			for (int i = 0; i <= target; ++i)
			{
				for (int j = 0; j <= c && i + j * m <= target; ++j)
					next_dp[i + j * m] = (next_dp[i + j * m] + dp[i]) % MOD;
			}
			dp.swap(next_dp);
		}
		return dp[target];
	}

private:
	static const int MOD = 1e9 + 7;
};