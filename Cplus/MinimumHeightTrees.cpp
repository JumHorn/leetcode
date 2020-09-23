#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

/*
topological sort
remove leaf node layer by layer
*/

class Solution
{
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
	{
		if (edges.empty())
			return {0};
		vector<unordered_set<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		queue<int> leavenode;
		for (int i = 0; i < n; ++i)
		{
			if ((int)graph[i].size() == 1)
				leavenode.push(i);
		}
		while (n > 2)
		{
			int size = leavenode.size();
			n -= size;
			while (--size >= 0)
			{
				auto node = leavenode.front();
				leavenode.pop();
				for (auto child : graph[node])
				{
					graph[child].erase(node);
					if ((int)graph[child].size() == 1)
						leavenode.push(child);
				}
			}
		}
		vector<int> res;
		while (!leavenode.empty())
		{
			res.push_back(leavenode.front());
			leavenode.pop();
		}
		return res;
	}
};