#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int maxPlaceCount(int *position, int positionSize, int interval)
{
	int res = 1, distance = 0;
	for (int i = 1; i < positionSize; ++i)
	{
		distance += position[i] - position[i - 1];
		if (distance >= interval)
		{
			distance = 0;
			++res;
		}
	}
	return res;
}

int maxDistance(int *position, int positionSize, int m)
{
	qsort(position, positionSize, sizeof(int), cmp);
	int lo = 0, hi = (position[positionSize - 1] - position[0]) / (m - 1) + 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (maxPlaceCount(position, positionSize, mi) >= m)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}