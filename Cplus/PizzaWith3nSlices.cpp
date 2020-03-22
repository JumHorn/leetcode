#include <vector>
using namespace std;

class Solution
{
public:
	int maxSizeSlices(vector<int>& slices)
	{
		int n = slices.size() / 3;
		return max(maxSubsequenceSum(vector<int>(slices.begin(), slices.end() - 1), n), maxSubsequenceSum(vector<int>(slices.begin() + 1, slices.end()), n));
	}

	int maxSubsequenceSum(vector<int> v, int n)
	{
		int len = v.size();
		vector<vector<int>> dp(len + 2, vector<int>(n + 1));
		for (int i = 2; i <= len + 1; i++)
		{
			for (int j = 1; j <= n; j++)
				dp[i][j] = max(dp[i - 1][j], v[i - 2] + dp[i - 2][j - 1]);
		}
		return dp[len + 1][n];
	}
};
