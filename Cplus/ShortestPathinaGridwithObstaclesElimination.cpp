#include <queue>
#include <vector>
using namespace std;

class Solution
{
	struct info
	{
		int x; //pos x
		int y; //pos y
		int k;
		int step;
		info(int row = 0, int col = 0, int _k = 0, int _step = 0) : x(row), y(col), k(_k), step(_step)
		{
		}
	};

public:
	int shortestPath(vector<vector<int>> &grid, int k)
	{
		int M = grid.size(), N = grid[0].size();
		if (k >= M + N - 1)
			return M + N - 2;
		vector<vector<vector<int>>> seen(M, vector<vector<int>>(N, vector<int>(k + 1, 5000)));
		queue<info> q;
		q.push(info(0, 0, k, 0));
		int res = 0;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				const info top = q.front();
				q.pop();
				int path[5] = {-1, 0, 1, 0, -1};
				for (int i = 0; i < 4; ++i)
				{
					int dx = top.x + path[i], dy = top.y + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N)
						continue;
					int dk = top.k - grid[dx][dy];
					if (dk >= 0 && top.step + 1 < seen[dx][dy][dk])
					{
						seen[dx][dy][dk] = top.step + 1;
						if (dx == M - 1 && dy == N - 1)
							return res;
						q.push(info(dx, dy, dk, top.step + 1));
					}
				}
			}
		}
		return -1;
	}
};