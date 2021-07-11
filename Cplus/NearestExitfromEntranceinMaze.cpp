#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
	{
		int res = 0, M = maze.size(), N = maze[0].size();
		int path[5] = {-1, 0, 1, 0, -1};
		queue<pair<int, int>> q;
		int x = entrance[0], y = entrance[1];
		q.push({x, y});
		maze[x][y] = '+';
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N || maze[dx][dy] == '+')
						continue;
					if (dx == 0 || dx == M - 1 || dy == 0 || dy == N - 1)
						return res;
					maze[dx][dy] = '+';
					q.push({dx, dy});
				}
			}
		}
		return -1;
	}
};