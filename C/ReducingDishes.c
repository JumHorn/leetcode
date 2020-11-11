#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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