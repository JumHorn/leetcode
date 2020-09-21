#include <math.h>
#include <stdlib.h>

typedef struct pair
{
	int index;
	int value;
} pair;

int cmp(const void *lhs, const void *rhs)
{
	int l = ((pair *)lhs)->value, r = ((pair *)rhs)->value;
	if (l == r)
		return 0;
	return l < r ? -1 : 1;
}

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
	if (numsSize < 2)
		return false;
	pair arr[numsSize];
	for (int i = 0; i < numsSize; ++i)
	{
		arr[i].index = i;
		arr[i].value = nums[i];
	}
	qsort(arr, numsSize, sizeof(pair), cmp);
	for (int i = 1, j = 0; i < numsSize; ++i)
	{
		long diff = (long)arr[i].value - arr[j].value;
		while (diff > t)
			diff = (long)arr[i].value - arr[++j].value;
		for (int l = j; l < i; ++l)
		{
			if (i != l && abs(arr[i].index - arr[l].index) <= k)
				return true;
		}
	}
	return false;
}
