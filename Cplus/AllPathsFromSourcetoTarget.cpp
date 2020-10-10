#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
	{
		vector<vector<int>> res;
		vector<int> instance = {0};
		dfs(graph, 0, instance, res);
		return res;
	}

	void dfs(vector<vector<int>> &graph, int node, vector<int> &instance, vector<vector<int>> &res)
	{
		int N = graph.size();
		if (node == N - 1)
		{
			res.push_back(instance);
			return;
		}
		for (int i = 0; i < graph[node].size(); ++i)
		{
			instance.push_back(graph[node][i]);
			dfs(graph, graph[node][i], instance, res);
			instance.pop_back();
		}
	}
};