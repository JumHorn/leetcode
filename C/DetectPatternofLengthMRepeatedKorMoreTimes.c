#include <stdbool.h>

bool containsPattern(int* arr, int arrSize, int m, int k)
{
	for (int i = 0, count = 0; i + m < arrSize; ++i)
	{
		if (arr[i] != arr[i + m])
			count = -1;
		if (++count == (k - 1) * m)
			return true;
	}
	return false;
}
