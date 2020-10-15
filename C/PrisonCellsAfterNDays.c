#include <stdlib.h>
#include <string.h>

/*
In fact, cells have only 2 ^ 6 = 64 different states.
And there will be a loop.
The period T=14
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize)
{
	int T = 14;
	*returnSize = cellsSize;
	for (N = (N - 1) % T; N >= 0; --N)
	{
		int next[8] = {0};
		for (int i = 1; i < 7; ++i)
			next[i] = (1 ^ cells[i - 1] ^ cells[i + 1]);
		memcpy(cells, next, sizeof(next));
	}
	return cells;
}
