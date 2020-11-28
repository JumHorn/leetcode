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
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
			cost[i][j] = cost[i + 1][j - 1] + houses[j] - houses[i];
	}
	//dp
	for (int i = 0; i <= k; ++i)
		dp[0][i] = 0;
	for (int l = 0; l < k; ++l)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i <= j; ++i)
				dp[j + 1][l + 1] = min(dp[j + 1][l + 1], dp[i][l] + cost[i][j]);
		}
	}
	return dp[N][k];
}