#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
	{
		vector<vector<int>> graph(n + 1);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{time,node}
		q.push({0, 1});
		vector<vector<int>> seen(n + 1);
		while (!q.empty())
		{
			auto [t, node] = q.top();
			q.pop();

			if (seen[node].size() >= 2)
				continue;

			int val = t;
			if (t % (2 * change) >= change)
				val = (t + 2 * change - 1) / (2 * change) * (2 * change);

			if (node == n)
			{
				if (seen[node].empty() || seen[node][0] != t)
					seen[node].push_back(t);
				else
					continue;
			}
			else
			{
				if (seen[node].empty() || seen[node][0] != val)
					seen[node].push_back(val);
				else
					continue;
			}
			for (auto to : graph[node])
				q.push({val + time, to});
		}
		return seen[n][1];
	}
};