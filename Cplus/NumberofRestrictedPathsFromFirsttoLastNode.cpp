#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int countRestrictedPaths(int n, vector<vector<int>> &edges)
	{
		vector<vector<pair<int, int>>> graph(n + 1);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back({edge[1], edge[2]});
			graph[edge[1]].push_back({edge[0], edge[2]});
		}
		//dijkstra
		vector<int> distance(n + 1, INT_MAX);
		dijkstra(graph, n, distance);
		//dfs
		vector<int> dp(n + 1, -1);
		return dfs(graph, distance, -1, 1, n, dp);
	}

	int dfs(vector<vector<pair<int, int>>> &graph, vector<int> &distance, int from, int at, int dst, vector<int> &dp)
	{
		if (at == dst)
			return 1;
		if (dp[at] != -1)
			return dp[at];
		int res = 0;
		for (auto &[to, _] : graph[at])
		{
			if (to != from && distance[to] < distance[at])
				res = (res + dfs(graph, distance, at, to, dst, dp)) % MOD;
		}
		return dp[at] = res;
	}

	void dijkstra(vector<vector<pair<int, int>>> &graph, int source, vector<int> &distance)
	{
		distance[source] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{distance,node}
		q.push({0, source});
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			if (top.first > distance[top.second])
				continue;
			for (auto [node, weight] : graph[top.second])
			{
				if (weight + top.first < distance[node])
				{
					distance[node] = weight + top.first;
					q.push({distance[node], node});
				}
			}
		}
	}

private:
	static const int MOD = 1e9 + 7;
};