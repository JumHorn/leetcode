#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		for (auto &con : connections)
		{
			graph[con[0]][con[1]] = 1;
			graph[con[1]][con[0]] = 2;
		}
		vector<int> dsc(n), low(n, n);
		vector<vector<int>> res;
		int found = 1;
		for (int i = 0; i < n; i++)
			if (dsc[i] == 0)
				dfs(graph, dsc, low, i, found, res);
		return res;
	}

	void dfs(vector<vector<int>> &graph, vector<int> &dsc, vector<int> &low, int index, int &found, vector<vector<int>> &res)
	{
		if (dsc[index] != 0)
			return;
		low[index] = dsc[index] = found++;
		int n = graph.size();
		for (int i = 0; i < n; i++)
		{
			if (graph[index][i] == 0)
				continue;
			if (dsc[i] == 0)
			{
				graph[i][index] = 0;
				dfs(graph, dsc, low, i, found, res);
			}
			low[index] = min(low[index], low[i]);
			if (low[index] < low[i])
			{
				if (graph[index][i] == 1)
					res.push_back({index, i});
				else
					res.push_back({i, index});
			}
		}
	}
};

int main()
{
	vector<vector<int>> v = {{1, 0}, {2, 0}, {3, 2}, {4, 2}, {4, 3}, {3, 0}, {4, 0}};
	Solution sol;
	sol.criticalConnections(5, v);
	return 0;
}