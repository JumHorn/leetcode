#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount)
{
	int dp[amount + 1];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i)
	{
		for (int j = 0; j < coinsSize; ++j)
		{
			if (coins[j] <= i && dp[i - coins[j]] != -1)
			{
				if (dp[i] == -1)
					dp[i] = dp[i - coins[j]] + 1;
				else
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount];
}
