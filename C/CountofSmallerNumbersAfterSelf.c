#include <stdlib.h>
#include <string.h>

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

void divide(pair *arr, pair *dup, int first, int last, int *res)
{
	if (last - first < 2)
		return;
	int mid = (last - first) / 2 + first;
	divide(arr, dup, first, mid, res);
	divide(arr, dup, mid, last, res);
	for (int i = first, j = mid; i < mid; ++i)
	{
		while (j < last && arr[i].val > arr[j].val)
			++j;
		res[arr[i].index] += j - mid;
	}
	merge(arr, dup, first, mid, last);
}
/********end of divide and conquer********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countSmaller(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	if (numsSize == 0)
		return NULL;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * numsSize);
	pair arr[numsSize], dup[numsSize];
	for (int i = 0; i < numsSize; ++i)
	{
		arr[i].val = nums[i];
		arr[i].index = i;
	}
	divide(arr, dup, 0, numsSize, res);
	return res;
}