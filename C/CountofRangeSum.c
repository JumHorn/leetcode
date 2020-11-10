#include <string.h>

//divide and conquer
void merge(long *arr, long *dup, int first, int mid, int last)
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
	memcpy(arr + first, dup, sizeof(long) * (last - first));
}

int divide(long *arr, long *dup, int first, int last, int lower, int upper)
{
	if (last - first < 2)
		return 0;
	int mid = first + (last - first) / 2, res = 0;
	res += divide(arr, dup, first, mid, lower, upper);
	res += divide(arr, dup, mid, last, lower, upper);
	for (int i = first, j = mid, k = mid; i < mid; ++i)
	{
		while (j < last && arr[j] - arr[i] < lower)
			++j;
		while (k < last && arr[k] - arr[i] <= upper)
			++k;
		res += k - j;
	}
	merge(arr, dup, first, mid, last);
	return res;
}
/********end of divide and conquer********/

int countRangeSum(int *nums, int numsSize, int lower, int upper)
{
	long prefixsum[numsSize + 1], dup[numsSize + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		prefixsum[i + 1] = prefixsum[i] + nums[i];
	return divide(prefixsum, dup, 0, numsSize + 1, lower, upper);
}