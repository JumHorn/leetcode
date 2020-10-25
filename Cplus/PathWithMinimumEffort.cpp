#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumEffortPath(vector<vector<int>> &heights)
	{
		int M = heights.size(), N = heights[0].size();
		priority_queue<pair<int, int>> q; //{effort,position}
		vector<vector<int>> seen(M, vector<int>(N, INT_MAX));
		seen[0][0] = 0;
		q.push({0, 0});
		while (!q.empty())
		{
			int x = q.top().second / N, y = q.top().second % N;
			int effort = -q.top().first;
			q.pop();
			if (x == M - 1 && y == N - 1)
				return effort;
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx < 0 || dx >= M || dy < 0 || dy >= N)
					continue;
				int curEffort = abs(heights[x][y] - heights[dx][dy]);
				curEffort = max(curEffort, effort);
				if (curEffort < seen[dx][dy])
				{
					seen[dx][dy] = curEffort;
					q.push({-curEffort, dx * N + dy});
				}
			}
		}
		return -1;
	}
};