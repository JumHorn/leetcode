
int numTilings(int N)
{
	static const int MOD = 1e9 + 7;
	if (N < 3)
		return N;
	int dp[N + 1];
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; ++i)
		dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
	return dp[N];
}