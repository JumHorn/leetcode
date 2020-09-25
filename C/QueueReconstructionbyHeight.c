#include <stdlib.h>
#include <string.h>

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********malloc result********/

int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return r[0] - l[0];
	return l[1] - r[1];
}

void swap(int **lhs, int **rhs)
{
	int *tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **reconstructQueue(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes)
{
	qsort(people, peopleSize, sizeof(int *), cmp);
	for (int i = 1; i < peopleSize; ++i)
	{
		if (people[i][1] < i)
		{
			int j = i;
			while (people[j][1] < j)
			{
				swap(&people[j], &people[j - 1]);
				--j;
			}
		}
	}
	return mallocRes(people, peopleSize, peopleColSize, returnSize, returnColumnSizes);
}
