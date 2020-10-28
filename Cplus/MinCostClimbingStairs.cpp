#include <algorithm>
#include <vector>
using namespace std;

/*
dp[i]=min(dp[i-1],dp[i-2])+cost[i]
*/

class Solution
{
public:
	int minCostClimbingStairs(vector<int> &cost)
	{
		int dp1 = 0, dp2 = 0;
		for (int i = 0; i < (int)cost.size(); ++i)
		{
			int dp3 = min(dp1, dp2) + cost[i];
			dp1 = dp2;
			dp2 = dp3;
		}
		return min(dp1, dp2);
	}
};