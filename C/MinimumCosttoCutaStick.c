#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int minCost(int n, int *cuts, int cutsSize)
{
	int N = cutsSize + 2, dp[N][N], cut[N], INF = 1e9;
	memset(dp, 0, sizeof(dp));
	memcpy(&cut[1], cuts, sizeof(int) * cutsSize);
	cut[0] = 0;
	cut[N - 1] = n;
	qsort(cut, N, sizeof(int), cmp);
	for (int i = N - 3; i >= 0; --i)
	{
		for (int j = i + 2; j < N; ++j)
		{
			dp[i][j] = INF;
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = min(dp[i][j], cut[j] - cut[i] + dp[i][k] + dp[k][j]);
		}
	}
	return dp[0][N - 1];
}