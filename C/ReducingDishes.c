#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int maxSatisfaction(int *satisfaction, int satisfactionSize)
{
	int N = satisfactionSize;
	int dp[N + 1], dp_copy[N + 1];
	qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
	memset(dp, 1u << 7, sizeof(dp));
	dp[0] = 0;
	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		memcpy(dp_copy, dp, sizeof(dp));
		for (int j = 0; j <= i; ++j)
		{
			dp[j + 1] = max(dp_copy[j + 1], dp_copy[j] + satisfaction[i] * (j + 1));
			res = max(res, dp[j + 1]);
		}
	}
	return res;
}