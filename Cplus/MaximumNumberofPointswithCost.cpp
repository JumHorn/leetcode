#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxPoints(vector<vector<int>> &points)
	{
		int M = points.size(), N = points[0].size();
		vector<vector<long long>> dp(M, vector<long long>(N));
		for (int j = 0; j < N; ++j)
			dp[0][j] = points[0][j];
		for (int i = 1; i < M; ++i)
		{
			long long maxv = dp[i - 1][0] + 0;
			for (int j = 0; j < N; ++j)
			{
				maxv = max(maxv, dp[i - 1][j] + j);
				dp[i][j] = max(dp[i][j], maxv + points[i][j] - j);
			}

			maxv = dp[i - 1][N - 1] - N - 1;
			for (int j = N - 1; j >= 0; --j)
			{
				maxv = max(maxv, dp[i - 1][j] - j);
				dp[i][j] = max(dp[i][j], maxv + points[i][j] + j);
			}
		}
		return *max_element(dp.back().begin(), dp.back().end());
	}
};