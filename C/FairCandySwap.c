#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int accumulate(int* arr, int arrSize)
{
	int res = 0;
	for (int i = 0; i < arrSize; ++i)
		res += arr[i];
	return res;
}

bool binarySeach(int* arr, int arrSize, int val)
{
	if (arrSize == 0)
		return false;
	int lo = 0, hi = arrSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return arr[lo] == val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize)
{
	qsort(B, BSize, sizeof(int), cmp);
	int sumA = accumulate(A, ASize);
	int sumB = accumulate(B, BSize);
	int avg = (sumA + sumB) / 2;
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < ASize; ++i)
	{
		if (binarySeach(B, BSize, avg + A[i] - sumA))
		{
			res[0] = A[i];
			res[1] = avg + A[i] - sumA;
			break;
		}
	}
	return res;
}
