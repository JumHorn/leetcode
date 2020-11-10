#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//decreasing stack
void maxKNumber(int *nums, int size, int k, int *res)
{
	if (k == 0)
		return;
	int top = -1;
	for (int i = 0; i < size; ++i)
	{
		while (top != -1 && top + 1 + size - i > k && res[top] < nums[i])
			--top;
		if (top + 1 < k)
			res[++top] = nums[i];
	}
}

bool less(int *nums1, int size1, int *nums2, int size2)
{
	for (int i = 0, j = 0; i < size1 && j < size2; ++i, ++j)
	{
		if (nums1[i] != nums2[j])
			return nums1[i] < nums2[j];
	}
	return size1 < size2;
}

void merge(int *num1, int num1Size, int *num2, int num2Size, int *dup)
{
	for (int i = 0, j = 0, d = 0; i < num1Size || j < num2Size;)
	{
		if (i == num1Size)
			dup[d++] = num2[j++];
		else if (j == num2Size)
			dup[d++] = num1[i++];
		else
		{
			if (less(num1 + i, num1Size - i, num2 + j, num2Size - j))
				dup[d++] = num2[j++];
			else
				dup[d++] = num1[i++];
		}
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
	int num1[k], num2[k], num[k];
	for (int i = 0; i <= k && i <= nums1Size; ++i)
	{
		if (k - i > nums2Size)
			continue;
		maxKNumber(nums1, nums1Size, i, num1);
		maxKNumber(nums2, nums2Size, k - i, num2);
		merge(num1, i, num2, k - i, num);
		if (less(res, k, num, k))
			memcpy(res, num, sizeof(int) * k);
	}
	return res;
}