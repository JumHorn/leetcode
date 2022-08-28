#include <queue>
#include <vector>
using namespace std;

/*
topological order
*/

class Solution
{
public:
	vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
	{
		vector<int> row, col;
		bool r = topologicalSort(k, rowConditions, row);
		if (!r)
			return {};
		bool c = topologicalSort(k, colConditions, col);
		if (!c)
			return {};
		vector<vector<int>> res(k, vector<int>(k));
		vector<pair<int, int>> pos(k + 1);
		for (int i = 0; i < k; ++i)
		{
			pos[row[i]].first = i;
			pos[col[i]].second = i;
		}
		for (int i = 1; i <= k; ++i)
			res[pos[i].first][pos[i].second] = i;
		return res;
	}

	bool topologicalSort(int k, vector<vector<int>> &conditions, vector<int> &tp_order)
	{
		vector<int> indegree(k + 1);
		vector<vector<int>> graph(k + 1);
		for (auto &con : conditions)
		{
			++indegree[con[1]];
			graph[con[0]].push_back(con[1]);
		}
		for (int i = 1; i <= k; ++i)
		{
			if (indegree[i] == 0)
				tp_order.push_back(i);
		}
		// tp_order size changes
		for (int i = 0; i < (int)tp_order.size(); ++i)
		{
			int cur = tp_order[i];
			for (auto next : graph[cur])
			{
				if (--indegree[next] == 0)
					tp_order.push_back(next);
			}
		}
		return tp_order.size() == k;
	}
};