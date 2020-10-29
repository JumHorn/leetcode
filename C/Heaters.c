#include <limits.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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
