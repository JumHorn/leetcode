#include <string.h>

void merge(int *nums, int *dup, int start, int mid, int end)
{
	int i = start, j = mid, d = 0;
	while (i < mid && j < end)
		dup[d++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	while (i < mid)
		dup[d++] = nums[i++];
	while (j < end)
		dup[d++] = nums[j++];
	memcpy(nums + start, dup, (end - start) * sizeof(int));
}

int divide(int *nums, int *dup, int start, int end)
{
	if (end - start < 2)
		return 0;
	int res = 0, mid = (end - start) / 2 + start;
	res += divide(nums, dup, start, mid);
	res += divide(nums, dup, mid, end);
	for (int i = start, j = mid; i < mid; i++)
	{
		while (j < end && (long)nums[i] > 2 * (long)nums[j])
			j++;
		res += j - mid;
	}
	merge(nums, dup, start, mid, end);
	return res;
}

int reversePairs(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int dup[numsSize];
	return divide(nums, dup, 0, numsSize);
}