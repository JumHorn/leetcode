#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			for (auto c : coins)
			{
				if (c <= i && dp[i - c] != -1)
				{
					if (dp[i] == -1)
						dp[i] = dp[i - c] + 1;
					else
						dp[i] = min(dp[i], dp[i - c] + 1);
				}
			}
		}
		return dp.back();
	}
};