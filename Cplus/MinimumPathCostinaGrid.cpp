#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
		for (int j = 0; j < N; ++j)
			dp[0][j] = grid[0][j];
		for (int i = 1; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int k = 0; k < N; ++k)
					dp[i][k] = min(dp[i][k], moveCost[grid[i - 1][j]][k] + dp[i - 1][j] + grid[i][k]);
			}
		}
		return *min_element(dp[M - 1].begin(), dp[M - 1].end());
	}
};