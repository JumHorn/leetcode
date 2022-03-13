#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	//dijkstra out param distance
	void dijkstra(vector<vector<pair<int, int>>> &graph, int source, vector<long long> &distance)
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

	/********end of dijkstra********/
	long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
	{
		vector<vector<pair<int, int>>> graph0(n), graph1(n);
		for (auto &edge : edges)
		{
			graph0[edge[0]].push_back({edge[1], edge[2]});
			graph1[edge[1]].push_back({edge[0], edge[2]});
		}

		vector<long long> distToSrc1(n, LLONG_MAX), distToSrc2(n, LLONG_MAX), distToDest(n, LLONG_MAX);
		dijkstra(graph0, src1, distToSrc1);
		dijkstra(graph0, src2, distToSrc2);
		dijkstra(graph1, dest, distToDest);

		long long res = LLONG_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (distToSrc1[i] != LLONG_MAX && distToSrc2[i] != LLONG_MAX && distToDest[i] != LLONG_MAX)
				res = min(res, (long long)distToSrc1[i] + distToSrc2[i] + distToDest[i]);
		}
		return res == LLONG_MAX ? -1 : res;
	}
};