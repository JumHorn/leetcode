
/*
the original dp function
dp[i]=max{prices[i]-prices[j]-fee+dp[j-1]} (0<j<i)

optimization
dp[i]=max{prices[i]-fee+(dp[j-1]-prices[j])} (0=<j<i)
dp1[j]=max{dp[j-1]-prices[j]} record max dp[j-1]-prices[j]
dp[i]=max(dp[i-1],dp1[i-1]+prices[i]-fee)
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int *prices, int pricesSize, int fee)
{
	int dp[pricesSize];
	dp[0] = 0;
	int buy = -prices[0];
	for (int i = 1; i < pricesSize; ++i)
	{
		dp[i] = max(dp[i - 1], prices[i] - fee + buy);
		buy = max(buy, dp[i - 1] - prices[i]);
	}
	return dp[pricesSize - 1];
}