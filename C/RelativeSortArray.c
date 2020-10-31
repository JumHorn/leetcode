#include <stdlib.h>
#include <string.h>

/*
counting sort
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	int count1[1001] = {0}, count2[1001];
	memset(count2, -1, sizeof(count2));
	for (int i = 0; i < arr2Size; ++i)
		count2[arr2[i]] = 0;
	for (int i = 0; i < arr1Size; ++i)
		count2[arr1[i]] == -1 ? ++count1[arr1[i]] : ++count2[arr1[i]];
	*returnSize = arr1Size;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int resIndex = *returnSize;
	for (int i = 1000; i >= 0; --i)
	{
		if (count2[i] == -1)  //move to end
		{
			while (--count1[i] >= 0)
				res[--resIndex] = i;
		}
	}
	for (int i = arr2Size - 1; i >= 0; --i)
	{
		while (--count2[arr2[i]] >= 0)
			res[--resIndex] = arr2[i];
	}
	return res;
}
