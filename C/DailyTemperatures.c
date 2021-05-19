#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
	*returnSize = TSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	int stack[TSize], top = -1;
	for (int i = 0; i < TSize; ++i)
	{
		for (; top != -1 && T[stack[top]] < T[i]; --top)
			res[stack[top]] = i - stack[top];
		stack[++top] = i;
	}
	return res;
}