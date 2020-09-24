
#define max(a, b) (((a) > (b)) ? (a) : (b))

int integerBreak(int n)
{
	if (n < 3)
		return 1;
	if (n == 3)
		return 2;
	int dp[60] = {0};
	for (int i = 0; i <= 3; ++i)
		dp[i] = i;
	for (int i = 4; i <= n; ++i)
	{
		for (int j = 1; j <= i / 2; ++j)
			dp[i] = max(dp[i], dp[j] * dp[i - j]);
	}
	return dp[n];
}
