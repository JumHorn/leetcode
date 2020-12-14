#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxCoins(vector<int> &nums)
	{
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		int N = nums.size();
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				for (int k = i + 1; k < j; ++k)
					dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
			}
		}
		return dp[0][N - 1];
	}
};