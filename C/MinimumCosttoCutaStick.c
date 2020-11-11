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
	int dp[cutsSize + 2][cutsSize + 2];
	memset(dp, 0, sizeof(dp));
	int cut[cutsSize + 2];
	memcpy(&cut[1], cuts, sizeof(int) * cutsSize);
	cut[0] = 0;
	cut[cutsSize + 1] = n;
	qsort(cut, cutsSize + 2, sizeof(int), cmp);
	for (int i = 0; i < cutsSize; ++i)
		dp[i + 1][i + 1] = cut[i + 2] - cut[i];
	for (int l = 1; l < cutsSize; ++l)
	{
		for (int i = 1, j = i + l; j <= cutsSize; ++i, ++j)
		{
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j; ++k)
				dp[i][j] = min(dp[i][j], cut[j + 1] - cut[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
		}
	}
	return dp[1][cutsSize];
}