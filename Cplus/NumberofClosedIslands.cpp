#include <vector>
using namespace std;

class Solution
{
public:
	int closedIsland(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0)
					res += dfs(grid, i, j);
			}
		}
		return res;
	}

	int dfs(vector<vector<int>> &grid, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return 0;
		if (grid[row][col] == 1)
			return 1;
		grid[row][col] = 1;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		int res = 0;
		for (int i = 0; i < 4; ++i)
			res += dfs(grid, row + path[i], col + path[i + 1]);
		return res == 4 ? 1 : 0;
	}
};