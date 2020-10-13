#include <vector>
using namespace std;

class Solution
{
public:
	bool possibleBipartition(int N, vector<vector<int>> &dislikes)
	{
		vector<vector<int>> graph(N + 1);
		for (auto &dislike : dislikes)
		{
			graph[dislike[0]].push_back(dislike[1]);
			graph[dislike[1]].push_back(dislike[0]);
		}
		vector<int> color(N + 1);
		for (int i = 1; i <= N; ++i)
		{
			if (color[i] == 0 && !dfs(graph, color, i, 1))
				return false;
		}
		return true;
	}

	bool dfs(vector<vector<int>> &graph, vector<int> &color, int node, int c)
	{
		if (color[node] != 0)
			return color[node] == c;
		color[node] = c;
		for (int i = 0; i < (int)graph[node].size(); ++i)
		{
			if (!dfs(graph, color, graph[node][i], -c))
				return false;
		}
		return true;
	}
};