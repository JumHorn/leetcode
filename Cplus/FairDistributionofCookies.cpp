#include <vector>
using namespace std;

class Solution
{
public:
	int distributeCookies(vector<int> &cookies, int k)
	{
		int N = cookies.size(), mask = (1 << N) - 1;
		vector<int> dp(1 << N, INT_MAX), count(1 << N);
		dp[0] = 0;
		for (int i = 0; i < 1 << N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if ((i >> j) & 1)
					count[i] += cookies[j];
			}
		}

		for (int i = 0; i < k; ++i)
		{
			for (int j = mask; j >= 0; --j)
			{
				int submask = (~j & mask);
				for (int m = submask; m > 0; m = submask & (m - 1))
					dp[j | m] = min(dp[j | m], max(dp[j], count[m]));
			}
		}
		return dp[mask];
	}
};