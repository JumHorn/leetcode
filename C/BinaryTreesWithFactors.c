#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int binarySearch(long (*dp)[2], int size, int val)
{
	int lo = 0, hi = size;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (dp[mi][0] < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return dp[lo][0] == val ? dp[lo][1] : 0;
}

int numFactoredBinaryTrees(int *A, int ASize)
{
	static const int MOD = 1e9 + 7;
	qsort(A, ASize, sizeof(int), cmp);
	long dp[ASize][2]; //{key,count}
	int res = 0, size = 0;
	for (int i = 0; i < ASize; ++i)
	{
		dp[size][0] = A[i];
		dp[size][1] = 1;
		for (int j = 0; j < size; ++j)
		{
			if (A[i] % dp[j][0] == 0)
			{
				int val = A[i] / dp[j][0];
				dp[size][1] = (dp[size][1] + dp[j][1] * binarySearch(dp, size, val) % MOD) % MOD;
			}
		}
		res = (res + dp[size++][1]) % MOD;
	}
	return res;
}