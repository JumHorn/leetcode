#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<vector<int>> &grid)
	{
		int res = 0, n = grid.size();
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					q.push({i, j});
			}
		}
		if ((int)q.size() == n * n)
			return -1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int x = q.front().first, y = q.front().second;
				q.pop();
				if (x - 1 >= 0 && grid[x - 1][y] == 0)
				{
					grid[x - 1][y] = res;
					q.push({x - 1, y});
				}
				if (x + 1 < n && grid[x + 1][y] == 0)
				{
					grid[x + 1][y] = res;
					q.push({x + 1, y});
				}
				if (y - 1 >= 0 && grid[x][y - 1] == 0)
				{
					grid[x][y - 1] = res;
					q.push({x, y - 1});
				}
				if (y + 1 < n && grid[x][y + 1] == 0)
				{
					grid[x][y + 1] = res;
					q.push({x, y + 1});
				}
			}
		}
		return res - 1;
	}
};
