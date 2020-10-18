#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numMovesStonesII(int *stones, int stonesSize, int *returnSize)
{
	qsort(stones, stonesSize, sizeof(int), cmp);
	int i = 0, N = stonesSize, low = N;
	int high = max(stones[N - 1] - N + 2 - stones[1], stones[N - 2] - stones[0] - N + 2);
	for (int j = 0; j < N; ++j)
	{
		while (stones[j] - stones[i] >= N)
			++i;
		if (j - i + 1 == N - 1 && stones[j] - stones[i] == N - 2)
			low = min(low, 2);
		else
			low = min(low, N - (j - i + 1));
	}
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	res[0] = low;
	res[1] = high;
	return res;
}
