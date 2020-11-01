#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *arrayRankTransform(int *arr, int arrSize, int *returnSize)
{
	*returnSize = arrSize;
	if (arrSize == 0)
		return arr;
	int index[arrSize][2];  //{value,index}
	for (int i = 0; i < arrSize; ++i)
	{
		index[i][0] = arr[i];
		index[i][1] = i;
	}
	qsort(index, arrSize, sizeof(index[0]), cmp);
	arr[index[0][1]] = 1;
	for (int i = 1, rank = 1; i < arrSize; ++i)
	{
		if (index[i - 1][0] < index[i][0])
			++rank;
		arr[index[i][1]] = rank;
	}
	return arr;
}
