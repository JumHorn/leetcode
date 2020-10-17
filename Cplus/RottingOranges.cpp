#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int orangesRotting(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), fresh = 0, rot = 0;
		queue<int> q;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 2)
					q.push(i * N + j);
				if (grid[i][j] == 1)
					++fresh;
			}
		}
		if (fresh == 0)
			return 0;

		int res = -1;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				int i = q.front() / N, j = q.front() % N;
				q.pop();
				int path[5] = {-1, 0, 1, 0, -1};
				for (int k = 0; k < 4; ++k)
				{
					int dx = i + path[k], dy = j + path[k + 1];
					if (dx >= 0 && dx < M && dy >= 0 && dy < N && grid[dx][dy] == 1)
					{
						grid[dx][dy] = 0;
						++rot;
						q.push(dx * N + dy);
					}
				}
			}
		}
		return fresh == rot ? res : -1;
	}
};