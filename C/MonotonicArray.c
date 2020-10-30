#include <stdbool.h>

bool isMonotonic(int* A, int ASize)
{
	bool increasing = true, decreasing = true;
	for (int i = 1; i < ASize; ++i)
	{
		if (A[i - 1] > A[i])
			increasing = false;
		if (A[i - 1] < A[i])
			decreasing = false;
	}

	return increasing || decreasing;
}
