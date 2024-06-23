#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumTotalCost(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<long long>> dp(N, vector<long long>(2, INT_MIN)); //{postive,negative} sign of nums[i]
		dp[0][0] = dp[0][1] = nums[0];
		for (int i = 1; i < N; ++i)
		{
			dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - 1][1]) + nums[i]);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] - nums[i]);
		}
		return max(dp[N - 1][0], dp[N - 1][1]);
	}
};