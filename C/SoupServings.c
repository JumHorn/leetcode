

double recursive(int A, int B, double (*dp)[5001])
{
	if (A <= 0 && B <= 0)
		return 0.5;
	if (A <= 0)
		return 1;
	if (B <= 0)
		return 0;
	if (dp[A][B] != 0)
		return dp[A][B];
	double res = 0.25 * (recursive(A - 100, B, dp) + recursive(A - 75, B - 25, dp) + recursive(A - 50, B - 50, dp) + recursive(A - 25, B - 75, dp));
	dp[A][B] = res;
	return res;
}

double soupServings(int N)
{
	if (N >= 5000)
		return 1.0;
	static double dp[5001][5001] = {{0}};
	return recursive(N, N, dp);
}

