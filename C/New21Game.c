#include <stdlib.h>

double new21Game(int N, int K, int W)
{
	if (K == 0 || N >= K + W)
		return 1.0;
	double* dp = (double*)malloc(sizeof(double) * (N + 1));
	dp[0] = 1.0;
	double sum = 1.0, res = 0.0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = sum / W;
		if (i < K)
			sum += dp[i];
		else
			res += dp[i];
		if (i - W >= 0)
			sum -= dp[i - W];
	}
	return res;
}

