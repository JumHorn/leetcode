#include <algorithm>
#include <unordered_map>
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
		vector<vector<int>> dp(N + 1, vector<int>(amount + 1));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				if (j == coins[i])
					dp[i + 1][j] = 1 + dp[i][j];
				else if (j < coins[i])
					dp[i + 1][j] = dp[i][j];
				else
					dp[i + 1][j] = dp[i + 1][j - coins[i]] + dp[i][j];
			}
		}
		return dp.back().back();
	}
};