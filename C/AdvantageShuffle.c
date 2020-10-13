#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
	int arr[BSize][2];  //{B val,B index}
	for (int i = 0; i < BSize; ++i)
	{
		arr[i][0] = B[i];
		arr[i][1] = i;
	}
	qsort(A, ASize, sizeof(int), cmp);
	qsort(arr, BSize, sizeof(arr[0]), cmp);
	*returnSize = ASize;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = BSize - 1, j = ASize - 1, k = 0; i >= 0; --i)
	{
		if (A[j] > arr[i][0])
			res[arr[i][1]] = A[j--];
		else
			res[arr[i][1]] = A[k++];
	}
	return res;
}
