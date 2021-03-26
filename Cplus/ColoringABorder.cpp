#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
	{
		set<pair<int, int>> seen;
		dfs(grid, r0, c0, grid[r0][c0], color, seen);
		return grid;
	}

	int dfs(vector<vector<int>> &grid, int row, int col, int oldcolor, int color, set<pair<int, int>> &seen)
	{
		int M = grid.size(), N = grid[0].size();
		if (seen.find({row, col}) != seen.end())
			return 1;
		if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != oldcolor)
			return 0;
		seen.insert({row, col});
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		int res = 0;
		for (int i = 0; i < 4; ++i)
			res += dfs(grid, row + path[i], col + path[i + 1], oldcolor, color, seen);
		if (res < 4)
			grid[row][col] = color;
		return 1;
	}
};