#include <vector>
using namespace std;

/*
(dp[i] / speed) means the minimum arrival time with i skip
*/

class Solution
{
public:
	int minSkips(vector<int> &dist, int speed, int hoursBefore)
	{
		int N = dist.size();
		vector<int> dp(N + 1);
		for (int i = 0; i < N; ++i)
		{
			for (int j = N; j >= 0; --j)
			{
				dp[j] += dist[i];
				if (i < N - 1)
					dp[j] = (dp[j] + speed - 1) / speed * speed; // take a rest
				if (j > 0)
					dp[j] = min(dp[j], dp[j - 1] + dist[i]);
			}
		}
		for (int i = 0; i < N; ++i)
		{
			if (dp[i] <= (long)speed * hoursBefore)
				return i;
		}
		return -1;
	}
};