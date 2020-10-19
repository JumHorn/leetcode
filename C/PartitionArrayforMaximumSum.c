#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSumAfterPartitioning(int *arr, int arrSize, int k)
{
	int dp[arrSize + 1];
	memset(dp, 0, sizeof(int) * (arrSize + 1));
	for (int i = 0; i < arrSize; ++i)
	{
		int maxval = arr[i];
		for (int j = i; j >= max(0, i - k + 1); --j)
		{
			maxval = max(maxval, arr[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + (i - j + 1) * maxval);
		}
	}
	return dp[arrSize];
}