#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		for (auto& v : prerequisites)
			graph[v[0]][v[1]] = 1;
		vector<bool> res;
		for (auto& v : queries)
		{
			res.push_back(dfs(graph, v[0], v[1]));
		}
		return res;
	}

	bool dfs(vector<vector<int>>& graph, int from, int to)
	{
		if (from == to)
			return true;
		if (graph[from][to] == -1)
			return false;
		for (int i = 0; i < (int)graph[from].size(); i++)
		{
			if (graph[from][i] == 1 && dfs(graph, i, to))
			{
				graph[from][to] = 1;
				return true;
			}
		}
		graph[from][to] = -1;
		return false;
	}
};
