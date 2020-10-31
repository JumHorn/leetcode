#include <stdlib.h>

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
	int **res = mallocRes(grid, gridSize, gridColSize, returnSize, returnColumnSizes);
	int M = gridSize, N = *gridColSize;
	k %= M * N;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int index = (i * N + j + k) % (M * N);
			int x = index / N, y = index % N;
			res[x][y] = grid[i][j];
		}
	}
	return res;
}