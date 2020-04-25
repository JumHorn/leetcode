
/*
dp[i][0] buy
dp[i][1] sell
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee)
{
	int dp[pricesSize][2];
	dp[0][0] = -prices[0] - fee;
	dp[0][1] = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
	}
	return dp[pricesSize - 1][1];
}
