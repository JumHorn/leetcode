#include <vector>
using namespace std;

class Solution
{
public:
	int countArrangement(int N)
	{
		vector<int> dp(1 << N);
		dp[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			for (int mask = (1 << N) - 1; mask >= 0; --mask)
			{
				for (int j = 1; j <= N; ++j)
				{
					if (i % j == 0 || j % i == 0)
					{
						if ((mask & (1 << (j - 1))) == 0)
							dp[mask | (1 << (j - 1))] += dp[mask];
					}
				}
			}
		}
		return dp[(1 << N) - 1];
	}
};