#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMaximumGold(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] != 0)
					res = max(res, dfs(grid, i, j));
			}
		}
		return res;
	}

	int dfs(vector<vector<int>> &grid, int row, int col)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] == 0)
			return res;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
		{
			int gold = grid[row][col];
			grid[row][col] = 0;
			res = max(res, dfs(grid, row + path[i], col + path[i + 1]) + gold);
			grid[row][col] = gold;
		}
		return res;
	}
};