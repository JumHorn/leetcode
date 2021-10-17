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
		int res = -1;
		vector<vector<int>> seen(n + 1);
		while (!q.empty())
		{
			auto [t, node] = q.top();
			q.pop();

			for (auto to : graph[node])
			{
				if (seen[to].size() >= 2)
					continue;
				int val = t + time;
				if (t / change % 2)
					val += change - t % change;
				if (seen[to].empty() || seen[to][0] != val)
				{
					q.push({val, to});
					seen[to].push_back(val);
				}
			}
		}
		return seen[n][1];
	}
};