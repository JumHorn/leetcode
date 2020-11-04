#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

int binarySearch(char **arr, int arrSize, char *val)
{
	if (arrSize == 0)
		return -1;
	int lo = 0, hi = arrSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (strcmp(arr[mi], val) < 0)
			lo = mi + 1;
		else
			hi = mi;
	}
	return strcmp(arr[lo], val);
}

bool contains(char **lhs, int lhsSize, char **rhs, int rhsSize) //rhs contains lhs
{
	if (lhsSize > rhsSize)
		return false;
	for (int i = 0; i < lhsSize; ++i)
	{
		if (binarySearch(rhs, rhsSize, lhs[i]) != 0)
			return false;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *peopleIndexes(char ***favoriteCompanies, int favoriteCompaniesSize, int *favoriteCompaniesColSize, int *returnSize)
{
	int N = favoriteCompaniesSize;
	for (int i = 0; i < N; ++i)
		qsort(favoriteCompanies[i], favoriteCompaniesColSize[i], sizeof(char *), cmp);
	int *res = (int *)malloc(sizeof(int) * N);
	*returnSize = 0;
	for (int i = 0; i < N; ++i)
	{
		bool flag = true;
		for (int j = 0; j < N && flag; ++j)
		{
			if (i == j)
				continue;
			if (contains(favoriteCompanies[i], favoriteCompaniesColSize[i], favoriteCompanies[j], favoriteCompaniesColSize[j]))
				flag = false;
		}
		if (flag)
			res[(*returnSize)++] = i;
	}
	return res;
}