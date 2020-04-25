
/*
dp[i][0] buy
dp[i][1] sell
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize < 2)
		return 0;
	int dp[pricesSize][2];
	dp[0][0] = -prices[0];
	dp[0][1] = 0;
	dp[1][0] = max(dp[0][0], -prices[1]);
	dp[1][1] = max(0, dp[0][0] + prices[1]);
	for (int i = 2; i < pricesSize; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
	}
	return dp[pricesSize - 1][1];
}
