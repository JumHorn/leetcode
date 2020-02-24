#include <vector>
using namespace std;

class Solution
{
public:
	int numRollsToTarget(int d, int f, int target)
	{
		vector<vector<int>> dp(d + 1, vector<int>(target + 1, -1));
		return memdp(d, f, target, dp);
	}

	int memdp(int d, int f, int target, vector<vector<int>>& dp)
	{
		if (d == 0)
			return target == 0 ? 1 : 0;
		if (target <= 0)
			return 0;
		if (dp[d][target] != -1)
			return dp[d][target];
		int res = 0;
		for (int i = 1; i <= f; i++)
			res = (res + memdp(d - 1, f, target - i, dp) % MOD) % MOD;
		dp[d][target] = res;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
