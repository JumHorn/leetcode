#include <stdbool.h>
#include <string.h>

bool canArrange(int* arr, int arrSize, int k)
{
	int v[k];
	memset(v, 0, sizeof(v));
	for (int i = 0; i < arrSize; ++i)
	{
		int index = arr[i] % k;
		if (index < 0)
			index += k;
		++v[index];
	}
	for (int i = 1; i < k / 2 + 1; ++i)
	{
		if (v[i] != v[k - i])
			return false;
	}
	if (k % 2 == 0 && v[k / 2] % 2 != 0)
		return false;
	return true;
}
