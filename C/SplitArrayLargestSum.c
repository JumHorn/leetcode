#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

/*
可变长数组的size，不可以在递归中随着参数变化一直变化
*/
int minmax(long *prefixsum, int prefixsumSize, int index, int m, int (*dp)[prefixsumSize])
{
	if (dp[m][index] != -1)
		return dp[m][index];
	if (m == 1)
		return prefixsum[prefixsumSize - 1] - prefixsum[index - 1];
	int res = INT_MAX;
	for (int i = index; i <= prefixsumSize - m; ++i)
	{
		int tmp = minmax(prefixsum, prefixsumSize, i + 1, m - 1, dp);
		res = min(res, max(tmp, prefixsum[i] - prefixsum[index - 1]));
	}
	return dp[m][index] = res;
}

int splitArray(int *nums, int numsSize, int m)
{
	long prefixsum[numsSize + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		prefixsum[i + 1] = prefixsum[i] + nums[i];
	int dp[m + 1][numsSize + 1];
	memset(dp, -1, sizeof(dp));
	return minmax(prefixsum, numsSize + 1, 1, m, dp);
}