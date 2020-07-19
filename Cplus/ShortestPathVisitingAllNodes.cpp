#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestPathLength(vector<vector<int>>& graph)
	{
		int N = graph.size(), res = 0;
		vector<vector<int>> dp(1 << N, vector<int>(N, N * N));
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++)
		{
			q.push({1 << i, i});
			dp[1 << i][i] = 0;
		}
		while (!q.empty())
		{
			auto node = q.front();
			q.pop();
			int dist = dp[node.first][node.second];
			if (node.first == (1 << N) - 1)
				return dist;
			for (int child : graph[node.second])
			{
				int cover = (node.first | (1 << child));
				if (dist + 1 < dp[cover][child])
				{
					dp[cover][child] = dist + 1;
					q.push({cover, child});
				}
			}
		}
		return res;
	}
};
