#include <vector>
using namespace std;

class Solution
{
public:
	bool hasValidPath(vector<vector<char>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(M + N)));
		if (grid[0][0] == ')')
			return false;
		return backTracking(grid, 0, 0, 1, dp);
	}

	bool backTracking(vector<vector<char>> &grid, int row, int col, int count, vector<vector<vector<int>>> &dp)
	{
		//board dfs direction
		int path[][2] = {{1, 0}, {0, 1}};
		int M = grid.size(), N = grid[0].size();
		if (row == M - 1 && col == N - 1)
			return count == 0;
		if (dp[row][col][count] != 0)
			return false;
		for (int i = 0; i < 2; ++i)
		{
			int dx = row + path[i][0], dy = col + path[i][1];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			{
				if (grid[dx][dy] == '(')
				{
					if (backTracking(grid, dx, dy, count + 1, dp))
						return true;
				}
				else
				{
					if (count >= 1 && backTracking(grid, dx, dy, count - 1, dp))
						return true;
				}
			}
		}
		dp[row][col][count] = 1;
		return false;
	}
};