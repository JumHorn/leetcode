#include <limits.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int binarySearch(int *arr, int lo, int hi, int val)
{
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] <= val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}

int memdp(int *arr1, int arr1Size, int *arr2, int arr2Size, int index1, int index2, int lastval, int (*dp)[arr2Size + 1])
{
	if (index1 >= arr1Size)
		return 0;
	index2 = binarySearch(arr2, index2, arr2Size, lastval);
	if (dp[index1][index2] != 0)
		return dp[index1][index2];
	dp[index1][index2] = arr2Size + 1; //INT_MAX
	if (index2 < arr2Size)
		dp[index1][index2] = 1 + memdp(arr1, arr1Size, arr2, arr2Size, index1 + 1, index2, arr2[index2], dp);
	if (lastval < arr1[index1])
	{
		int res = memdp(arr1, arr1Size, arr2, arr2Size, index1 + 1, index2, arr1[index1], dp);
		if (dp[index1][index2] > res)
			dp[index1][index2] = res;
	}
	return dp[index1][index2];
}

int makeArrayIncreasing(int *arr1, int arr1Size, int *arr2, int arr2Size)
{
	qsort(arr2, arr2Size, sizeof(int), cmp);
	int dp[arr1Size][arr2Size + 1];
	memset(dp, 0, sizeof(dp));
	int res = memdp(arr1, arr1Size, arr2, arr2Size, 0, 0, INT_MIN, dp);
	return res > arr2Size ? -1 : res;
}