#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int connectTwoGroups(vector<vector<int>> &cost)
	{
		int size1 = cost.size(), size2 = cost[0].size(), bitmask = (1 << size2) - 1;
		vector<vector<int>> dp(size1 + 1, vector<int>(bitmask + 1, INT_MAX / 2));
		dp[0][0] = 0;
		for (int i = 0; i < size1; ++i)
		{
			for (int mask = 0; mask <= bitmask; ++mask)
			{
				for (int j = 0; j < size2; ++j)
					dp[i + 1][mask | 1 << j] = min(dp[i + 1][mask | 1 << j], dp[i][mask] + cost[i][j]);
			}
		}
		vector<int> mincost(size2, INT_MAX);
		for (int i = 0; i < size1; ++i)
		{
			for (int j = 0; j < size2; ++j)
				mincost[j] = min(mincost[j], cost[i][j]);
		}
		int res = INT_MAX;
		for (int i = 0; i <= bitmask; ++i)
		{
			int val = dp[size1][i];
			for (int j = 0; j < size2; ++j)
			{
				if (((1 << j) & i) == 0)
					val += mincost[j];
			}
			res = min(res, val);
		}
		return res;
	}
};