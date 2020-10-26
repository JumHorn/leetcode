#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	*returnSize = queriesSize;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int prefix[arrSize + 1];
	prefix[0] = 0;
	for (int i = 0; i < arrSize; ++i)
		prefix[i + 1] = (prefix[i] ^ arr[i]);
	for (int i = 0; i < queriesSize; ++i)
		res[i] = (prefix[queries[i][0]] ^ prefix[queries[i][1] + 1]);
	return res;
}
