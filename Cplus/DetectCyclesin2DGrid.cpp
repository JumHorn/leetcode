#include <vector>
using namespace std;

class Solution
{
public:
	bool containsCycle(vector<vector<char>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> seen(M, vector<int>(N));
		int mark = 1;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (seen[i][j] == 0)
				{
					if (dfs(grid, seen, -1, i, j, grid[i][j], mark))
						return true;
					++mark;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>> &grid, vector<vector<int>> &seen, int parent, int row, int col, char color, int mark)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return false;
		if (grid[row][col] != color)
			return false;
		if (seen[row][col] != 0)
			return seen[row][col] == mark;
		seen[row][col] = mark;
		bool res = false;
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
		{
			int x = row + path[i], y = col + path[i + 1];
			if (parent != x * N + y)
				res = res || dfs(grid, seen, row * N + col, x, y, color, mark);
		}
		return res;
	}
};