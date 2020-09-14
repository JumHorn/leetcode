#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
	*returnSize = n;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = n;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));

	int range[] = {0, n, 0, n}; //left,right,bottom,top
	int i = 0, j = 0, d = 0;
	int path[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int rangechange[][4] = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 0, 0, -1}};
	for (int k = 0; k < n * n; ++k)
	{
		res[i][j] = k + 1;
		int dx = i + path[d][0], dy = j + path[d][1];
		if (dx >= range[2] && dx < range[3] && dy >= range[0] && dy < range[1])
		{
			i = dx;
			j = dy;
		}
		else
		{
			d = (d + 1) % 4;
			i += path[d][0];
			j += path[d][1];
			for (int i = 0; i < 4; ++i)
				range[i] += rangechange[d][i];
		}
	}
	return res;
}