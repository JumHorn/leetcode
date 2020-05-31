#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minReorder(int n, vector<vector<int>>& connections)
	{
		vector<unordered_map<int, int>> graph(n);
		for (auto& conn : connections)
		{
			graph[conn[0]][conn[1]] = 1;
		}
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			res += dfs(graph, i);
		}
		return res;
	}

	int dfs(vector<unordered_map<int, int>>& graph, int at)
	{
		if (at == 0)
			return 0;
		if (graph[at].find(0) != graph[at].end())
			return 0;
	}
};
