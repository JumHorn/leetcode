#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
	{
		sort(robot.begin(), robot.end());
		sort(factory.begin(), factory.end());
		long long res = LONG_MAX, N = robot.size(), M = factory.size();
		vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, 1e15)); //factory,robot
		//init
		dp[0][0] = 0;
		for (int i = 0; i < M; ++i)
			dp[i][0] = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				dp[i + 1][j + 1] = dp[i][j + 1];
				long long d = 0;
				for (int k = 0; k < factory[i][1] && k <= j; ++k)
				{
					d += abs(robot[j - k] - factory[i][0]);
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j - k] + d);
					if (j == N - 1 && dp[i + 1][j + 1] < 1e15)
						res = min(res, dp[i + 1][j + 1]);
				}
			}
		}
		return res;
	}
};