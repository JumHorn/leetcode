#include <vector>
using namespace std;

class Solution
{
public:
	int islandPerimeter(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					res += dfs(grid, i, j);
			}
		}
		return res;
	}

	int dfs(vector<vector<int>> &grid, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] == 0)
			return 1;
		if (grid[row][col] != 1)
			return 0;
		grid[row][col] = 2;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		int res = 0;
		for (int i = 0; i < 4; ++i)
			res += dfs(grid, row + path[i], col + path[i + 1]);
		return res;
	}
};