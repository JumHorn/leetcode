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
		return backTracking(graph, 1, t, target);
	}

	double backTracking(vector<unordered_set<int>> &graph, int index, int t, int target)
	{
		int n = graph[index].size();
		if (t == 0 || n == 0)
			return index == target ? 1 : 0;
		for (auto to : graph[index])
		{
			graph[to].erase(index);
			double res = 1.0 / n * backTracking(graph, to, t - 1, target);
			if (res != 0)
				return res;
		}
		return 0;
	}
};