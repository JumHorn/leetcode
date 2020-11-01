#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize)
{
	int hash[2001] = {0};
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] * 2 >= -1000 && arr[i] * 2 <= 1000 && hash[arr[i] * 2 + 1000] == 1)
			return true;
		if (arr[i] % 2 == 0 && hash[arr[i] / 2 + 1000] == 1)
			return true;
		hash[arr[i] + 1000] = 1;
	}
	return false;
}
