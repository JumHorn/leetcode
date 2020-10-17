#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int mincostTickets(vector<int> &days, vector<int> &costs)
	{
		int N = days.back() + 1;
		vector<int> dp(N + 1);
		int index = 0;
		for (int i = dp[index]; i < N; ++i)
		{
			if (i != days[index])
				dp[i + 1] = dp[i];
			else
			{
				++index;
				dp[i + 1] = dp[i] + costs[0];
				dp[i + 1] = min(dp[i + 1], dp[max(0, i + 1 - 7)] + costs[1]);
				dp[i + 1] = min(dp[i + 1], dp[max(0, i + 1 - 30)] + costs[2]);
			}
		}
		return dp[N];
	}
};