#include <stdbool.h>

bool validMountainArray(int *A, int ASize)
{
	if (ASize < 3)
		return false;
	int i = 1;
	while (i < ASize && A[i - 1] < A[i])
		++i;
	if (i == 1 || i == ASize)
		return false;
	while (i < ASize && A[i - 1] > A[i])
		++i;
	return i == ASize;
}