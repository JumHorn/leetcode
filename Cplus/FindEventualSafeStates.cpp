#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> eventualSafeNodes(vector<vector<int>> &graph)
	{
		int N = graph.size();
		vector<int> res, state(N); //0 unvisited 1 safe 2 unsafe
		for (int i = 0; i < N; ++i)
		{
			if (dfs(graph, i, state))
				res.push_back(i);
		}
		return res;
	}

	bool dfs(vector<vector<int>> &graph, int node, vector<int> &state)
	{
		if (state[node] != 0)
			return state[node] == 1;
		state[node] = 2;
		for (int i = 0; i < (int)graph[node].size(); ++i)
		{
			if (!dfs(graph, graph[node][i], state))
				return false;
		}
		state[node] = 1;
		return true;
	}
};