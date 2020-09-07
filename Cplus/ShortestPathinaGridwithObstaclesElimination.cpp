#include <queue>
#include <vector>
using namespace std;

class Solution
{
	struct info
	{
		int i;
		int j;
		int k;
		int step;
		info(int _i = 0, int _j = 0, int _k = 0, int _step = 0) : i(_i), j(_j), k(_k), step(_step)
		{
		}
	};

public:
	int shortestPath(vector<vector<int>> &grid, int k)
	{
		int m = grid.size(), n = grid[0].size();
		if (k >= m + n - 1)
			return m + n - 2;
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>((k + 1), 5000)));
		queue<info> q;
		q.push(info(0, 0, k, 0));
		int res = 0;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				const info top = q.front();
				q.pop();
				int path[5] = {-1, 0, 1, 0, -1};
				for (int i = 0; i < 4; ++i)
				{
					int dx = top.i + path[i], dy = top.j + path[i + 1];
					if (dx < 0 || dx >= m || dy < 0 || dy >= n)
						continue;
					int dk = top.k - grid[dx][dy];
					if (dk >= 0 && top.step + 1 < dp[dx][dy][dk])
					{
						dp[dx][dy][dk] = top.step + 1;
						if (dx == m - 1 && dy == n - 1)
							return res;
						q.push(info(dx, dy, dk, top.step + 1));
					}
				}
			}
		}
		return -1;
	}
};