#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
	{
		vector<int> res(n);
		vector<unordered_set<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		dfs(graph, 0, labels[0], labels, res);
		return res;
	}

	vector<int> dfs(vector<unordered_set<int>> &graph, int at, char c, string &labels, vector<int> &nodeCount)
	{
		vector<int> res(26);
		for (auto n : graph[at])
		{
			graph[n].erase(at);
			vector<int> tmp = dfs(graph, n, c, labels, nodeCount);
			for (int i = 0; i < 26; ++i)
				res[i] += tmp[i];
		}
		nodeCount[at] = ++res[labels[at] - 'a'];
		return res;
	}
};