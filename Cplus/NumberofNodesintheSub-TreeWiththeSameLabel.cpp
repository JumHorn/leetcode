#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
	{
		vector<int> res(n);
		vector<unordered_set<int>> graph(n);
		for (auto& edge : edges)
			graph[edge[0]].insert(edge[1]);

		for (int i = 0; i < n; i++)
			res[i] = dfs(graph, i, labels[i], labels) + 1;
		return res;
	}

	int dfs(vector<unordered_set<int>>& graph, int at, char c, string& labels)
	{
		int res = 0;
		for (auto n : graph[at])
		{
			if (labels[n] == c)
				++res;
			res += dfs(graph, n, c, labels);
		}
		return res;
	}
};
