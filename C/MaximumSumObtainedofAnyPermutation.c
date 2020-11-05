#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int maxSumRangeQuery(int* nums, int numsSize, int** requests, int requestsSize, int* requestsColSize)
{
	static const int MOD = 1e9 + 7;
	int count[numsSize + 1];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < requestsSize; ++i)
	{
		++count[requests[i][0]];
		--count[requests[i][1] + 1];
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 1; i < numsSize; ++i)
		count[i] += count[i - 1];
	qsort(count, numsSize, sizeof(int), cmp);
	long res = 0;
	for (int i = 0; i < numsSize; ++i)
		res = (res + (long)count[i] * nums[i]) % MOD;
	return res;
}
