
/*
the original dp function
dp[i]=max{prices[i]-prices[j]-fee+dp[j-2]} (1<j<i)

optimization
dp[i]=max{prices[i]-fee+(dp[j-2]-prices[j])} (1<j<i)
dp1[j]=max{dp[j-2]-prices[j]} record max dp[j-2]-prices[j]
dp[i]=max(dp[i-1],dp1[i-1]+prices[i]-fee)
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize < 2)
		return 0;
	int dp[pricesSize];
	dp[0] = 0;
	dp[1] = max(0, prices[1] - prices[0]);
	int buy = max(dp[0] - prices[0], dp[1] - prices[1]);
	for (int i = 2; i < pricesSize; ++i)
	{
		dp[i] = max(dp[i - 1], prices[i] + buy);
		buy = max(buy, dp[i - 2] - prices[i]);
	}
	return dp[pricesSize - 1];
}