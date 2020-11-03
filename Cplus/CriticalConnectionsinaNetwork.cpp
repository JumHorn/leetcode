#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
	{
		vector<unordered_set<int>> graph(n);
		for (auto &con : connections)
		{
			graph[con[0]].insert(con[1]);
			graph[con[1]].insert(con[0]);
		}
		vector<int> dsc(n), low(n);
		vector<vector<int>> res;
		int time = 0;
		for (int i = 0; i < n; ++i)
		{
			if (dsc[i] == 0)
				dfs(graph, dsc, low, i, time);
		}
		for (auto &con : connections)
		{
			if (graph[con[0]].find(con[1]) != graph[con[0]].end())
			{
				if (low[con[1]] > dsc[con[0]])
					res.push_back(con);
			}
			else
			{
				if (low[con[0]] > dsc[con[1]])
					res.push_back(con);
			}
		}
		return res;
	}

	void dfs(vector<unordered_set<int>> &graph, vector<int> &dsc, vector<int> &low, int at, int &time)
	{
		if (dsc[at] != 0)
			return;
		low[at] = dsc[at] = ++time;
		for (auto to : graph[at])
		{
			if (dsc[to] == 0)
			{
				graph[to].erase(at);
				dfs(graph, dsc, low, to, time);
			}
			low[at] = min(low[at], low[to]);
		}
	}
};