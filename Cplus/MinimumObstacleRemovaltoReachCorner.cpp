#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumObstacles(vector<vector<int>> &grid)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{removed Obstacle,pos}
		q.push({0, 0});
		int M = grid.size(), N = grid[0].size();
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		vector<vector<int>> seen(M, vector<int>(N, INT_MAX));
		seen[0][0] = 0;
		while (!q.empty())
		{
			int obstacle = q.top().first, x = q.top().second / N, y = q.top().second % N;
			q.pop();
			if (obstacle > seen[x][y])
				continue;
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N)
				{
					if (dx == M - 1 && dy == N - 1)
						return obstacle;
					if (obstacle + grid[dx][dy] < seen[dx][dy])
					{
						seen[dx][dy] = obstacle + grid[dx][dy];
						q.push({obstacle + grid[dx][dy], dx * N + dy});
					}
				}
			}
		}
		return 0;
	}
};