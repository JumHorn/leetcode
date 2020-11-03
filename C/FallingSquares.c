#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *fallingSquares(int **positions, int positionsSize, int *positionsColSize, int *returnSize)
{
	int query[positionsSize];
	memset(query, 0, sizeof(query));
	for (int i = 0; i < positionsSize; ++i)
	{
		int left = positions[i][0];
		int size = positions[i][1];
		int right = left + size;
		query[i] += size;
		for (int j = i + 1; j < positionsSize; j++)
		{
			int left2 = positions[j][0];
			int size2 = positions[j][1];
			int right2 = left2 + size2;
			if (left2 < right && left < right2) //intersect
				query[j] = max(query[j], query[i]);
		}
	}
	*returnSize = positionsSize;
	int *res = (int *)malloc(sizeof(int) * positionsSize);
	int cur = -1;
	for (int i = 0; i < positionsSize; ++i)
	{
		cur = max(cur, query[i]);
		res[i] = cur;
	}
	return res;
}
