#include <vector>
using namespace std;

class Solution
{
public:
	double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
	{
		vector<vector<int>> graph(n + 1);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		return backTracking(graph, -1, 1, t, target);
	}

	double backTracking(vector<vector<int>> &graph, int from, int at, int t, int target)
	{
		int N = graph[at].size();
		if (from != -1) //can not jump to previouse positon
			--N;
		if (t == 0 || N == 0)
			return at == target ? 1 : 0;
		for (auto to : graph[at])
		{
			if (to != from)
			{
				double res = 1.0 / N * backTracking(graph, at, to, t - 1, target);
				if (res != 0)
					return res;
			}
		}
		return 0;
	}
};