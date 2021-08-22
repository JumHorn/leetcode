#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPaths(int n, vector<vector<int>> &roads)
	{
		const long INF = LONG_MAX;
		vector<long> dist(n, INF), dp(n);
		vector<vector<int>> graph(n, vector<int>(n, -1));
		for (auto &v : roads)
		{
			if (graph[v[0]][v[1]] == -1)
				graph[v[0]][v[1]] = v[2];
			else
				graph[v[0]][v[1]] = min(graph[v[0]][v[1]], v[2]);

			if (graph[v[1]][v[0]] == -1)
				graph[v[1]][v[0]] = v[2];
			else
				graph[v[1]][v[0]] = min(graph[v[1]][v[0]], v[2]);
		}

		dist[0] = 0;
		dp[0] = 1;
		// {time,id}
		priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
		q.push({0, 0});
		while (!q.empty())
		{
			auto [t, id] = q.top();
			q.pop();
			if (dist[id] < t)
				continue;
			for (int i = 0; i < n; ++i)
			{
				if (graph[id][i] == -1)
					continue;

				if (dist[i] > t + graph[id][i])
				{
					dist[i] = t + graph[id][i];
					dp[i] = dp[id];
					q.push({dist[i], i});
				}
				else if (dist[i] == t + graph[id][i])
					dp[i] = (dp[i] + dp[id]) % MOD;
			}
		}
		return dp[n - 1];
	}

private:
	static const int MOD = 1e9 + 7;
};