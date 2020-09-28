#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool makesquare(vector<int> &nums)
	{
		if (nums.empty())
			return false;
		int perimeter = accumulate(nums.begin(), nums.end(), 0);
		if (perimeter % 4 != 0)
			return false;
		int sidelen = perimeter / 4;
		vector<unordered_map<int, bool>> dp(1 << nums.size());
		return backTracking(nums, sidelen, perimeter, 0, dp);
	}

	bool backTracking(vector<int> &nums, int sidelen, int perimeter, int mask, vector<unordered_map<int, bool>> &dp)
	{
		if (perimeter == 0)
			return true;
		//not finish side len
		if (dp[mask].find(perimeter) != dp[mask].end())
			return dp[mask][perimeter];
		int len = perimeter - perimeter / sidelen * sidelen;
		if (len == 0)
			len = sidelen;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if ((mask & (1 << i)) == 0)
			{
				if (nums[i] <= len)
				{
					if (backTracking(nums, sidelen, perimeter - nums[i], mask ^ (1 << i), dp))
						return dp[mask][perimeter] = true;
				}
			}
		}
		return dp[mask][perimeter] = false;
	}
};