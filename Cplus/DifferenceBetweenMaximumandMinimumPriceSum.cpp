#include <vector>
using namespace std;

class Solution
{
public:
	long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price)
	{
		vector<vector<int>> graph(n);
		for (auto &e : edges)
		{
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		graph[0].push_back(-1); //choose 0 as root
		long res = 0;
		dfs(graph, 0, -1, price, res);
		return res;
	}

	//{path with leaf,path without leaf}
	pair<long, long> dfs(vector<vector<int>> &graph, int at, int from, vector<int> &price, long &res)
	{
		int p = price[at];
		if (graph[at].size() == 1)
			return {p, 0};
		long maxleaf = 0, maxnonleaf = 0;
		for (auto to : graph[at])
		{
			if (to == from)
				continue;
			auto [leaf, nonleaf] = dfs(graph, to, at, price, res);
			if (maxleaf == 0) //first subtree
				res = max(res, leaf);
			else
				res = max(res, maxnonleaf + p + leaf);
			res = max(res, maxleaf + p + nonleaf);
			maxleaf = max(maxleaf, leaf);
			maxnonleaf = max(maxnonleaf, nonleaf);
		}
		return {maxleaf + p, maxnonleaf + p};
	}
};