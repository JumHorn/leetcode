#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
	{
		vector<int> res(n);
		vector<vector<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		vector<bool> seen(n);
		postorder(graph, 0, labels, seen, res);
		return res;
	}

	const vector<int> postorder(vector<vector<int>> &graph, int at, string &labels, vector<bool> &seen, vector<int> &nodeCount)
	{
		vector<int> res(26);
		seen[at] = true;
		for (auto n : graph[at])
		{
			if (seen[n])
				continue;
			auto &count = postorder(graph, n, labels, seen, nodeCount);
			for (int i = 0; i < 26; ++i)
				res[i] += count[i];
		}
		nodeCount[at] = ++res[labels[at] - 'a'];
		return res;
	}
};