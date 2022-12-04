#include <cmath>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int magnificentSets(int n, vector<vector<int>> &edges)
	{
		vector<vector<int>> graph(n + 1), group;
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		//dfs to check bipartite
		vector<int> seen(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (seen[i] != 0)
				continue;
			seen[i] = 1;
			stack<int> stk;
			stk.push(i);
			group.push_back({i});
			while (!stk.empty())
			{
				auto u = stk.top();
				stk.pop();
				for (auto &v : graph[u])
				{
					if (seen[v] == 0)
					{
						seen[v] = seen[u] + 1;
						stk.push(v);
						group.back().push_back(v);
					}
					else if ((seen[u] & 1) == (seen[v] & 1))
						return -1;
				}
			}
		}

		int res = 0;
		for (auto &g : group)
		{
			int maxval = 0;
			for (auto n : g)
				maxval = max(maxval, bfs(graph, n));
			res += maxval;
		}
		return res;
	}

	int bfs(vector<vector<int>> &graph, int root)
	{
		int N = graph.size(), g = 0;
		vector<int> seen(N);
		seen[root] = 1;
		queue<int> q;
		q.push(root);
		while (!q.empty())
		{
			++g;
			int size = q.size();
			while (--size >= 0)
			{
				int at = q.front();
				q.pop();
				for (auto to : graph[at])
				{
					if (seen[to] == 0)
					{
						q.push(to);
						seen[to] = 1;
					}
				}
			}
		}
		return g;
	}
};