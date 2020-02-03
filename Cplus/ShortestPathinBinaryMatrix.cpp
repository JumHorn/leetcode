#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid)
	{
		if (grid[0][0] == 1 || grid.back().back() == 1)
			return -1;
		if (grid.size() == 1)
			return 1;
		vector<vector<int>> visited(grid.size(), vector<int>(grid.size()));
		queue<pair<int, int>> q;
		int res = 0, N = grid.size();
		int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		q.push({0, 0});
		visited[0][0] = 1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 8; i++)
				{
					int dx = x + dir[i][0], dy = y + dir[i][1];
					if (dx < 0 || dy < 0 || dx >= N || dy >= N)
						continue;
					if (visited[dx][dy] == 1 || grid[dx][dy] == 1)
						continue;
					if (dx == N - 1 && dy == N - 1)
						return res + 1;
					visited[dx][dy] = 1;
					q.push({dx, dy});
				}
			}
		}
		return -1;
	}
};
