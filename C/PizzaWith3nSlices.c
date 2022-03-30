#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubSlice(int *slice, int n, int first, int last)
{
	int N = last - first;
	int dp[N + 2][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0, k = first; k < last; ++i, ++k)
	{
		for (int j = 0; j < n && j <= i; ++j)
			dp[i + 2][j + 1] = max(dp[i + 1][j + 1], slice[k] + dp[i][j]);
	}
	return dp[N + 1][n];
}

int maxSizeSlices(int *slices, int slicesSize)
{
	int n = slicesSize / 3;
	return max(maxSubSlice(slices, n, 0, slicesSize - 1), maxSubSlice(slices, n, 1, slicesSize));
}