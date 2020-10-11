
double memdp(int A, int B, double (*dp)[5001])
{
	if (A <= 0 && B <= 0)
		return 0.5;
	if (A <= 0)
		return 1;
	if (B <= 0)
		return 0;
	if (dp[A][B] != 0)
		return dp[A][B];
	double res = 0;
	for (int i = 0; i <= 75; i += 25)
		res += memdp(A - (100 - i), B - i, dp);
	return dp[A][B] = res * 0.25;
}

double soupServings(int N)
{
	if (N >= 5000)
		return 1.0;
	static double dp[5001][5001] = {{0}};
	return memdp(N, N, dp);
}