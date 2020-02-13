#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
	{
		int n = quiet.size();
		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < (int)richer.size(); i++)
			graph[richer[i][1]][richer[i][0]] = 1;
		vector<int> res(n, n);
		for (int i = 0; i < n; i++)
			dfs(graph, quiet, res, i);
		return res;
	}

	int dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<int> &res, int index)
	{
		int n = graph.size();
		if (res[index] < n)
			return res[index];
		if (res[index] >= n)
			res[index] = index;
		for (int i = 0; i < n; i++)
		{
			if (graph[index][i] == 1)
			{
				int tmp = dfs(graph, quiet, res, i);
				if (quiet[tmp] < quiet[res[index]])
					res[index] = tmp;
			}
		}
		return res[index];
	}
};