#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int wiggleMaxLength(vector<int> &nums)
	{
		int N = nums.size();
		if (nums.empty())
			return 0;
		vector<vector<int>> dp(N, vector<int>(2)); //{up,down}
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
			}
			else if (nums[i] > nums[i - 1])
			{
				dp[i][0] = dp[i - 1][1] + 1;
				dp[i][1] = dp[i - 1][1];
			}
			else
			{
				dp[i][1] = dp[i - 1][0] + 1;
				dp[i][0] = dp[i - 1][0];
			}
		}
		return max(dp[N - 1][0], dp[N - 1][1]);
	}
};