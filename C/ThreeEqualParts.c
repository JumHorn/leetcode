#include <stdlib.h>

int* makeResult(int pos1, int pos2)
{
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = pos1;
	res[1] = pos2;
	return res;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* threeEqualParts(int* A, int ASize, int* returnSize)
{
	*returnSize = 2;
	int count = 0;
	for (int i = 0; i < ASize; ++i)
		count += A[i];
	if (count == 0)
		return makeResult(0, 2);
	if (count % 3 != 0)
		return makeResult(-1, -1);
	int i = -1, j = 0, k=0, n = count / 3;
	for (k = 0; k < n;)
	{
		if (A[++i] == 1)
			++k;
	}
	j = i + 1;
	for (k = 0; k < n; ++j)
	{
		if (A[j] == 1)
			++k;
	}
	k = ASize - 1;
	while (A[k] == 0)
		--k;
	int zero = ASize - 1 - k;
	for (k = 0; k < zero; ++k)
	{
		if (A[++i] != 0)
			return makeResult(-1, -1);
	}
	for (k = 0; k < zero; ++k)
	{
		if (A[j++] != 0)
			return makeResult(-1, -1);
	}
	int i1 = 0, j1 = i + 1, k1 = j;
	while (A[i1] == 0)
		++i1;
	while (A[j1] == 0)
		++j1;
	while (A[k1] == 0)
		++k1;
	while (i1 <= i)
	{
		if (A[i1] != A[j1] || A[j1] != A[k1])
			return makeResult(-1, -1);
		++i1;
		++j1;
		++k1;
	}
	return makeResult(i, j);
}