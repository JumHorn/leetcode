#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMaximumGold(vector<vector<int>>& grid)
	{
		int res = 0, m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] != 0)
					res = max(res, recursive(grid, i, j));
			}
		return res;
	}

	int recursive(vector<vector<int>>& grid, int i, int j)
	{
		int res = 0, m = grid.size(), n = grid[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
			return res;
		int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int k = 0; k < 4; k++)
		{
			int tmp = grid[i][j];
			grid[i][j] = 0;
			int x = i + direction[k][0], y = j + direction[k][1];
			res = max(res, recursive(grid, x, y) + tmp);
			grid[i][j] = tmp;
		}
		return res;
	}
};
