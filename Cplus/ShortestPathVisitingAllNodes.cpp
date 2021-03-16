#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestPathLength(vector<vector<int>> &graph)
	{
		int N = graph.size(), res = 0;
		vector<vector<int>> dp(1 << N, vector<int>(N, N * N));
		queue<pair<int, int>> q; //{mask,node}
		for (int i = 0; i < N; ++i)
		{
			q.push({1 << i, i});
			dp[1 << i][i] = 0;
		}
		while (!q.empty())
		{
			auto at = q.front();
			q.pop();
			int dist = dp[at.first][at.second];
			if (at.first == (1 << N) - 1)
				return dist;
			for (int to : graph[at.second])
			{
				int mask = (at.first | (1 << to));
				if (dist + 1 < dp[mask][to])
				{
					dp[mask][to] = dist + 1;
					q.push({mask, to});
				}
			}
		}
		return res;
	}
};