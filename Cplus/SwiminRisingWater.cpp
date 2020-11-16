#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int swimInWater(vector<vector<int>> &grid)
	{
		int N = grid.size();
		priority_queue<pair<int, int>> q;
		q.push({-grid[0][0], 0});
		int res = grid[0][0], elevation = grid[0][0], dst = grid[N - 1][N - 1];
		grid[0][0] = -1;
		while (!q.empty())
		{
			if (grid[N - 1][N - 1] == -1)
				return res + max(0, dst - elevation);
			auto top = q.top();
			q.pop();
			res += -top.first - elevation;
			if (top.second == (N - 1) * (N + 1))
				return res;
			elevation = -top.first;
			dfs(grid, top.second / N, top.second % N, elevation, q);
		}
		return res;
	}

	void dfs(vector<vector<int>> &grid, int row, int column, int elevation, priority_queue<pair<int, int>> &q)
	{
		int N = grid.size();
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
		{
			int x = row + path[i], y = column + path[i + 1];
			if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == -1)
				continue;
			int height = grid[x][y];
			grid[x][y] = -1;
			if (elevation >= height)
				dfs(grid, x, y, elevation, q);
			else
				q.push({-height, x * N + y});
		}
	}
};