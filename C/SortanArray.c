#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

//divide and conquer
void merge(int *arr, int *dup, int first, int mid, int last)
{
	for (int i = first, j = mid, d = 0; i < mid || j < last;)
	{
		if (i == mid)
			dup[d++] = arr[j++];
		else if (j == last)
			dup[d++] = arr[i++];
		else
			dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
	}
	memcpy(arr + first, dup, sizeof(int) * (last - first));
}

void divide(int *sum, int *dup, int first, int last)
{
	if (last - first < 2)
		return;
	int mid = (last - first) / 2 + first;
	divide(sum, dup, first, mid);
	divide(sum, dup, mid, last);
	//to do
	merge(sum, dup, first, mid, last);
}
/********end of divide and conquer********/

//quick sort
void quickSort(int *arr, int first, int last)
{
	if (last - first <= 1)
		return;
	int left = first, right = last - 1;
	int pivot = arr[first];
	while (right - left > 0)
	{
		while (right - left > 0 && arr[right] >= pivot)
			--right;
		arr[left] = arr[right];
		while (right - left > 0 && arr[left] <= pivot)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	quickSort(arr, first, left);
	quickSort(arr, left + 1, last);
}
/********end of quick sort********/

//max heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(int *ptr, int size)
{
	if (size <= 0)
		return;
	int val = *ptr, non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1] > ptr[i])
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = ptr[size - 1];
	push_heap(ptr, hole + 1);
	ptr[size - 1] = val;
}

void make_heap(int *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	//merge sort
	// int dup[numsSize];
	// divide(nums, dup, 0, numsSize);

	//quick sort
	// quickSort(nums, 0, numsSize);
	//library quick sort
	//qsort(nums, numsSize, sizeof(int), cmp);
	make_heap(nums, numsSize);
	for (int i = 0; i < numsSize; ++i)
		pop_heap(nums, numsSize - i);
	return nums;
}