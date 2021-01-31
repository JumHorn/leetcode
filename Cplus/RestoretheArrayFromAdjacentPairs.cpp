#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
	{
		int N = adjacentPairs.size();
		unordered_map<int, unordered_set<int>> graph;
		for (auto &p : adjacentPairs)
		{
			graph[p[0]].insert(p[1]);
			graph[p[1]].insert(p[0]);
		}
		int start = -1;
		for (auto &node : graph)
		{
			if (node.second.size() == 1)
			{
				start = node.first;
				break;
			}
		}
		vector<int> res;
		dfs(graph, start, start, res);
		return res;
	}

	void dfs(unordered_map<int, unordered_set<int>> &graph, int from, int at, vector<int> &res)
	{
		res.push_back(at);
		for (auto to : graph[at])
		{
			if (to != from)
				dfs(graph, at, to, res);
		}
	}
};