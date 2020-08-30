#include <queue>
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
					groupgraph[group[beforeItems[i][j]]].push_back(group[i]);
					++groupindgree[group[i]];
				}
				else
				{
					itemgraph[beforeItems[i][j]].push_back(i);
					++itemindgree[i];
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
		int N = items.empty() ? graph.size() : items.size();
		vector<int> res;
		queue<int> q;
		if (items.empty())
		{
			for (int i = 0; i < N; ++i)
			{
				if (indgree[i] == 0)
					q.push(i);
			}
		}
		else
		{
			for (auto item : items)
			{
				if (indgree[item] == 0)
					q.push(item);
			}
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (auto n : graph[node])
			{
				if (--indgree[n] == 0)
					q.push(n);
			}
		}
		return res.size() == N ? res : vector<int>();
	}
};