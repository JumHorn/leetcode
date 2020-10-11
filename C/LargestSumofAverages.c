
#define max(a, b) (((a) > (b)) ? (a) : (b))

double largestSumOfAverages(int* A, int ASize, int K)
{
	int prefixsum[ASize + 1];
	prefixsum[0] = 0;
	double dp[ASize][K];
	for (int i = 0; i < ASize; ++i)
		prefixsum[i + 1] = prefixsum[i] + A[i];
	for (int k = 0; k < K; ++k)
	{
		for (int i = 0; i < ASize; ++i)
		{
			dp[i][k] = prefixsum[i + 1] * 1.0 / (i + 1);
			for (int j = k - 1; j < i && k > 0; ++j)
				dp[i][k] = max(dp[i][k], dp[j][k - 1] + (prefixsum[i + 1] - prefixsum[j + 1]) * 1.0 / (i - j));
		}
	}
	return dp[ASize - 1][K - 1];
}
