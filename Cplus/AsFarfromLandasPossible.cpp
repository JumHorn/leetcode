#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<vector<int>> &grid)
	{
		int res = 0, N = grid.size();
		queue<pair<int, int>> q;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					q.push({i, j});
			}
		}
		if ((int)q.size() == N * N)
			return -1;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				//board dfs direction
				int path[5] = {-1, 0, 1, 0, -1};
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx >= 0 && dx < N && dy >= 0 && dy < N && grid[dx][dy] == 0)
					{
						grid[dx][dy] = res;
						q.push({dx, dy});
					}
				}
			}
		}
		return res - 1;
	}
};