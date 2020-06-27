#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
	{
		vector<vector<int>> graph(n + 1, vector<int>(n + 1));
		set<int> root;
		for (int i = 1; i <= n; i++)
			root.insert(i);
		vector<int> seen(n + 1);
		for (auto &v : dependencies)
		{
			graph[v[0]][v[1]] = 1;
			root.erase(v[1]);
		}
		queue<int> q;
		for (auto n : root)
		{
			q.push(n);
			seen[n] = 1;
		}
		int res = 0;
		while (!q.empty())
		{
			int size = q.size();
			int count = k;
			++res;
			vector<int> parent(n + 1);
			while (--size >= 0 && --count >= 0)
			{
				int node = q.front();
				q.pop();
				if (parent[node] == 1)
					q.push(node);
				for (int to = 1; to <= n; to++)
				{
					if (graph[node][to] == 1)
					{
						parent[to] = 1;
						if (seen[to] == 0)
						{
							seen[to] = 1;
							q.push(to);
						}
					}
				}
			}
		}
		return res;
	}
};