#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
	{
		unordered_set<int> seen;
		dfs(grid, r0, c0, grid[r0][c0], -1, seen);
		for (int i = 0; i < (int)grid.size(); i++)
			for (int j = 0; j < (int)grid[0].size(); j++)
				if (grid[i][j] == -1)
					grid[i][j] = color;
		return grid;
	}

	void dfs(vector<vector<int>> &grid, int i, int j, int oldcolor, int color, unordered_set<int> &seen)
	{
		int m = grid.size(), n = grid[0].size();
		if (seen.find(i * n + j) != seen.end())
			return;
		seen.insert(i * n + j);
		bool flag = false;
		if (i - 1 >= 0 && (grid[i - 1][j] == oldcolor || grid[i - 1][j] == -1))
			dfs(grid, i - 1, j, oldcolor, color, seen);
		else
			flag = true;
		if (i + 1 < m && (grid[i + 1][j] == oldcolor || grid[i + 1][j] == -1))
			dfs(grid, i + 1, j, oldcolor, color, seen);
		else
			flag = true;
		if (j - 1 >= 0 && (grid[i][j - 1] == oldcolor || grid[i][j - 1] == -1))
			dfs(grid, i, j - 1, oldcolor, color, seen);
		else
			flag = true;
		if (j + 1 < n && (grid[i][j + 1] == oldcolor || grid[i][j + 1] == -1))
			dfs(grid, i, j + 1, oldcolor, color, seen);
		else
			flag = true;

		if (flag)
			grid[i][j] = color;
	}
};
