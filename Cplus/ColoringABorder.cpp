#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
	{
		dfs(grid, r0, c0, grid[r0][c0]);
		for (auto &v : grid)
		{
			for (auto &n : v)
			{
				if (n < 0)
					n = color;
			}
		}
		return grid;
	}

	void dfs(vector<vector<int>> &grid, int row, int col, int color)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != color)
			return;
		grid[row][col] = -color;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(grid, row + path[i], col + path[i + 1], color);
		if (row > 0 && row < M - 1 && col > 0 && col < N - 1 &&
			color == abs(grid[row - 1][col]) &&
			color == abs(grid[row + 1][col]) &&
			color == abs(grid[row][col - 1]) &&
			color == abs(grid[row][col + 1]))
			grid[row][col] = color;
	}
};