#include <vector>
using namespace std;

class Solution
{
public:
	int change(int amount, vector<int> &coins)
	{
		int N = coins.size();
		if (amount == 0)
			return 1;
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
				dp[j] += dp[j - coins[i]];
		}
		return dp[amount];
	}
};