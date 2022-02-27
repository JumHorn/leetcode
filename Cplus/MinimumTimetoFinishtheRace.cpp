#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps)
	{
		int N = tires.size();
		vector<long> best(numLaps, LONG_MAX), dp(numLaps + 1, INT_MAX);
		for (int i = 0; i < N; ++i)
		{
			long f = tires[i][0], r = tires[i][1], x = 1, sum = 0;
			for (int j = 0; j < numLaps && f * x < f + changeTime; ++j)
			{
				sum += f * x;
				best[j] = min(best[j], sum);
				x *= r;
			}
		}
		dp[0] = 0;
		for (int i = 0; i < numLaps; ++i)
		{
			for (int j = 0; j < numLaps && best[j] < LONG_MAX && i >= j; ++j)
				dp[i + 1] = min(dp[i + 1], best[j] + changeTime + dp[i - j]);
		}
		return dp[numLaps];
	}
};