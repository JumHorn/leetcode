#include <vector>
using namespace std;

class Solution
{
public:
	int maximumScore(vector<int> &nums, vector<int> &multipliers)
	{
		int N = nums.size(), M = multipliers.size();
		vector<vector<int>> dp(M, vector<int>(M, -1));
		return memdp(nums, multipliers, 0, 0, dp);
	}

	int memdp(vector<int> &nums, vector<int> &multipliers, int left, int index, vector<vector<int>> &dp)
	{
		int N = nums.size(), M = multipliers.size();
		if (index >= M)
			return 0;
		if (dp[left][index] != -1)
			return dp[left][index];
		return dp[left][index] = max(memdp(nums, multipliers, left + 1, index + 1, dp) + nums[left] * multipliers[index],
									 memdp(nums, multipliers, left, index + 1, dp) + nums[N - (index - left) - 1] * multipliers[index]);
	}
};