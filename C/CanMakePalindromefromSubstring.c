#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bitReverse(int num, int bit)
{
	return ((~num) & (1u << bit)) | (num & (~(1u << bit)));
}

int bitCount(int x)
{
	x -= ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x += x >> 8;
	x += x >> 16;
	return x & 0x3F;
}

bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	bool* res = (bool*)malloc(queriesSize * sizeof(bool));
	*returnSize = queriesSize;
	int len = strlen(s);
	int* dp = (int*)malloc((len + 1) * sizeof(int));
	dp[0] = 0;
	for (int i = 0; i < len; i++)
		dp[i + 1] = (dp[i] ^ (1 << (s[i] - 'a')));

	for (int i = 0; i < queriesSize; i++)
	{
		int r = bitCount(dp[queries[i][1] + 1] ^ dp[queries[i][0]]);
		res[i] = (queries[i][2] >= (r >> 1));
	}
	return res;
}
