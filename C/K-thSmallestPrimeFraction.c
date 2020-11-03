#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *kthSmallestPrimeFraction(int *A, int ASize, int K, int *returnSize)
{
	double lo = 0, hi = 1;
	int p = 0, q = 1;
	for (int n = ASize, count = 0;; count = 0, p = 0)
	{
		double mi = (hi - lo) / 2 + lo;
		for (int i = 0, j = n - 1; i < n; ++i)
		{
			while (j >= 0 && A[i] > mi * A[n - 1 - j])
				j--;
			count += (j + 1);

			if (j >= 0 && p * A[n - 1 - j] < q * A[i])
			{
				p = A[i];
				q = A[n - 1 - j];
			}
		}

		if (count == K)
			break;
		if (count < K)
			lo = mi;
		else
			hi = mi;
	}
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	res[0] = p;
	res[1] = q;
	return res;
}
