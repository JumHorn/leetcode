#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int trapRainWater(vector<vector<int>> &heightMap)
	{
		int M = heightMap.size(), N = heightMap[0].size();
		if (M <= 2 || N <= 2)
			return 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<vector<int>> seen(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			q.push({heightMap[i][0], i * N + 0});
			q.push({heightMap[i][N - 1], i * N + N - 1});
			seen[i][0] = seen[i][N - 1] = 1;
		}
		for (int j = 1; j < N - 1; ++j)
		{
			q.push({heightMap[0][j], 0 * N + j});
			q.push({heightMap[M - 1][j], (M - 1) * N + j});
			seen[0][j] = seen[M - 1][j] = 1;
		}
		int res = 0, curMinHeight = 0;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			curMinHeight = max(curMinHeight, top.first);
			for (int i = 0; i < 4; ++i)
			{
				int x = top.second / N + path[i], y = top.second % N + path[i + 1];
				if (x < 0 || x >= M || y < 0 || y >= N || seen[x][y] == 1)
					continue;
				seen[x][y] = 1;
				res += max(curMinHeight - heightMap[x][y], 0);
				q.push({heightMap[x][y], x * N + y});
			}
		}
		return res;
	}
};