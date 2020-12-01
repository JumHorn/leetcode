#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int lower_bound(int *arr, int size, int val)
{
	int lo = 0, hi = size;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	if (lo >= size || arr[lo] != val)
		return -1;
	return lo;
}

int upper_bound(int *arr, int size, int val)
{
	int lo = 0, hi = size;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] <= val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}

int fourSumCount(int *A, int ASize, int *B, int BSize, int *C, int CSize, int *D, int DSize)
{
	if (ASize == 0 || BSize == 0 || CSize == 0 || DSize == 0)
		return 0;
	int size1 = ASize * BSize, size2 = CSize * DSize;
	int hash1[size1], hash2[size2];
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < BSize; ++j)
			hash1[i * ASize + j] = A[i] + B[j];
	}
	qsort(hash1, size1, sizeof(int), cmp);
	for (int i = 0; i < CSize; ++i)
	{
		for (int j = 0; j < DSize; ++j)
			hash2[i * CSize + j] = C[i] + D[j];
	}
	qsort(hash2, size2, sizeof(int), cmp);
	int res = 0, pre = hash1[0];
	for (int i = 1, j = 0; i <= size1; ++i)
	{
		if (i == size1 || hash1[i] != pre)
		{
			int upper = upper_bound(hash2, size2, -pre);
			int lower = lower_bound(hash2, size2, -pre);
			if (lower != -1)
				res += (i - j) * (upper - lower);
			if (i < size1)
			{
				pre = hash1[i];
				j = i;
			}
		}
	}
	return res;
}