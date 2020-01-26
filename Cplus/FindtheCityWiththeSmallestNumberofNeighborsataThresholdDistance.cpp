#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < (int)edges.size(); i++)
		{
			graph[edges[i][0]][edges[i][1]] = edges[i][2];
			graph[edges[i][1]][edges[i][0]] = edges[i][2];
		}
		int res = n - 1, count = 0;
		unordered_set<int> visited;
		dfs(graph, n - 1, visited, distanceThreshold);
		count = visited.size();
		for (int i = n - 2; i >= 0; i--)
		{
			visited.clear();
			dfs(graph, i, visited, distanceThreshold);
			int tmp = visited.size();
			if (tmp < count)
			{
				count = tmp;
				res = i;
			}
		}
		return res;
	}

	void dfs(vector<vector<int>>& graph, int n, unordered_set<int>& visited, int d)
	{
		if (d < 0)
			return;
		if (visited.find(n) != visited.end())
			return;
		visited.insert(n);
		for (int i = 0; i < (int)graph[n].size(); i++)
		{
			if (graph[n][i] != 0)
				dfs(graph, i, visited, d - graph[n][i]);
		}
	}
};
