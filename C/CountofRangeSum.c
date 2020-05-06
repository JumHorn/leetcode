#include <string.h>

void merge(long *sum, long *dup, int start, int mid, int end)
{
	int i = start, j = mid, d = 0;
	while (i < mid && j < end)
		dup[d++] = sum[i] < sum[j] ? sum[i++] : sum[j++];
	while (i < mid)
		dup[d++] = sum[i++];
	while (j < end)
		dup[d++] = sum[j++];
	memcpy(sum + start, dup, (end - start) * sizeof(long));
}

int divide(long *sum, long *dup, int start, int end, int lower, int upper)
{
	if (end - start < 2)
		return 0;
	int res = 0, mid = (end - start) / 2 + start;
	res += divide(sum, dup, start, mid, lower, upper);
	res += divide(sum, dup, mid, end, lower, upper);
	for (int i = start, j = mid, k = mid; i < mid; i++)
	{
		while (j < end && sum[j] - sum[i] < lower)
			j++;
		while (k < end && sum[k] - sum[i] <= upper)
			k++;
		res += k - j;
	}
	merge(sum, dup, start, mid, end);
	return res;
}

int countRangeSum(int *nums, int numsSize, int lower, int upper)
{
	long sum[numsSize + 1], dup[numsSize + 1];
	sum[0] = 0;
	for (int i = 0; i < numsSize; i++)
		sum[i + 1] = sum[i] + nums[i];
	return divide(sum, dup, 0, numsSize + 1, lower, upper);
}