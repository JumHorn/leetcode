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

void dfs(int **image, int M, int N, int row, int col, int oldColor, int newColor)
{
	if (row < 0 || row >= M || col < 0 || col >= N || image[row][col] != oldColor)
		return;
	image[row][col] = newColor;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		dfs(image, M, N, row + path[i], col + path[i + 1], oldColor, newColor);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize, int **returnColumnSizes)
{
	if (image[sr][sc] != newColor)
		dfs(image, imageSize, *imageColSize, sr, sc, image[sr][sc], newColor);
	return mallocRes(image, imageSize, imageColSize, returnSize, returnColumnSizes);
}