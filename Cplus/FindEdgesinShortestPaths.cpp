#include <climits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> findAnswer(int n, vector<vector<int>> &edges)
	{
		vector<vector<tuple<int, int, int>>> graph(n); //{node,weight,index}
		for (int i = 0; i < edges.size(); ++i)
		{
			graph[edges[i][0]].push_back({edges[i][1], edges[i][2], i});
			graph[edges[i][1]].push_back({edges[i][0], edges[i][2], i});
		}
		vector<long long> distance(n, LLONG_MAX);
		dijkstra(graph, 0, distance);
		vector<bool> res(edges.size());
		if (distance[n - 1] == LLONG_MAX)
			return res;
		vector<int> seen(n);
		dfs(graph, distance, seen, n - 1, res);
		return res;
	}

	void dfs(vector<vector<tuple<int, int, int>>> &graph, vector<long long> &distance, vector<int> &seen, int source, vector<bool> &res)
	{
		seen[source] = 1;
		for (auto [n, w, i] : graph[source])
		{
			if (distance[source] == distance[n] + w)
			{
				res[i] = true;
				if (seen[n] == 0)
					dfs(graph, distance, seen, n, res);
			}
		}
	}

	// dijkstra
	void dijkstra(vector<vector<tuple<int, int, int>>> &graph, int source, vector<long long> &distance)
	{
		int N = graph.size();
		distance[source] = 0;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q; //{distance,node}
		q.push({0, source});
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			if (top.first > distance[top.second])
				continue;
			for (auto [node, weight, _] : graph[top.second])
			{
				if (weight + top.first < distance[node])
				{
					distance[node] = weight + top.first;
					q.push({distance[node], node});
				}
			}
		}
	}
	/********end of dijkstra********/
};