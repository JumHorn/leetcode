#include <vector>
using namespace std;

class Solution
{
public:
	int countPaths(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		vector<vector<int>> dp(M, vector<int>(N, -1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				res = (res + memdp(grid, i, j, dp)) % MOD;
		}
		return res;
	}

	int memdp(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
	{
		if (dp[row][col] != -1)
			return dp[row][col];
		int res = 1, M = matrix.size(), N = matrix[0].size();
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int k = 0; k < 4; ++k)
		{
			int x = row + path[k], y = col + path[k + 1];
			if (x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] < matrix[row][col])
				res = (res + memdp(matrix, x, y, dp)) % MOD;
		}
		return dp[row][col] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};