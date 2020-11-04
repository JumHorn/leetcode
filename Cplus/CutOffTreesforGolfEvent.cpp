#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int cutOffTree(vector<vector<int>> &forest)
	{
		int M = forest.size(), N = forest[0].size();
		priority_queue<pair<int, int>> height;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (forest[i][j] > 1)
					height.push({-forest[i][j], i * N + j});
			}
		}
		int cut = 0, res = 0;
		vector<vector<int>> cache(M * N, vector<int>(M * N));
		while (!height.empty())
		{
			int distance = minDistance(forest, cut, height.top().second, cache);
			if (distance == -1)
				return -1;
			res += distance;
			cut = height.top().second;
			height.pop();
		}
		return res;
	}

	int minDistance(vector<vector<int>> &forest, int from, int to, vector<vector<int>> &cache)
	{
		if (from == to)
			return 0;
		if (cache[from][to] != 0)
			return cache[from][to];
		int dist = 0, M = forest.size(), N = forest[0].size();
		queue<int> q;
		vector<int> seen(M * N);
		q.push(from);
		seen[from] = 1;
		while (!q.empty())
		{
			int size = q.size();
			++dist;
			while (--size >= 0)
			{
				int at = q.front();
				q.pop();
				int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				int x = at / N, y = at % N;
				for (int k = 0; k < 4; k++)
				{
					int i = x + path[k][0], j = y + path[k][1];
					if (i < 0 || i >= M || j < 0 || j >= N || forest[i][j] == 0)
						continue;
					if (seen[i * N + j] == 1)
						continue;
					seen[i * N + j] = 1;
					cache[from][i * N + j] = cache[i * N + j][from] = dist;
					if (i * N + j == to)
						return dist;
					q.push(i * N + j);
				}
			}
		}
		return -1;
	}
};