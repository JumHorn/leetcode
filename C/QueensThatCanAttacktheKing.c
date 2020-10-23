#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes)
{
	int board[8][8] = {};
	for (int i = 0; i < queensSize; ++i)
		board[queens[i][0]][queens[i][1]] = 1;
	int** res = (int**)malloc(sizeof(int*) * 8);
	*returnSize = 0;
	int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 1; k < 8; ++k)
			{
				int x = king[0] + k * dx[i], y = king[1] + k * dy[j];
				if (x < 0 || x >= 8 || y < 0 || y >= 8)
					continue;
				if (board[x][y] == 1)
				{
					res[*returnSize] = (int*)malloc(sizeof(int) * 2);
					res[*returnSize][0] = x;
					res[*returnSize][1] = y;
					++*returnSize;
					break;
				}
			}
		}
	}
	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}
