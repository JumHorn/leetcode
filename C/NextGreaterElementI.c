#include <stdlib.h>
#include <string.h>

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
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
	*returnSize = nums1Size;
	if (nums1Size == 0)
		return NULL;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int map[nums2Size][2], mapsize = 0; //{element,next greater}
	int top = -1;
	for (int i = 0; i < nums2Size; ++i)
	{
		while (top != -1 && nums2[i] > nums2[top])
		{
			map[mapsize][0] = nums2[top];
			map[mapsize][1] = nums2[i];
			++mapsize;
			--top;
		}
		nums2[++top] = nums2[i];
	}

	qsort(map, mapsize, sizeof(map[0]), cmp);
	for (int i = 0; i < nums1Size; ++i)
	{
		int lo = 0, hi = mapsize;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (map[mi][0] < nums1[i])
				lo = mi + 1;
			else
				hi = mi;
		}
		if (lo == mapsize || map[lo][0] != nums1[i])
			res[i] = -1;
		else
			res[i] = map[lo][1];
	}
	return res;
}