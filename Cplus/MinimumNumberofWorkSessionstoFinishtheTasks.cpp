#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSessions(vector<int> &tasks, int sessionTime)
	{
		int N = tasks.size();
		vector<int> dp(1 << N, INT_MAX);
		vector<int> group; //this mask can be finished in sessionTime
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			int t = 0;
			for (int i = 0; i < N; ++i)
			{
				if ((1 << i) & mask)
					t += tasks[i];
			}
			if (t <= sessionTime)
				group.push_back(mask);
		}

		dp[0] = 0;
		for (auto n : group)
		{
			for (int mask = (1 << N) - 1; mask > 0; --mask)
			{
				if ((n & mask) != n)
					continue;
				int pre = mask - n;
				if (dp[pre] == INT_MAX)
					continue;
				dp[mask] = min(dp[mask], dp[pre] + 1);
			}
		}
		return dp.back();
	}
};