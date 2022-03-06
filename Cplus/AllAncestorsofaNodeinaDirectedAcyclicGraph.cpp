#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
	{
		vector<set<int>> res(n);
		vector<vector<int>> graph(n);
		vector<int> indegree(n);
		for (auto &edge : edges)
		{
			int from = edge[0], to = edge[1];
			graph[from].push_back(to);
			++indegree[to];
		}
		queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int node = q.front();
				q.pop();
				for (auto to : graph[node])
				{
					if (--indegree[to] == 0)
						q.push(to);
					res[to].insert(node);
					for (auto n : res[node])
						res[to].insert(n);
				}
			}
		}
		vector<vector<int>> res1(n);
		for (int i = 0; i < n; ++i)
		{
			for (auto n : res[i])
				res1[i].push_back(n);
		}
		return res1;
	}
};