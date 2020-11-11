#include <limits.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int findRadius(int *houses, int housesSize, int *heaters, int heatersSize)
{
	qsort(houses, housesSize, sizeof(int), cmp);
	qsort(heaters, heatersSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0, j = 0; i < housesSize; ++i)
	{
		while (j < heatersSize && houses[i] > heaters[j])
			++j;
		int radius = INT_MAX;
		if (j < heatersSize)
			radius = min(radius, heaters[j] - houses[i]);
		if (j > 0)
			radius = min(radius, houses[i] - heaters[j - 1]);
		res = max(res, radius);
	}
	return res;
}