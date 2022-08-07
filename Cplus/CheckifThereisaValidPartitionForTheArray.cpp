#include <vector>
using namespace std;

class Solution
{
public:
	bool validPartition(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> dp(N + 1);
		dp[0] = 1;
		for (int i = 0; i < N; ++i)
		{
			if (i >= 1)
			{
				if (nums[i] == nums[i - 1])
					dp[i + 1] |= dp[i - 1];
			}
			if (i >= 2)
			{
				if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
					dp[i + 1] |= dp[i - 2];
				if (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
					dp[i + 1] |= dp[i - 2];
			}
		}
		return dp[N];
	}
};