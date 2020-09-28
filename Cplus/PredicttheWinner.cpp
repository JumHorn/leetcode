#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	bool PredictTheWinner(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<int>> dp(N + 1, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			dp[i][i] = nums[i];
			for (int j = i + 1; j < N; ++j)
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		}
		return dp[0][N - 1] >= 0;
	}
};