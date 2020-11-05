#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProductPath(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<vector<long>>> dp(M, vector<vector<long>>(N, vector<long>(2)));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == 0 && j == 0)
					dp[i][j][0] = dp[i][j][1] = grid[0][0];
				else if (i == 0)
					dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i][j - 1][0];
				else if (j == 0)
					dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i - 1][j][0];
				else
				{
					long a = grid[i][j] * max(dp[i][j - 1][0], dp[i - 1][j][0]);
					long b = grid[i][j] * min(dp[i][j - 1][1], dp[i - 1][j][1]);
					dp[i][j][0] = max(a, b);
					dp[i][j][1] = min(a, b);
				}
			}
		}
		return dp[M - 1][N - 1][0] < 0 ? -1 : dp[M - 1][N - 1][0] % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};