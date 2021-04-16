#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/*
Prim's algorithm
minimum spanning tree
find vertex
*/

class Solution
{
public:
	int minCostConnectPoints(vector<vector<int>> &points)
	{
		int N = points.size();
		vector<vector<int>> graph(N, vector<int>(N));
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				graph[j][i] = graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{weight,node}
		vector<int> seen(N);
		seen[0] = 1;
		for (int i = 1; i < N; ++i)
			q.push({graph[0][i], i});
		int res = 0, count = 1;
		while (!q.empty() && count < N)
		{
			auto top = q.top();
			q.pop();
			if (seen[top.second] == 1)
				continue;
			seen[top.second] = 1;
			res += top.first;
			++count;
			for (int i = 0; i < N; ++i)
			{
				if (seen[i] == 0)
					q.push({graph[top.second][i], i});
			}
		}
		return res;
	}
};