#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int numFactoredBinaryTrees(int *A, int ASize)
{
	static const int MOD = 1e9 + 7;
	qsort(A, ASize, sizeof(int), cmp);
	long dp[ASize];
	int res = 0;
	for (int k = 0; k < ASize; ++k)
	{
		dp[k] = 1;
		int i = 0, j = k - 1;
		while (i <= j)
		{
			if ((long)A[i] * A[j] == A[k])
			{
				dp[k] = (dp[k] + dp[i] * dp[j] * (i == j ? 1 : 2) % MOD) % MOD;
				++i;
			}
			else if ((long)A[i] * A[j] < A[k])
				++i;
			else
				--j;
		}
		res = (res + dp[k]) % MOD;
	}
	return res;
}