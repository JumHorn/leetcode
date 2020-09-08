#include <vector>
using namespace std;

class Solution
{
public:
	int maxSizeSlices(vector<int> &slices)
	{
		int N = slices.size(), n = N / 3;
		return max(maxSubSlice(slices, n, 0, N - 1), maxSubSlice(slices, n, 1, N));
	}

	int maxSubSlice(vector<int> &slice, int n, int first, int last)
	{
		int N = last - first;
		vector<vector<int>> dp(N + 2, vector<int>(n + 1));
		for (int i = 0, k = first; k < last; ++i, ++k)
		{
			for (int j = 0; j < n; ++j)
				dp[i + 2][j + 1] = max(dp[i + 1][j + 1], slice[k] + dp[i][j]);
		}
		return dp[N + 1][n];
	}
};