#include <math.h>
#include <stdlib.h>

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
/********malloc result********/

void dfs(int **grid, int M, int N, int row, int col, int color)
{
	if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != color)
		return;
	grid[row][col] = -color;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		dfs(grid, M, N, row + path[i], col + path[i + 1], color);
	if (row > 0 && row < M - 1 && col > 0 && col < N - 1 &&
		color == abs(grid[row - 1][col]) &&
		color == abs(grid[row + 1][col]) &&
		color == abs(grid[row][col - 1]) &&
		color == abs(grid[row][col + 1]))
		grid[row][col] = color;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **colorBorder(int **grid, int gridSize, int *gridColSize, int r0, int c0, int color, int *returnSize, int **returnColumnSizes)
{
	dfs(grid, gridSize, *gridColSize, r0, c0, grid[r0][c0]);
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			if (grid[i][j] < 0)
				grid[i][j] = color;
		}
	}
	return mallocRes(grid, gridSize, gridColSize, returnSize, returnColumnSizes);
}