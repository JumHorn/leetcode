#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * ASize);
	*returnSize = ASize;
	int even = 0;
	for (int i = 0; i < ASize; i++)
	{
		if (A[i] % 2 == 0)
			even += A[i];
	}
	for (int i = 0; i < queriesSize; i++)
	{
		int index = queries[i][1];
		if (A[index] % 2 == 0)
			even -= A[index];
		A[index] += queries[i][0];
		if (A[index] % 2 == 0)
			even += A[index];
		res[i] = even;
	}
	return res;
}

