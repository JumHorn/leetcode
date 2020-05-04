#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void maxKNumber(int *nums, int size, int k, int *res)
{
	if (k == 0)
		return;
	int top = -1;
	for (int i = 0; i < size; i++)
	{
		while (top != -1 && top + 1 + size - i > k && res[top] < nums[i])
			--top;
		res[++top] = nums[i];
	}
}

bool compare(int *lhs, int *rhs, int size)
{
	for (int i = 0; i < size; i++)
		if (lhs[i] != rhs[i])
			return lhs[i] < rhs[i];
	return false;
}

void merge(int *left, int leftsize, int *right, int rightsize, int *dup, int r, int *res, int k)
{
	if (leftsize == 0)
	{
		memcpy(dup + r, right, sizeof(int) * rightsize);
		if (compare(res, dup, k))
			memcpy(res, dup, sizeof(int) * k);
		return;
	}
	if (rightsize == 0)
	{
		memcpy(dup + r, left, sizeof(int) * leftsize);
		if (compare(res, dup, k))
			memcpy(res, dup, sizeof(int) * k);
		return;
	}

	if (left[0] > right[0])
	{
		dup[r] = left[0];
		merge(left + 1, leftsize - 1, right, rightsize, dup, r + 1, res, k);
	}
	else if (left[0] < right[0])
	{
		dup[r] = right[0];
		merge(left, leftsize, right + 1, rightsize - 1, dup, r + 1, res, k);
	}
	else
	{
		dup[r] = left[0];
		merge(left + 1, leftsize - 1, right, rightsize, dup, r + 1, res, k);
		dup[r] = right[0];
		merge(left, leftsize, right + 1, rightsize - 1, dup, r + 1, res, k);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxNumber(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize)
{
	*returnSize = k;
	int *res = (int *)malloc(sizeof(int) * k);
	memset(res, 0, sizeof(int) * k);
	int left[k], right[k], tmp[k];
	for (int i = 0; i <= k && i <= nums1Size; i++)
	{
		if (k - i > nums2Size)
			continue;
		maxKNumber(nums1, nums1Size, i, left);
		maxKNumber(nums2, nums2Size, k - i, right);
		merge(left, i, right, k - i, tmp, 0, res, k);
	}
	return res;
}