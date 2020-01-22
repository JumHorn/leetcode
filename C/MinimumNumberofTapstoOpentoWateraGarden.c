#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int minTaps(int n, int* ranges, int rangesSize)
{
	int* dp = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++)
		dp[i] = n + 2;
	dp[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		int max_left = max(0, i - ranges[i]), max_right = min(n, i + ranges[i]);
		for (int j = max_left + 1; j <= max_right; j++)
			dp[j] = min(dp[j], dp[max_left] + 1);
	}
	return dp[n] < n + 2 ? dp[n] : -1;
}
