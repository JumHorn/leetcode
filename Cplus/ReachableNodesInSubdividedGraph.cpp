#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
	int reachableNodes(vector<vector<int>> &edges, int M, int N)
	{
		vector<vector<pair<int, int>>> graph(N);
		vector<vector<int>> dist(N, vector<int>(N));
		vector<int> seen(N, -1); //current largest weight
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back({edge[1], edge[2]});
			graph[edge[1]].push_back({edge[0], edge[2]});
		}

		int res = 0;
		//dijkstra
		priority_queue<pair<int, int>> q; //{weight,node}
		q.push({M, 0});
		while (!q.empty())
		{
			int weight = q.top().first;
			int node = q.top().second;
			q.pop();
			if (weight <= seen[node])
				continue;
			seen[node] = weight;
			++res;
			for (auto &n : graph[node])
			{
				if (weight > n.second)
				{
					dist[node][n.first] = n.second;
					if (weight - n.second - 1 > seen[n.first])
						q.push({weight - n.second - 1, n.first});
				}
				else
					dist[node][n.first] = max(dist[node][n.first], weight);
			}
		}

		for (auto &edge : edges)
		{
			int i = edge[0], j = edge[1], w = edge[2];
			res += min(w, dist[i][j] + dist[j][i]);
		}
		return res;
	}
};