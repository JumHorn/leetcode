#include <string.h>

int findLatestStep(int* arr, int arrSize, int m)
{
	int res = -1;
	if (arrSize == m)
		return arrSize;
	int length[arrSize + 2];
	memset(length, 0, sizeof(length));
	for (int i = 0; i < arrSize; ++i)
	{
		int a = arr[i], left = length[a - 1], right = length[a + 1];
		length[a - left] = length[a + right] = left + right + 1;
		if (left == m || right == m)
			res = i;
	}
	return res;
}
