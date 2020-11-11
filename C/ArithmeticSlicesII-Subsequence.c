#include <limits.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	int *l = (int *)lhs, *r = (int *)rhs;
	if (l[0] != r[0])
		return l[0] < r[0] ? -1 : 1;
	return l[1] - r[1];
}

int binarySeach(int (*arr)[2], int arrSize, int val)
{
	if (arrSize == 0)
		return -1;
	int lo = 0, hi = arrSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi][0] < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return arr[lo][0] == val ? lo : -1;
}

int numberOfArithmeticSlices(int *A, int ASize)
{
	if (ASize == 0)
		return 0;
	int arr[ASize][2]; //{value,index}
	for (int i = 0; i < ASize; ++i)
	{
		arr[i][0] = A[i];
		arr[i][1] = i;
	}
	qsort(arr, ASize, sizeof(arr[0]), cmp);
	int dp[ASize][ASize], res = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < ASize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			long pre = 2L * A[j] - A[i]; //sequence pre.A[j].A[i]
			if (pre < INT_MIN || pre > INT_MAX)
				continue;
			int k = binarySeach(arr, ASize, pre);
			if (k == -1)
				continue;
			for (; k < ASize && arr[k][1] < j && arr[k][0] == pre; ++k)
				dp[i][j] += dp[j][arr[k][1]] + 1;
			res += dp[i][j];
		}
	}
	return res;
}