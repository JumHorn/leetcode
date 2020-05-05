#include <stdbool.h>
#include <stdlib.h>
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
		if (top + 1 < k)
			res[++top] = nums[i];
	}
}

bool less(int *nums1, int size1, int *nums2, int size2)
{
	for (int i = 0, j = 0; i < size1 && j < size2; i++, j++)
		if (nums1[i] != nums2[j])
			return nums1[i] < nums2[j];
	return size1 < size2;
}

void merge(int *left, int leftsize, int *right, int rightsize, int *dup)
{
	int i = 0, j = 0, d = 0;
	while (i < leftsize && j < rightsize)
	{
		if (less(left + i, leftsize - i, right + j, rightsize - j))
			dup[d++] = right[j++];
		else
			dup[d++] = left[i++];
	}
	while (i < leftsize)
		dup[d++] = left[i++];
	while (j < rightsize)
		dup[d++] = right[j++];
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
		merge(left, i, right, k - i, tmp);
		if (less(res, k, tmp, k))
			memcpy(res, tmp, sizeof(int) * k);
	}
	return res;
}
