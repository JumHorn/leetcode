#include <stdlib.h>

// Index-rewiring.  "virtual indexing"
// #define A(i) nums[(1 + 2 * (i)) % (N | 1)]
/*
Accessing A(0) actually accesses nums[1].
Accessing A(1) actually accesses nums[3].
Accessing A(2) actually accesses nums[5].
Accessing A(3) actually accesses nums[7].
Accessing A(4) actually accesses nums[9].
Accessing A(5) actually accesses nums[0].
Accessing A(6) actually accesses nums[2].
Accessing A(7) actually accesses nums[4].
Accessing A(8) actually accesses nums[6].
Accessing A(9) actually accesses nums[8].
*/

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

void wiggleSort(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int mid = nums[numsSize / 2];
#define map(i) nums[(1 + 2 * (i)) % (numsSize | 1)]

	int i = 0, j = 0, k = numsSize - 1;
	//three-way partitioning
	while (j <= k)
	{
		if (map(j) > mid)
			swap(&map(i++), &map(j++));
		else if (map(j) < mid)
			swap(&map(j), &map(k--));
		else
			++j;
	}
}