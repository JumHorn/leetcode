#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize)
{
	int window = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		window += arr[i] % 2;
		if (i >= 3)
			window -= arr[i - 3] % 2;
		if (window == 3)
			return true;
	}
	return false;
}
