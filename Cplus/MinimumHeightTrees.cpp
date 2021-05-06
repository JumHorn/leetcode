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
		vector<vector<int>> graph(n);
		vector<int> indegree(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
			++indegree[edge[0]];
			++indegree[edge[1]];
		}
		queue<int> leavenode;
		for (int i = 0; i < n; ++i)
		{
			if (--indegree[i] == 0)
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
					if (--indegree[child] == 0)
						leavenode.push(child);
				}
			}
		}
		vector<int> res;
		for (; !leavenode.empty(); leavenode.pop())
			res.push_back(leavenode.front());
		return res;
	}
};