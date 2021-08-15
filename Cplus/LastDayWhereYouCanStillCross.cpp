#include <vector>
using namespace std;

class Solution
{
public:
	int latestDayToCross(int row, int col, vector<vector<int>> &cells)
	{
		int N = cells.size();
		int lo = 0, hi = N;
		vector<vector<int>> grid(row, vector<int>(col));
		while (lo < hi)
		{
			for (auto &v : grid)
				fill(v.begin(), v.end(), 0);
			int mi = (hi - lo) / 2 + lo;
			color(grid, cells, mi, 1);
			if (check(grid))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	void color(vector<vector<int>> &grid, vector<vector<int>> &cells, int index, int val)
	{
		int N = cells.size();
		for (int i = 0; i < index; ++i)
		{
			grid[cells[i][0] - 1][cells[i][1] - 1] = val;
		}
	}

	bool check(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		for (int i = 0; i < N; ++i)
		{
			if (grid[0][i] == 0 && dfs(grid, 0, i))
				return true;
		}
		return false;
	}

	bool dfs(vector<vector<int>> &grid, int r, int c)
	{
		int M = grid.size(), N = grid[0].size();
		if (r < 0 || r >= M || c < 0 || c >= N)
			return false;
		if (grid[r][c] == 1)
			return false;
		if (r == M - 1)
			return true;
		grid[r][c] = 1;
		return dfs(grid, r - 1, c) || dfs(grid, r + 1, c) || dfs(grid, r, c - 1) || dfs(grid, r, c + 1);
	}
};