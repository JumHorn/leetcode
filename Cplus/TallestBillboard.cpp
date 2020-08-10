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
		unordered_map<int, int> dp; //{diff,height}
		dp[0] = 0;
		for (auto r : rods)
		{
			unordered_map<int, int> tmp(dp);
			for (auto &n : tmp)
			{
				dp[n.first + r] = max(dp[n.first + r], tmp[n.first]); //add to higher side
				int delta = r >= n.first ? n.first : r;
				dp[abs(n.first - r)] = max(dp[abs(n.first - r)], tmp[n.first] + delta); //add to lower side
			}
		}
		return dp[0];
	}
};