#include <stdlib.h>

/*
counting sort
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	int count[1001] = {0};
	for (int i = 0; i < arr1Size; ++i)
		++count[arr1[i]];
	*returnSize = arr1Size;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int index = 0;
	for (int i = 0; i < arr2Size; ++i)
	{
		while (--count[arr2[i]] >= 0)
			res[index++] = arr2[i];
	}
	for (int i = 0; i <= 1000; ++i)
	{
		while (--count[i] >= 0)
			res[index++] = i;
	}
	return res;
}
