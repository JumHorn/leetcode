#include <stdlib.h>

int cmp(const void* lhs, const void* rhs)
{
	int* t1 = *(int**)lhs;
	int* t2 = *(int**)rhs;
	if (t1[1] != t2[1])
		return t1[1] - t2[1];
	return t1[2] - t2[2];
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
	qsort(trips, tripsSize, sizeof(int*), cmp);
	int map[1001] = {0};
	for (int i = 0, j = 0; i < tripsSize; i++)
	{
		while (j <= trips[i][1])
			capacity += map[j++];
		if (capacity < trips[i][0])
			return false;
		capacity -= trips[i][0];
		map[trips[i][2]] += trips[i][0];
	}
	return true;
}

