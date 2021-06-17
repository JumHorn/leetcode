#include <stdlib.h>

typedef struct pair
{
	int val;
	int index;
} pair;

//divide and conquer
void merge(pair *arr, pair *dup, int first, int mid, int last)
{
	for (int i = first, j = mid, d = 0; i < mid || j < last;)
	{
		if (i == mid)
			dup[d++] = arr[j++];
		else if (j == last)
			dup[d++] = arr[i++];
		else
			dup[d++] = (arr[i].val > arr[j].val) ? arr[j++] : arr[i++];
	}
	memcpy(arr + first, dup, sizeof(pair) * (last - first));
}

void divide(pair *arr, pair *dup, int first, int last)
{
	if (last - first < 2)
		return;
	int mid = (last - first) / 2 + first;
	divide(arr, dup, first, mid);
	divide(arr, dup, mid, last);
	for (int i = first, j = mid, count = 0; i < mid; ++i)
	{
		for (; j < last && arr[i].val + count >= arr[j].val; ++j)
			++count;
		arr[i].val += count;
	}
	merge(arr, dup, first, mid, last);
}
/********end of divide and conquer********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize)
{
	*returnSize = numsSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	// this O(n^2) part can be optimized using merge sort to O(nlogn)
	// for (int i = 0; i < indexSize; ++i)
	// {
	// 	for (int j = i + 1; j < indexSize; ++j)
	// 	{
	// 		if (index[i] >= index[j])
	// 			++index[i];
	// 	}
	// }
	pair arr[indexSize], dup[indexSize];
	for (int i = 0; i < indexSize; ++i)
	{
		arr[i].val = index[i];
		arr[i].index = i;
	}
	divide(arr, dup, 0, numsSize);
	for (int i = 0; i < indexSize; ++i)
		res[arr[i].val] = nums[arr[i].index];
	return res;
}