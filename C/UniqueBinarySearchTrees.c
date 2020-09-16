
int numTrees(int n)
{
	int dp[n + 1];
	dp[0] = dp[1] = 1;
	for (int i = 1; i < n; ++i)
	{
		dp[i + 1] = 0;
		for (int j = 0; j <= i; ++j)
			dp[i + 1] += dp[j] * dp[i - j];
	}
	return dp[n];
}