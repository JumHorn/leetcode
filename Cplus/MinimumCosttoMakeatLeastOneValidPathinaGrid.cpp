#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		int path[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //same as 1,2,3,4
		vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{cost,position}
		int res = 0;
		q.push({0, 0});
		dist[0][0] = 0;
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			int i = top.second / N, j = top.second % N;
			res = top.first;
			if (dist[i][j] < res) //avoid outdated
				continue;
			if (i == M - 1 && j == N - 1)
				return res;
			for (int k = 0; k < 4; ++k)
			{
				int dx = i + path[k][0], dy = j + path[k][1], cost = top.first + (grid[i][j] == k + 1 ? 0 : 1);
				if (dx >= 0 && dx < M && dy >= 0 && dy < N && dist[dx][dy] > cost)
				{
					dist[dx][dy] = cost;
					q.push({cost, dx * N + dy});
				}
			}
		}
		return res;
	}
};