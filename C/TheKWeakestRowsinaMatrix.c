#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	int *l = (int*)lhs, *r = (int*)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return l[1] - r[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
	int arr[matSize][2], arrSize = 0;  //{soldiers,index}
	for (int i = 0; i < matSize; ++i)
	{
		int j = 0;
		while (j < *matColSize && mat[i][j] == 1)
			++j;
		arr[arrSize][0] = j;
		arr[arrSize][1] = i;
		++arrSize;
	}
	qsort(arr, arrSize, sizeof(arr[0]), cmp);
	*returnSize = k;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < k; ++i)
		res[i] = arr[i][1];
	return res;
}
