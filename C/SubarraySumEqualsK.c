#include <stdlib.h>
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

int divide(int *arr, int *dup, int first, int last, int diff)
{
	if (last - first < 2)
		return 0;
	int mid = (last - first) / 2 + first, res = 0;
	res += divide(arr, dup, first, mid, diff);
	res += divide(arr, dup, mid, last, diff);

	for (int i = first, j = mid, k = mid; i < mid; ++i)
	{
		while (j < last && arr[j] - arr[i] < diff)
			++j;
		while (k < last && arr[k] - arr[i] <= diff)
			++k;
		res += k - j;
	}

	merge(arr, dup, first, mid, last);
	return res;
}
/********end of divide and conquer********/

int subarraySum(int *nums, int numsSize, int k)
{
	int prefixsum = 0;
	int arr[numsSize + 1], dup[numsSize + 1];
	arr[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		arr[i + 1] = arr[i] + nums[i];
	return divide(arr, dup, 0, numsSize + 1, k);
}
