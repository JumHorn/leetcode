#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestPathBinaryMatrix(vector<vector<int>> &grid)
	{
		int res = 0, N = grid.size();
		if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1)
			return -1;
		if (N == 1)
			return 1;
		int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				int x = q.front() / N, y = q.front() % N;
				q.pop();
				for (int i = 0; i < 8; ++i)
				{
					int dx = x + dir[i][0], dy = y + dir[i][1];
					if (dx < 0 || dx >= N || dy < 0 || dy >= N || grid[dx][dy] == 1)
						continue;
					grid[dx][dy] = 1;
					if (dx == N - 1 && dy == N - 1)
						return res + 1;
					q.push(dx * N + dy);
				}
			}
		}
		return -1;
	}
};