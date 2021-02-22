#include <vector>
using namespace std;

class Solution
{
public:
	int maximumScore(vector<int> &nums, vector<int> &multipliers)
	{
		int N = nums.size(), M = multipliers.size();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		return memdp(nums, multipliers, 0, N - 1, dp);
	}

	int memdp(vector<int> &nums, vector<int> &multipliers, int first, int last, vector<vector<int>> &dp)
	{
		int N = nums.size(), M = multipliers.size();
		int index = first + N - 1 - last;
		if (index >= M)
			return 0;
		if (dp[first][last] != -1)
			return dp[first][last];
		return dp[first][last] = max(memdp(nums, multipliers, first + 1, last, dp) + nums[first] * multipliers[index],
									 memdp(nums, multipliers, first, last - 1, dp) + nums[last] * multipliers[index]);
	}
};