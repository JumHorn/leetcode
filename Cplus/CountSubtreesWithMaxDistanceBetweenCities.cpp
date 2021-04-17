#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
	{
		vector<int> res(n - 1);
		vector<vector<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0] - 1].push_back(edge[1] - 1);
			graph[edge[1] - 1].push_back(edge[0] - 1);
		}
		for (int mask = 1; mask < (1 << n); ++mask)
		{
			int seen = ~mask;
			auto node = getHeight(graph, getNode(mask), seen);
			if (node.first > 0 && seen == -1) //ensure all nodes traversed
				++res[node.first - 1];
		}
		return res;
	}

	int getNode(int mask)
	{
		int res = 0;
		while ((mask & (1 << res)) == 0)
			++res;
		return res;
	}

	//return {longest path,depth}
	pair<int, int> getHeight(vector<vector<int>> &graph, int at, int &seen)
	{
		seen |= (1 << at);
		int longestpath = 0, depth1 = 0, depth2 = 0;
		for (auto to : graph[at])
		{
			if ((seen & (1 << to)) == 0)
			{
				auto node = getHeight(graph, to, seen);
				longestpath = max(longestpath, node.first);
				if (depth1 < node.second)
				{
					depth2 = depth1;
					depth1 = node.second;
				}
				else if (depth2 < node.second)
					depth2 = node.second;
			}
		}
		return {max(depth1 + depth2, longestpath), depth1 + 1};
	}
};