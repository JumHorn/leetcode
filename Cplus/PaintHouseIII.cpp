#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
	{
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));
		int res = memdp(houses, cost, m, n, 0, 0, target, dp);
		return res >= 1e9 ? -1 : res;
	}

	int memdp(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int precolor, int index, int target, vector<vector<vector<int>>> &dp)
	{
		if (index >= m)
			return target == 0 ? 0 : 1e9;
		if (target < 0)
			return 1e9;
		if (dp[index][target][precolor] != -1)
			return dp[index][target][precolor];
		int res = 1e9;
		if (houses[index] != 0)
		{
			if (index == 0 || houses[index] != precolor)
				res = min(res, memdp(houses, cost, m, n, houses[index], index + 1, target - 1, dp));
			else
				res = min(res, memdp(houses, cost, m, n, houses[index], index + 1, target, dp));
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (index == 0 || i + 1 != precolor)
					res = min(res, memdp(houses, cost, m, n, i + 1, index + 1, target - 1, dp) + cost[index][i]);
				else
					res = min(res, memdp(houses, cost, m, n, precolor, index + 1, target, dp) + cost[index][i]);
			}
		}
		dp[index][target][precolor] = res;
		return res;
	}
};