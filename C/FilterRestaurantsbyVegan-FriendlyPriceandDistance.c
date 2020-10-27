#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[1] != r[1])
		return r[1] - l[1];
	return r[0] - l[0];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *filterRestaurants(int **restaurants, int restaurantsSize, int *restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int *returnSize)
{
	int *filter[restaurantsSize], filterSize = 0;
	for (int i = 0; i < restaurantsSize; ++i)
	{
		if (restaurants[i][2] < veganFriendly)
			continue;
		if (restaurants[i][3] > maxPrice)
			continue;
		if (restaurants[i][4] > maxDistance)
			continue;
		filter[filterSize++] = restaurants[i];
	}
	qsort(filter, filterSize, sizeof(int *), cmp);
	int *res = (int *)malloc(sizeof(int) * restaurantsSize);
	*returnSize = 0;
	for (int i = 0; i < filterSize; ++i)
		res[(*returnSize)++] = filter[i][0];
	return res;
}