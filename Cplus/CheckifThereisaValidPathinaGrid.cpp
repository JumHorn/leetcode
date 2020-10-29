#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	bool hasValidPath(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		int path[][6][2] = {
			{{0, -1}, {0, 1}},
			{{-1, 0}, {1, 0}},
			{{0, -1}, {1, 0}},
			{{0, 1}, {1, 0}},
			{{0, -1}, {-1, 0}},
			{{0, 1}, {-1, 0}}};
		queue<pair<int, int>> q; //{postion,path}
		q.push({0, grid[0][0]});
		grid[0][0] = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int x = q.front().first / N, y = q.front().first % N;
				int d = q.front().second - 1;
				q.pop();
				if (x == M - 1 && y == N - 1)
					return true;
				for (int i = 0; i < 2; ++i)
				{
					int dx = x + path[d][i][0], dy = y + path[d][i][1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N || grid[dx][dy] == 0)
						continue;
					for (int i = 0; i < 2; ++i) //check back to {x,y}
					{
						int index = grid[dx][dy] - 1;
						if (dx + path[index][i][0] == x && dy + path[index][i][1] == y)
						{
							q.push({dx * N + dy, grid[dx][dy]});
							grid[dx][dy] = 0;
							break;
						}
					}
				}
			}
		}
		return false;
	}
};