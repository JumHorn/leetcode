#include <string.h>

/*
the original dp
dp[i][k] max profit with i prices in k transaction
dp[i][k]=max{prices[i]-prices[j]+dp[j-1][k-1]} (0<j<i)
dp[i][k]=max{prices[i]+(dp[j-1][k-1]-prices[j])} (0<j<i)

optimization
inner loop k is constant
dp1[j]=max{dp[j-1][k-1]-prices[j]}
dp[i][k]=max{prices[i]+dp1[j]}
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfitUnlimits(int *prices, int pricesSize)
{
	int res = 0;
	for (int i = 1; i < pricesSize; ++i)
	{
		if (prices[i] > prices[i - 1])
			res += prices[i] - prices[i - 1];
	}
	return res;
}

int maxProfit(int k, int *prices, int pricesSize)
{
	if (pricesSize < 2 || k == 0)
		return 0;
	if (k >= pricesSize / 2)
		return maxProfitUnlimits(prices, pricesSize);
	int dp[k + 1][pricesSize];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= k; ++i)
	{
		int buy = -prices[0];
		for (int j = 1; j < pricesSize; ++j)
		{
			dp[i][j] = max(dp[i][j - 1], prices[j] + buy);
			buy = max(buy, dp[i - 1][j - 1] - prices[j]);
		}
	}
	return dp[k][pricesSize - 1];
}