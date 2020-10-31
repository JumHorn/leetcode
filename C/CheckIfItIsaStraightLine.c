#include <stdbool.h>

bool threePointOnALine(int *p0, int *p1, int *p2)
{
	return (p0[0] - p1[0]) * (p0[1] - p2[1]) ==
		   (p0[0] - p2[0]) * (p0[1] - p1[1]);
}

bool checkStraightLine(int **coordinates, int coordinatesSize, int *coordinatesColSize)
{
	for (int i = 2; i < coordinatesSize; ++i)
	{
		if (!threePointOnALine(coordinates[0], coordinates[1], coordinates[i]))
			return false;
	}
	return true;
}