#include <stdlib.h>
#include <string.h>

//malloc result
int **mallocRes(int (*data)[2], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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
/********malloc result********/

void dfs(int **matrix, int M, int N, int (*color)[N], int row, int col)
{
	if (color[row][col] != 0)
		return;
	color[row][col] = 1;
	if (row - 1 >= 0 && matrix[row - 1][col] >= matrix[row][col])
		dfs(matrix, M, N, color, row - 1, col);
	if (col - 1 >= 0 && matrix[row][col - 1] >= matrix[row][col])
		dfs(matrix, M, N, color, row, col - 1);
	if (row + 1 < M && matrix[row + 1][col] >= matrix[row][col])
		dfs(matrix, M, N, color, row + 1, col);
	if (col + 1 < N && matrix[row][col + 1] >= matrix[row][col])
		dfs(matrix, M, N, color, row, col + 1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **pacificAtlantic(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int **returnColumnSizes)
{
	int staticRes[10000][2], staticColSize[10000];
	*returnSize = 0;
	if (matrixSize == 0 || *matrixColSize == 0)
		return NULL;
	int M = matrixSize, N = *matrixColSize;
	int color1[M][N], color2[M][N];
	memset(color1, 0, sizeof(color1));
	memset(color2, 0, sizeof(color2));

	for (int i = 0; i < M; ++i)
	{
		dfs(matrix, M, N, color1, i, 0);
		dfs(matrix, M, N, color2, i, N - 1);
	}
	for (int j = 0; j < N; ++j)
	{
		dfs(matrix, M, N, color1, 0, j);
		dfs(matrix, M, N, color2, M - 1, j);
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (color1[i][j] == 1 && color2[i][j] == 1)
			{
				staticRes[*returnSize][0] = i;
				staticRes[*returnSize][1] = j;
				++*returnSize;
			}
		}
	}
	for (int i = 0; i < *returnSize; ++i)
		staticColSize[i] = 2;
	return mallocRes(staticRes, *returnSize, staticColSize, returnSize, returnColumnSizes);
}