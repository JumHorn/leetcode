/*
(2) 1×2, 2×2, 3×2, 4×2, 5×2, …
(3) 1×3, 2×3, 3×3, 4×3, 5×3, …
(5) 1×5, 2×5, 3×5, 4×5, 5×5, …
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define trimin(a, b, c) (min(min(a, b), c)) //the minimum of a,b,c

int nthUglyNumber(int n)
{
	int dp[n];
	dp[0] = 1;
	int i = 0, j = 0, k = 0;
	for (int m = 1; m < n; ++m)
	{
		dp[m] = trimin(dp[i] * 2, dp[j] * 3, dp[k] * 5);
		if (dp[i] * 2 == dp[m])
			++i;
		if (dp[j] * 3 == dp[m])
			++j;
		if (dp[k] * 5 == dp[m])
			++k;
	}
	return dp[n - 1];
}