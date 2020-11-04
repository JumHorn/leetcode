#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxAreaOfIsland(vector<vector<int>> &grid)
	{
		if (grid.empty() || grid[0].empty())
			return 0;
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				res = max(res, dfs(grid, i, j));
		}
		return res;
	}

	int dfs(vector<vector<int>> &grid, int r, int c)
	{
		int M = grid.size(), N = grid[0].size();
		if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] == 0)
			return 0;
		grid[r][c] = 0;
		int res = 1;
		int path[] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			res += dfs(grid, r + path[i], c + path[i + 1]);
		return res;
	}
};