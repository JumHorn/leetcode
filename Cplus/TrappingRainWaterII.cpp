#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int trapRainWater(vector<vector<int>> &heightMap)
	{
		int m = heightMap.size(), n = heightMap[0].size();
		if (m <= 2 || n <= 2)
			return 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<vector<int>> seen(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			q.push({heightMap[i][0], i * n + 0});
			q.push({heightMap[i][n - 1], i * n + n - 1});
			seen[i][0] = seen[i][n - 1] = 1;
		}
		for (int j = 1; j < n - 1; j++)
		{
			q.push({heightMap[0][j], 0 * n + j});
			q.push({heightMap[m - 1][j], (m - 1) * n + j});
			seen[0][j] = seen[m - 1][j] = 1;
		}
		int res = 0, maxheight = 0;
		int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			maxheight = max(maxheight, top.first);
			for (int i = 0; i < 4; i++)
			{
				int x = top.second / n + path[i][0], y = top.second % n + path[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n || seen[x][y] == 1)
					continue;
				seen[x][y] = 1;
				if (heightMap[x][y] < maxheight)
					res += maxheight - heightMap[x][y];
				q.push({heightMap[x][y], x * n + y});
			}
		}
		return res;
	}
};