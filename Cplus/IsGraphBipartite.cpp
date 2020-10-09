#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isBipartite(vector<vector<int>> &graph)
	{
		int N = graph.size();
		vector<int> color(N);
		for (int i = 0; i < N; ++i)
		{
			if (color[i] == 0 && !backTracking(graph, color, i, 1))
				return false;
		}
		return true;
	}

	bool backTracking(vector<vector<int>> &graph, vector<int> &color, int node, int c)
	{
		if (color[node] != 0)
			return color[node] == c;
		color[node] = c;
		for (int i = 0; i < (int)graph[node].size(); ++i)
		{
			if (!backTracking(graph, color, graph[node][i], -c))
				return false;
		}
		return true;
	}
};