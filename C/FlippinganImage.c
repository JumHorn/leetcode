#include <stdlib.h>
#include <string.h>

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **flipAndInvertImage(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes)
{
	int M = ASize, N = *AColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j * 2 < N; ++j)
		{
			if (A[i][j] == A[i][N - j - 1])
			{
				A[i][j] ^= 1;
				A[i][N - j - 1] = A[i][j];
			}
		}
	}
	return mallocRes(A, ASize, AColSize, returnSize, returnColumnSizes);
}