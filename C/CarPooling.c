#include <stdlib.h>

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
	int map[1001] = {0}, start = 1001, end = 0;
	for (int i = 0; i < tripsSize; i++)
	{
		map[trips[i][1]] -= trips[i][0];
		map[trips[i][2]] += trips[i][0];
		if (trips[i][1] < start)
			start = trips[i][1];
		if (trips[i][2] > end)
			end = trips[i][2];
	}
	for (int i = start; i <= end; i++)
	{
		capacity += map[i];
		if (capacity < 0)
			return false;
	}
	return true;
}

