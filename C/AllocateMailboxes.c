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

int minDistance(int *houses, int housesSize, int k)
{
	int N = housesSize;
	qsort(houses, N, sizeof(int), cmp);
	int dp[N + 1][k + 1];
	memset(dp, 1 << 6, sizeof(dp));
	int cost[N][N];
	memset(cost, 0, sizeof(cost));
	for (int l = 1; l < N; ++l)
	{
		for (int i = 0, j = l; j < N; ++i, ++j)
			cost[i][j] = cost[i + 1][j - 1] + houses[j] - houses[i];
	}
	//dp
	for (int i = 0; i <= k; ++i)
		dp[0][i] = 0;
	for (int l = 1; l <= k; ++l)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= i; ++j)
				dp[i + 1][l] = min(dp[i + 1][l], dp[j][l - 1] + cost[j][i]);
		}
	}
	return dp[N][k];
}