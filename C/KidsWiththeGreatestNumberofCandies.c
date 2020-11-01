#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
	*returnSize = candiesSize;
	bool* res = (bool*)malloc(sizeof(bool) * (*returnSize));
	int greatest = 0;
	for (int i = 0; i < candiesSize; ++i)
		greatest = max(greatest, candies[i]);
	for (int i = 0; i < candiesSize; ++i)
		res[i] = (extraCandies + candies[i] >= greatest);
	return res;
}
