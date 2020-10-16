#include <stdlib.h>

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)

void reverse(int *arr, int first, int last)
{
	while (first < last)
	{
		swap(arr[first], arr[last]);
		++first;
		--last;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *pancakeSort(int *arr, int arrSize, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * (arrSize * 2));
	*returnSize = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		int index = 0; //max index
		for (int j = 1; j < arrSize - i; ++j)
		{
			if (arr[j] > arr[index])
				index = j;
		}
		if (index != arrSize - i - 1)
		{
			res[(*returnSize)++] = index + 1;
			reverse(arr, 0, index);
			res[(*returnSize)++] = arrSize - i;
			reverse(arr, 0, arrSize - i - 1);
		}
	}
	return res;
}