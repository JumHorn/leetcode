#include <stdlib.h>

void recursive(int num, int N, int K, int *res, int *size)
{
	if (N == 0)
	{
		res[(*size)++] = num;
		return;
	}
	if (K == 0)
		recursive(num * 10 + num % 10, N - 1, K, res, size);
	else
	{
		if (num % 10 + K <= 9)
			recursive(num * 10 + num % 10 + K, N - 1, K, res, size);
		if (num % 10 - K >= 0)
			recursive(num * 10 + num % 10 - K, N - 1, K, res, size);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numsSameConsecDiff(int n, int k, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 2000);
	*returnSize = 0;
	if (n < 2)
		return NULL;
	for (int i = 1; i <= 9; ++i)
		recursive(i, n - 1, k, res, returnSize);
	return res;
}