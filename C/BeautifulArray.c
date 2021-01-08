#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *beautifulArray(int N, int *returnSize)
{
	*returnSize = N;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int next[N];
	res[0] = 1;
	for (int resSize = 1, nextSize = 0; resSize < N; resSize = nextSize)
	{
		nextSize = 0;
		for (int i = 0; i < resSize; ++i)
		{
			if (res[i] * 2 - 1 <= N)
				next[nextSize++] = res[i] * 2 - 1;
		}
		for (int i = 0; i < resSize; ++i)
		{
			if (res[i] * 2 <= N)
				next[nextSize++] = res[i] * 2;
		}
		memcpy(res, next, sizeof(next));
	}
	return res;
}
