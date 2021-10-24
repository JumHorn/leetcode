#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
	{
		vector<vector<int>> graph(n + 1);
		vector<int> indegree(n + 1);
		for (auto &r : relations)
		{
			graph[r[1]].push_back(r[0]);
			++indegree[r[0]];
		}
		int res = 0;
		vector<int> seen(n + 1, -1);
		for (int i = 1; i <= n; ++i)
		{
			if (indegree[i] == 0)
				res = max(res, dfs(graph, i, time, seen));
		}
		return res;
	}

	int dfs(vector<vector<int>> &graph, int node, vector<int> &time, vector<int> &seen)
	{
		if (graph[node].empty())
			return time[node - 1];
		if (seen[node] != -1)
			return seen[node];
		int res = 0;
		for (auto to : graph[node])
			res = max(res, dfs(graph, to, time, seen));
		return seen[node] = res + time[node - 1];
	}
};