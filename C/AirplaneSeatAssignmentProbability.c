#include <stdlib.h>
#include <string.h>

double nthPersonGetsNthSeat(int n)
{
	double *dp = (double *)malloc(sizeof(double) * n);
	memset(dp, 0, sizeof(double) * n);
	dp[0] = 1.0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			dp[i] += dp[j];
		dp[i] /= i + 1;
	}
	return dp[n - 1];
}

