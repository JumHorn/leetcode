#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		int M = obstacleGrid.size(), N = obstacleGrid[0].size();
		vector<int> dp(N);
		dp[0] = 1;
		for (int i = 0; i < M; ++i)
		{
			if (obstacleGrid[i][0] == 1)
				dp[0] = 0;
			for (int j = 1; j < N; ++j)
			{
				if (obstacleGrid[i][j] == 1)
					dp[j] = 0;
				else
					dp[j] += dp[j - 1];
			}
		}
		return dp[N - 1];
	}
};