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

int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize < 2)
		return 0;
	int dp[3][pricesSize];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= 2; i++)
	{
		int buy = -prices[0];
		for (int j = 1; j < pricesSize; j++)
		{
			dp[i][j] = max(dp[i][j - 1], prices[j] + buy);
			buy = max(buy, dp[i - 1][j - 1] - prices[j]);
		}
	}
	return dp[2][pricesSize - 1];
}