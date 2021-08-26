#include <vector>
using namespace std;

/*
图论中的割点与桥
articulation point and bridge
*/

class Solution
{
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
	{
		vector<vector<int>> graph(n);
		for (auto &con : connections)
		{
			graph[con[0]].push_back(con[1]);
			graph[con[1]].push_back(con[0]);
		}
		vector<int> dsc(n), low(n);
		vector<vector<int>> res;
		int time = 0;
		dfs(graph, dsc, low, -1, 0, time, res);
		return res;
	}

	void dfs(vector<vector<int>> &graph, vector<int> &dsc, vector<int> &low, int from, int at, int &time, vector<vector<int>> &res)
	{
		low[at] = dsc[at] = ++time;
		for (auto to : graph[at])
		{
			if (dsc[to] == 0)
			{
				dfs(graph, dsc, low, at, to, time, res);
				low[at] = min(low[at], low[to]);
				if (low[to] > dsc[at])
					res.push_back({at, to});
			}
			else if (from != to)
				low[at] = min(low[at], dsc[to]);
		}
	}
};