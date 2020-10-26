#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)rhs - *(int *)lhs;
}

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
int **diagonalSort(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes)
{
	int **res = mallocRes(mat, matSize, matColSize, returnSize, returnColumnSizes);
	int M = matSize, N = *matColSize;
	int data[M + N][max(M, N)], dataColSize[M + N];
	memset(dataColSize, 0, sizeof(dataColSize));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			data[i - j + N][dataColSize[i - j + N]++] = mat[i][j];
	}
	for (int i = 1; i < M + N; ++i)
		qsort(data[i], dataColSize[i], sizeof(int), cmp); //descending
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			res[i][j] = data[i - j + N][--dataColSize[i - j + N]];
	}
	return res;
}