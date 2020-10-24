#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
	int m = tomatoSlices, n = cheeseSlices;
	*returnSize = 0;
	if (m < 2 * n || (m - 2 * n) % 2 != 0 || 4 * n - m < 0)
		return NULL;
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	res[0] = (m - 2 * n) / 2;
	res[1] = n - (m - 2 * n) / 2;
	return res;
}
