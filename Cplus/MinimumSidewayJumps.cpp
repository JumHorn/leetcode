#include <vector>
using namespace std;

class Solution
{
public:
	int minSideJumps(vector<int> &obstacles)
	{
		int N = obstacles.size(), INF = 1e9;
		vector<vector<int>> dp(N, vector<int>(3));
		dp[0][1] = 0;
		dp[0][0] = dp[0][2] = 1;
		for (int i = 1; i < N; ++i)
		{
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
			if (obstacles[i] != 0)
				dp[i][obstacles[i] - 1] = INF;
			//lane 0
			if (obstacles[i] != 1)
				dp[i][0] = min({dp[i - 1][0], dp[i][1] + 1, dp[i][2] + 1});
			//lane 1
			if (obstacles[i] != 2)
				dp[i][1] = min({dp[i - 1][1], dp[i][0] + 1, dp[i][2] + 1});
			//lane 2
			if (obstacles[i] != 3)
				dp[i][2] = min({dp[i - 1][2], dp[i][0] + 1, dp[i][1] + 1});
		}
		return min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
	}
};