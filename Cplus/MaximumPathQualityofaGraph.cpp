#include <vector>
using namespace std;

class Solution
{
public:
	int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
	{
		int N = values.size(), res = 0;
		vector<vector<pair<int, int>>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back({edge[1], edge[2]});
			graph[edge[1]].push_back({edge[0], edge[2]});
		}
		vector<int> seen(N);
		dfs(graph, values, seen, 0, maxTime, 0, res);
		return res;
	}

	void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &values, vector<int> &seen, int at, int maxTime, int quality, int &res)
	{
		if (maxTime < 0)
			return;
		++seen[at];
		if (seen[at] == 1)
			quality += values[at];
		if (at == 0)
			res = max(res, quality);
		for (auto [to, time] : graph[at])
			dfs(graph, values, seen, to, maxTime - time, quality, res);
		--seen[at];
	}
};