#include <stdlib.h>

void arraySquare(int *arr, int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
		arr[i] *= arr[i];
}

int binarySeach(int *arr, int arrSize)
{
	int lo = 0, hi = arrSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] < 0)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize)
{
	*returnSize = ASize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int i = binarySeach(A, ASize), j = i - 1;
	arraySquare(A, ASize);
	//merge
	for (int k = 0; i < ASize || j >= 0; ++k)
	{
		if (i == ASize)
			res[k] = A[j--];
		else if (j == -1)
			res[k] = A[i++];
		else
			res[k] = (A[i] > A[j]) ? A[j--] : A[i++];
	}
	return res;
}