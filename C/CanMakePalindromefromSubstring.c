#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *canMakePaliQueries(char *s, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
	*returnSize = queriesSize;
	bool *res = (bool *)malloc(sizeof(bool) * (*returnSize));
	int N = strlen(s), prefixsum[N + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < N; ++i)
		prefixsum[i + 1] = (prefixsum[i] ^ (1 << (s[i] - 'a')));

	for (int i = 0; i < queriesSize; ++i)
	{
		int r = bitCount(prefixsum[queries[i][1] + 1] ^ prefixsum[queries[i][0]]);
		res[i] = (queries[i][2] >= (r >> 1));
	}
	return res;
}