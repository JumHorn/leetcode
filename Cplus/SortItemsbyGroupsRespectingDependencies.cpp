#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
	{
		for (int i = 0; i < n; ++i)
		{
			if (group[i] == -1)
				group[i] = m++;
		}
		vector<vector<int>> groupgraph(m);
		vector<int> groupindgree(m);
		vector<vector<int>> itemgraph(n);
		vector<int> itemindgree(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < (int)beforeItems[i].size(); ++j)
			{
				if (group[i] != group[beforeItems[i][j]]) //not in the same group
				{
					groupgraph[group[i]].push_back(group[beforeItems[i][j]]);
					++groupindgree[group[beforeItems[i][j]]];
				}
				else
				{
					itemgraph[i].push_back(beforeItems[i][j]);
					++itemindgree[beforeItems[i][j]];
				}
			}
		}
		auto grouporder = topologicalSort(groupgraph, groupindgree);
		if (grouporder.empty())
			return {};
		vector<int> res;
		vector<vector<int>> groupitem(m);
		for (int i = 0; i < n; ++i)
			groupitem[group[i]].push_back(i);
		for (auto n : grouporder)
		{
			if (groupitem[n].empty())
				continue;
			auto itemorder = topologicalSort(itemgraph, itemindgree, groupitem[n]);
			if (itemorder.empty())
				return {};
			res.insert(res.end(), itemorder.begin(), itemorder.end());
		}
		return res;
	}

	//if items is empty, search all graph
	vector<int> topologicalSort(vector<vector<int>> &graph, vector<int> &indgree, const vector<int> &items = vector<int>())
	{
		int N = graph.size();
		vector<int> res, seen(N);
		if (items.empty())
		{
			for (int i = 0; i < N; ++i)
			{
				if (indgree[i] == 0)
					dfs(graph, i, res, seen);
			}
			return res.size() == graph.size() ? res : vector<int>();
		}

		for (auto item : items)
		{
			if (indgree[item] == 0)
				dfs(graph, item, res, seen);
		}
		return res.size() == items.size() ? res : vector<int>();
	}

private:
	void dfs(vector<vector<int>> &graph, int at, vector<int> &v, vector<int> &seen)
	{
		if (seen[at] == 1)
			return;
		seen[at] = 1;
		for (auto n : graph[at])
			dfs(graph, n, v, seen);
		v.push_back(at);
	}
};