#include <stdlib.h>
#include <string.h>

void dfs(int n, int value, int *data, int *index)
{
	if (value > n)
		return;
	data[(*index)++] = value;
	dfs(n, value * 10, data, index);
	if (value % 10 != 9)
		dfs(n, value + 1, data, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *lexicalOrder(int n, int *returnSize)
{
	*returnSize = n;
	int *res = (int *)malloc(sizeof(int) * (*returnSize)), index = 0;
	dfs(n, 1, res, &index);
	return res;
}