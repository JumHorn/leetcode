#include <stdlib.h>

double new21Game(int N, int K, int W)
{
	if (K == 0 || N >= K + W)
		return 1.0;
	double* dp = (double*)malloc(sizeof(double) * (N + 1));
	dp[0] = 1.0;
	double res = 0.0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 0.0;
		int min = 0;
		if (i - W > min)
			min = i - W;
		for (int j = i - 1; j > min; j--)
			dp[i] += dp[j];
		for (int j = i; j > K; j--)
			dp[i] -= dp[i - (j - K)];
		dp[i] /= W;
		if (i >= K)
			res += dp[i];
	}
	return res;
}

