#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrixIII(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes)
{
	*returnSize = R * C;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		(*returnColumnSizes)[i] = 2;
		res[i] = (int *)malloc(sizeof(int) * 2);
	}
	res[0][0] = r0;
	res[0][1] = c0;
	int path[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int i = r0, j = c0;
	for (int n = 0, index = 1; index < R * C; ++n)
	{
		for (int k = 0; k < n / 2 + 1; ++k)
		{
			i += path[n % 4][0], j += path[n % 4][1];
			if (0 <= i && i < R && 0 <= j && j < C)
			{
				res[index][0] = i;
				res[index][1] = j;
				++index;
			}
		}
	}
	return res;
}