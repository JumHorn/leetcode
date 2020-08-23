#include <vector>
using namespace std;

class Solution
{
public:
	bool containsCycle(vector<vector<char>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> newgrid(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				newgrid[i][j] = grid[i][j] - 'a';
		}
		int count = 30, base = 30;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (newgrid[i][j] < 30)
				{
					if (dfs(newgrid, newgrid[i][j], base, base, count, i, j))
						return true;
					base = ++count;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<int>> &grid, int c, int base, int old, int &count, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return false;
		if (grid[row][col] >= base && grid[row][col] - old >= 4)
			return true;
		if (grid[row][col] != c)
			return false;
		grid[row][col] = ++count;
		return dfs(grid, c, base, grid[row][col], count, row - 1, col) || dfs(grid, c, base, grid[row][col], count, row + 1, col) || dfs(grid, c, base, grid[row][col], count, row, col - 1) || dfs(grid, c, base, grid[row][col], count, row, col + 1);
	}
};