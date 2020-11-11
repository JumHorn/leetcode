#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	int *res = (int *)malloc(sizeof(int) * max(nums1Size, nums2Size));
	*returnSize = 0;
	for (int i = 0, j = 0; i < nums1Size && j < nums2Size;)
	{
		if (nums1[i] == nums2[j])
		{
			if (*returnSize == 0 || res[*returnSize - 1] != nums1[i])
				res[(*returnSize)++] = nums1[i];
			++i;
			++j;
		}
		else if (nums1[i] < nums2[j])
			++i;
		else
			++j;
	}
	return res;
}