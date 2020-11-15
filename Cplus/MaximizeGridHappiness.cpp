#include <vector>
using namespace std;

class Solution
{
public:
	int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
	{
		vector<vector<int>> grid(m, vector<int>(n));
		return dfs(grid, 0, 0, introvertsCount, extrovertsCount, 0);
	}

	int dfs(vector<vector<int>> &grid, int row, int col, int in, int ex, int happy)
	{
		int M = grid.size(), N = grid[0].size();
		if (row == M - 1 && col == N)
			return happy;
		if (col == N)
		{
			col = 0;
			++row;
		}
		int res = dfs(grid, row, col + 1, in, ex, happy);
		if (in > 0)
		{
			grid[row][col] = 1;
			int h = happy + 120;
			if (row > 0 && grid[row - 1][col] != 0)
			{
				if (grid[row - 1][col] == 1)
					h += -30 - 30;
				else
					h += 20 - 30;
			}
			if (col > 0 && grid[row][col - 1] != 0)
			{
				if (grid[row][col - 1] == 1)
					h += -30 - 30;
				else
					h += 20 - 30;
			}
			res = max(res, dfs(grid, row, col + 1, in - 1, ex, h));
			grid[row][col] = 0;
		}
		if (ex > 0)
		{
			grid[row][col] = 2;
			int h = happy + 40;
			if (row > 0 && grid[row - 1][col] != 0)
			{
				if (grid[row - 1][col] == 1)
					h += 20 - 30;
				else
					h += 20 + 20;
			}
			if (col > 0 && grid[row][col - 1] != 0)
			{
				if (grid[row][col - 1] == 1)
					h += 20 - 30;
				else
					h += 20 + 20;
			}
			res = max(res, dfs(grid, row, col + 1, in, ex - 1, h));
			grid[row][col] = 0;
		}
		return res;
	}
};