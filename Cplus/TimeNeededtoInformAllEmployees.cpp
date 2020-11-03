#include <vector>
using namespace std;

class Solution
{
public:
	int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
	{
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i)
			if (manager[i] != -1)
				graph[manager[i]].push_back(i);
		int res = dfs(graph, headID, informTime);
		return res;
	}

	int dfs(vector<vector<int>> &graph, int headid, vector<int> &informTime)
	{
		if (graph[headid].empty())
			return 0;
		int res = 0;
		for (int i = 0; i < (int)graph[headid].size(); ++i)
			res = max(res, dfs(graph, graph[headid][i], informTime) + informTime[headid]);
		return res;
	}
};
