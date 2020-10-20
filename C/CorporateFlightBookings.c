#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * (n + 1));
	memset(res, 0, sizeof(int) * (n + 1));
	*returnSize = n;
	for (int i = 0; i < bookingsSize; ++i)
	{
		res[bookings[i][0] - 1] += bookings[i][2];
		res[bookings[i][1]] -= bookings[i][2];
	}
	for (int i = 1; i < n; ++i)
		res[i] += res[i - 1];
	return res;
}
