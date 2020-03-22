#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int splitArray(vector<int>& nums, int m)
	{
		vector<vector<int>> dp(nums.size(), vector<int>(m + 1));
		return memdp(nums, 0, m, dp);
	}

	int memdp(vector<int>& nums, int start, int m, vector<vector<int>>& dp)
	{
		if (dp[start][m] != 0)
			return dp[start][m];
		int tmp = 0;
		if (m == 1)
		{
			for (int i = start; i < (int)nums.size(); i++)
				tmp += nums[i];
			return tmp;
		}
		int res = INT_MAX;
		for (int i = start; i <= (int)nums.size() - m; i++)
		{
			tmp += nums[i];
			res = min(res, max(memdp(nums, i + 1, m - 1, dp), tmp));
		}
		dp[start][m] = res;
		return res;
	}
};
