#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(vector<int> &houses, int k)
	{
		int N = houses.size();
		sort(houses.begin(), houses.end());
		vector<vector<int>> dp(N + 1, vector<int>(k + 1, 1e9)), cost(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 1; j < N; ++j)
				cost[i][j] = cost[i + 1][j - 1] + houses[j] - houses[i];
		}

		for (int i = 0; i <= k; ++i)
			dp[0][i] = 0;
		for (int l = 0; l < k; ++l)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int i = 0; i <= j; ++i)
					dp[j + 1][l + 1] = min(dp[j + 1][l + 1], dp[i][l] + cost[i][j]);
			}
		}
		return dp[N][k];
	}
};