#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
	{
		vector<unordered_map<int, int>> graph(n);
		for (auto &con : connections)
		{
			graph[con[0]][con[1]] = 1;
			graph[con[1]][con[0]] = 2;
		}
		vector<int> dsc(n), low(n, n);
		vector<vector<int>> res;
		int found = 1;
		for (int i = 0; i < n; i++)
			if (dsc[i] == 0)
				dfs(graph, dsc, low, i, found, res);
		return res;
	}

	void dfs(vector<unordered_map<int, int>> &graph, vector<int> &dsc, vector<int> &low, int index, int &found, vector<vector<int>> &res)
	{
		if (dsc[index] != 0)
			return;
		low[index] = dsc[index] = found++;
		int n = graph.size();
		for (auto to : graph[index])
		{
			if (dsc[to.first] == 0)
			{
				graph[to.first].erase(index);
				dfs(graph, dsc, low, to.first, found, res);
				low[index] = min(low[index], low[to.first]);
				if (dsc[index] < low[to.first])
				{
					if (graph[index][to.first] == 1)
						res.push_back({index, to.first});
					else
						res.push_back({to.first, index});
				}
			}
			else
				low[index] = min(low[index], low[to.first]);
		}
	}
};