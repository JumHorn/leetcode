#include <vector>
using namespace std;

class Solution
{
public:
	int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
	{
		vector<vector<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		vector<int> seen(n);
		for (auto n : restricted)
			seen[n] = 1;
		return preorder(graph, 0, seen);
	}

	int preorder(vector<vector<int>> &graph, int at, vector<int> &seen)
	{
		if (seen[at] != 0)
			return 0;
		int res = 1;
		seen[at] = 1;
		for (auto to : graph[at])
			res += preorder(graph, to, seen);
		return res;
	}
};