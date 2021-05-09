#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
topological order
*/

class Solution
{
public:
	int largestPathValue(string colors, vector<vector<int>> &edges)
	{
		int N = colors.size();
		vector<int> indegree(N);
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			++indegree[edge[1]];
		}
		vector<int> tp_order;
		for (int i = 0; i < N; ++i)
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
		if ((int)tp_order.size() != N) //circle exists in graph
			return -1;

		int res = 0;
		vector<int> dp(N);
		for (char c = 'a'; c <= 'z'; ++c)
		{
			fill(dp.begin(), dp.end(), 0);
			for (auto cur : tp_order)
			{
				if (c == colors[cur])
					++dp[cur];
				res = max(res, dp[cur]);
				for (auto next : graph[cur])
					dp[next] = max(dp[next], dp[cur]);
			}
		}
		return res;
	}
};