#include <vector>
using namespace std;

class Solution
{
public:
	int closedIsland(vector<vector<int>>& grid)
	{
		int res = 0, m = grid.size(), n = grid[0].size();
		for (int i = 1; i < m - 1; i++)
			for (int j = 1; j < n - 1; j++)
			{
				if (grid[i][j] == 0)
					res += dfs(grid, i, j);
			}
		return res;
	}

	int dfs(vector<vector<int>>& grid, int i, int j)
	{
		int m = grid.size(), n = grid[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n)
			return 0;
		if (grid[i][j] == 1)
			return 1;
		if (grid[i][j] == 2)
			return 1;
		grid[i][j] = 2;
		int res = 1;
		int tmp = dfs(grid, i - 1, j);
		if (res == 1)
			res = tmp;
		tmp = dfs(grid, i + 1, j);
		if (res == 1)
			res = tmp;
		tmp = dfs(grid, i, j - 1);
		if (res == 1)
			res = tmp;
		tmp = dfs(grid, i, j + 1);
		if (res == 1)
			res = tmp;
		return res;
	}
};
