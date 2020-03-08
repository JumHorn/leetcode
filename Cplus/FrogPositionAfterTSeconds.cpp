#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
	{
		vector<unordered_set<int>> graph(n + 1);
		for (auto &edge : edges)
		{
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		return dfs(graph, 1, t, target);
	}

	double dfs(vector<unordered_set<int>> &graph, int index, int t, int target)
	{
		if (t == 0 || graph[index].size() == 0)
		{
			return index == target ? 1 : 0;
		}
		int n = graph[index].size();
		for (auto to : graph[index])
		{
			graph[to].erase(index);
			double tmp = 1.0 / n * dfs(graph, to, t - 1, target);
			if (tmp != 0)
				return tmp;
		}
		return 0;
	}
};