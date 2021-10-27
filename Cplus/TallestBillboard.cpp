#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int tallestBillboard(vector<int> &rods)
	{
		unordered_map<int, int> dp; //{diff,height of short rod}
		dp[0] = 0;
		for (auto r : rods)
		{
			unordered_map<int, int> pre_dp(dp);
			for (auto &n : pre_dp)
			{
				dp[n.first + r] = max(dp[n.first + r], n.second); //add to higher side
				int delta = r >= n.first ? n.first : r;
				dp[abs(n.first - r)] = max(dp[abs(n.first - r)], n.second + delta); //add to lower side
			}
		}
		return dp[0];
	}
};