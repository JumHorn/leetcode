#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
	*returnSize = 0;
	if (matrixSize == 0 || *matrixColSize == 0)
		return NULL;
	int M = matrixSize, N = *matrixColSize;
	int* res = (int*)malloc(sizeof(int) * M * N);
	int i = 0, j = 0;
	while (*returnSize < M * N)
	{
		res[(*returnSize)++] = matrix[i][j];
		if ((i + j) % 2 == 0)
		{
			if (j == N - 1)
				++i;
			else if (i == 0)
				++j;
			else
			{
				--i;
				++j;
			}
		}
		else
		{
			if (i == M - 1)
				++j;
			else if (j == 0)
				++i;
			else
			{
				++i;
				--j;
			}
		}
	}
	return res;
}
