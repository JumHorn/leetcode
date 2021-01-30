#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minReorder(int n, vector<vector<int>> &connections)
	{
		vector<vector<pair<int, int>>> graph(n);
		for (auto &conn : connections)
		{
			graph[conn[0]].push_back({conn[1], 1}); //real edge
			graph[conn[1]].push_back({conn[0], 0}); //virtual edge
		}
		return dfs(graph, 0, 0);
	}

	int dfs(vector<vector<pair<int, int>>> &graph, int from, int at)
	{
		int res = 0;
		for (auto &to : graph[at])
		{
			if (from != to.first)
			{
				if (to.second == 1)
					++res;
				res += dfs(graph, at, to.first);
			}
		}
		return res;
	}
};