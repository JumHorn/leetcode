#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Algorithm:
Bellman Ford
*/

class Solution
{
public:
	int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
	{
		int N = passingFees.size();
		vector<vector<int>> dp(maxTime + 1, vector<int>(N, INF));
		dp[0][0] = passingFees[0];
		for (int t = 1; t <= maxTime; ++t)
		{
			for (const auto &edge : edges)
			{
				int i = edge[0], j = edge[1], cost = edge[2];
				if (cost <= t)
				{
					dp[t][i] = min(dp[t][i], dp[t - cost][j] + passingFees[i]);
					dp[t][j] = min(dp[t][j], dp[t - cost][i] + passingFees[j]);
				}
			}
		}

		int res = INF;
		for (int t = 1; t <= maxTime; ++t)
			res = min(res, dp[t][N - 1]);
		return res == INF ? -1 : res;
	}

private:
	static constexpr int INF = INT_MAX / 2;
};