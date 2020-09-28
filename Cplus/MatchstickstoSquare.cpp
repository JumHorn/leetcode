#include <numeric>
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
		vector<vector<int>> dp(1 << nums.size(), vector<int>(4));
		return backTracking(nums, sidelen, 0, 0, dp);
	}

	bool backTracking(vector<int> &nums, int sidelen, int sideformed, int mask, vector<vector<int>> &dp)
	{
		if (dp[mask][sideformed] != 0)
			return dp[mask][sideformed] == 1;
		int N = nums.size(), perimeter = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((mask & (1 << i)) != 0)
				perimeter += nums[i];
		}
		if (perimeter > 0 && perimeter % sidelen == 0)
			++sideformed;
		if (sideformed == 3)
			return true;

		//not finish side len
		int len = sidelen - (perimeter - perimeter / sidelen * sidelen);
		for (int i = 0; i < N; ++i)
		{
			if ((mask & (1 << i)) == 0)
			{
				if (nums[i] <= len)
				{
					if (backTracking(nums, sidelen, sideformed, mask | (1 << i), dp))
					{
						dp[mask][sideformed] = 1;
						return true;
					}
				}
			}
		}
		dp[mask][sideformed] = -1;
		return false;
	}
};