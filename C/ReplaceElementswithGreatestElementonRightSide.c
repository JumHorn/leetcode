#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize)
{
	*returnSize = arrSize;
	if (arrSize == 0)
		return arr;
	int maxsuffix = arr[arrSize - 1];
	arr[arrSize - 1] = -1;
	for (int i = arrSize - 2; i >= 0; --i)
	{
		int tmp = arr[i];
		arr[i] = maxsuffix;
		if (tmp > maxsuffix)
			maxsuffix = tmp;
	}
	return arr;
}
