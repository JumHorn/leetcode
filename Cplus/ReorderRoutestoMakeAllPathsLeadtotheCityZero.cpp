#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minReorder(int n, vector<vector<int>> &connections)
	{
		vector<unordered_map<int, int>> graph(n);
		for (auto &conn : connections)
		{
			graph[conn[0]][conn[1]] = 1; //real edge
			graph[conn[1]][conn[0]] = 0; //virtual edge
		}
		return dfs(graph, 0);
	}

	int dfs(vector<unordered_map<int, int>> &graph, int at)
	{
		int res = 0;
		for (auto &to : graph[at])
		{
			if (to.second == 1)
				++res;
			graph[to.first].erase(at);
			res += dfs(graph, to.first);
		}
		return res;
	}
};