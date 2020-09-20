#include <vector>
using namespace std;

class Solution
{
public:
	int maxProductPath(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<vector<long>>> dp(M, vector<vector<long>>(N, vector<long>(2)));
		dp[0][0][0] = dp[0][0][1] = grid[0][0];
		for (int i = 1; i < M; ++i)
		{
			long maxval = max(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
			long minval = min(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
			dp[i][0][0] = maxval;
			dp[i][0][1] = minval;
		}
		for (int j = 1; j < N; ++j)
		{
			long maxval = max(dp[0][j - 1][0] * grid[0][j], dp[0][j - 1][1] * grid[0][j]);
			long minval = min(dp[0][j - 1][0] * grid[0][j], dp[0][j - 1][1] * grid[0][j]);
			dp[0][j][0] = maxval;
			dp[0][j][1] = minval;
		}
		for (int i = 1; i < M; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				long maxval = max(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]);
				maxval = max({maxval, dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]});

				long minval = min(dp[i - 1][j][0] * grid[i][j], dp[i - 1][j][1] * grid[i][j]);
				minval = min({minval, dp[i][j - 1][0] * grid[i][j], dp[i][j - 1][1] * grid[i][j]});

				dp[i][j][0] = maxval;
				dp[i][j][1] = minval;
			}
		}
		return dp[M - 1][N - 1][0] < 0 ? -1 : dp[M - 1][N - 1][0] % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};