#include <vector>
using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>> &grid)
	{
		int res = 0;
		for (int i = 0; i < (int)grid.size(); i++)
		{
			for (int j = 0; j < (int)grid[0].size(); j++)
				res += dfs(grid, i, j);
		}
		return res;
	}

	int dfs(vector<vector<char>> &grid, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return 0;
		if (grid[row][col] != '1')
			return 0;
		grid[row][col] = '0';
		int path[] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(grid, row + path[i], col + path[i + 1]);
		return 1;
	}
};