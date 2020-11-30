#include <string.h>

static const int MOD = 1e9 + 7;

int recursive(int *nums, int numsSize, int N, int (*cache)[N + 1])
{
	if (numsSize <= 2)
		return 1;
	int left[N + 1], leftSize = 0, right[N + 1], rightSize = 0;
	for (int i = 1; i < numsSize; ++i)
		nums[i] > nums[0] ? (right[rightSize++] = nums[i]) : (left[leftSize++] = nums[i]);
	int l = recursive(left, leftSize, N, cache), r = recursive(right, rightSize, N, cache);
	long res = cache[numsSize - 1][leftSize];
	return res * l % MOD * r % MOD;
}

int numOfWays(int *nums, int numsSize)
{
	int N = numsSize;
	//combination table
	int combination[N + 1][N + 1];
	memset(combination, 0, sizeof(combination));
	combination[0][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		combination[i][0] = 1;
		for (int j = 1; j <= N; ++j)
			combination[i][j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % MOD;
	}
	return recursive(nums, numsSize, N, combination) - 1;
}