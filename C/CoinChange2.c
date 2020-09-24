#include <string.h>

int memdp(int* coins, int coinsSize, int index, int amount, int (*dp)[coinsSize])
{
	if (amount < 0)
		return 0;
	if (amount == 0)
		return 1;
	if (dp[amount][index] != -1)
		return dp[amount][index];
	int res = 0;
	for (int i = index; i < coinsSize; ++i)
		res += memdp(coins, coinsSize, i, amount - coins[i], dp);
	return dp[amount][index] = res;
}

int change(int amount, int* coins, int coinsSize)
{
	if (coinsSize == 0)
		return amount == 0 ? 1 : 0;
	if (amount == 0)
		return 1;
	int dp[amount + 1][coinsSize];
	memset(dp, -1, sizeof(dp));
	memdp(coins, coinsSize, 0, amount, dp);
	return dp[amount][0];
}
