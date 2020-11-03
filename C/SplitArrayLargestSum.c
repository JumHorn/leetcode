#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

/*
可变长数组的size，不可以在递归中随着参数变化一直变化
*/
int minmax(long *arr, int size, int index, int m, int (*dp)[size])
{
	if (dp[m][index] != -1)
		return dp[m][index];
	if (m == 1)
		return arr[size - 1] - arr[index - 1];
	int res = INT_MAX;
	for (int i = index; i <= size - m; ++i)
	{
		int tmp = minmax(arr, size, i + 1, m - 1, dp);
		res = min(res, max(tmp, arr[i] - arr[index - 1]));
	}
	return dp[m][index] = res;
}

int splitArray(int *nums, int numsSize, int m)
{
	long arr[numsSize + 1];
	arr[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		arr[i + 1] = arr[i] + nums[i];
	int dp[m + 1][numsSize + 1];
	memset(dp, -1, sizeof(dp));
	return minmax(arr, numsSize + 1, 1, m, dp);
}