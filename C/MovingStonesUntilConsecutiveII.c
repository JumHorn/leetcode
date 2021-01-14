#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numMovesStonesII(int *stones, int stonesSize, int *returnSize)
{
	qsort(stones, stonesSize, sizeof(int), cmp);
	int N = stonesSize, low = N;
	int high = max(stones[N - 1] - N + 2 - stones[1], stones[N - 2] - stones[0] - N + 2);
	for (int i = 0, j = 0; j < N; ++j)
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