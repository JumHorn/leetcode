#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTime(vector<vector<int>> &grid)
	{
		if (grid[0][1] > 1 && grid[1][0] > 1)
			return -1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{time,position}
		q.push({0, 0});
		int M = grid.size(), N = grid[0].size();
		int path[] = {-1, 0, 1, 0, -1};
		vector<vector<int>> seen(M, vector<int>(N));
		while (!q.empty())
		{
			auto [t, p] = q.top();
			q.pop();
			int x = p / N, y = p % N;
			if (x == M - 1 && y == N - 1)
				return t;
			if (seen[x][y] != 0)
				continue;
			seen[x][y] = 1;
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N)
				{
					if (seen[dx][dy] == 0)
					{
						int wait = (grid[dx][dy] - t) % 2 == 0;
						q.push({max(grid[dx][dy] + wait, t + 1), dx * N + dy});
					}
				}
			}
		}
		return -1;
	}
};