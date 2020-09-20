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
				for (int j = 1; j <= bitmask; ++j)
				{
					int costs = 0;
					for (int k = 0; k < size2; ++k)
					{
						if (j & (1 << k))
							costs += cost[i][k];
					}
					dp[i + 1][mask | j] = min(dp[i + 1][mask | j], dp[i][mask] + costs);
				}
			}
		}
		return dp[size1][bitmask];
	}
};