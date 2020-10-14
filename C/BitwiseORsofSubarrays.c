#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int unique(int *arr, int arrSize)
{
	if (arrSize == 0)
		return 0;
	int res = 1, pre = arr[0];
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i] != pre)
		{
			++res;
			pre = arr[i];
		}
	}
	return res;
}

int subarrayBitwiseORs(int *A, int ASize)
{
	int res[ASize * 20], resSize = 0, left = 0, right;
	for (int i = 0; i < ASize; ++i)
	{
		right = resSize;
		res[resSize++] = A[i];
		for (int j = left; j < right; ++j)
		{
			if (res[resSize - 1] != (res[j] | A[i]))
				res[resSize++] = (res[j] | A[i]);
		}
		left = right;
	}
	qsort(res, resSize, sizeof(int), cmp);
	return unique(res, resSize);
}