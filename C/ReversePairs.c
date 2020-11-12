#include <string.h>

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

int divide(int *arr, int *dup, int first, int last)
{
	if (last - first < 2)
		return 0;
	int mid = (last - first) / 2 + first, res = 0;
	res += divide(arr, dup, first, mid);
	res += divide(arr, dup, mid, last);
	for (int i = first, j = mid; i < mid; ++i)
	{
		while (j < last && (long)arr[i] > 2L * arr[j])
			++j;
		res += j - mid;
	}
	merge(arr, dup, first, mid, last);
	return res;
}
/********end of divide and conquer********/

int reversePairs(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int dup[numsSize];
	return divide(nums, dup, 0, numsSize);
}