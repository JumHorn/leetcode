#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **allCellsDistOrder(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes)
{
	*returnSize = R * C;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));

	res[0][0] = r0;
	res[0][1] = c0;
	int seen[R][C];
	memset(seen, 0, sizeof(seen));
	seen[r0][c0] = 1;
	//BFS
	for (int i = 0, j = 1; j < R * C; ++i)
	{
		int x = res[i][0], y = res[i][1];
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int k = 0; k < 4; ++k)
		{
			int dx = x + path[k], dy = y + path[k + 1];
			if (dx >= 0 && dx < R && dy >= 0 && dy < C && seen[dx][dy] == 0)
			{
				seen[dx][dy] = 1;
				res[j][0] = dx;
				res[j][1] = dy;
				++j;
			}
		}
	}
	return res;
}