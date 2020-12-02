#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * 2);
	memset(res, -1, sizeof(int) * 2);

	int lo = 0, hi = numsSize;
	if (numsSize == 0 || target < nums[lo] || target > nums[hi - 1])
		return res;
	//upper bound
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] < target)
			lo = mi + 1;
		else
			hi = mi;
	}
	if (nums[lo] != target)
		return res;

	//lower bound
	res[0] = lo;
	lo = 0, hi = numsSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] <= target)
			lo = mi + 1;
		else
			hi = mi;
	}
	res[1] = lo - 1;
	return res;
}