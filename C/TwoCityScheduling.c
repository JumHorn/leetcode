#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int twoCitySchedCost(int **costs, int costsSize, int *costsColSize)
{
	int arr[costsSize][2]; //{diff,index}
	for (int i = 0; i < costsSize; ++i)
	{
		arr[i][0] = costs[i][1] - costs[i][0];
		arr[i][1] = i;
	}
	qsort(arr, costsSize, sizeof(arr[0]), cmp);
	int res = 0;
	for (int i = 0; i < costsSize / 2; ++i)
		res += costs[arr[i][1]][1];
	for (int i = costsSize / 2; i < costsSize; ++i)
		res += costs[arr[i][1]][0];
	return res;
}