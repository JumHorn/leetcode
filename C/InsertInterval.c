#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int *createInterval(int *interval)
{
	int *res = (int *)malloc(sizeof(int) * 2);
	res[0] = interval[0];
	res[1] = interval[1];
	return res;
}

int *createReturnColumn(int size)
{
	int *res = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
		res[i] = 2;
	return res;
}

int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes)
{
	int size = 0, i;
	int **res = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
	for (i = 0; i < intervalsSize; ++i)
	{
		if (newInterval[1] < intervals[i][0])
		{
			res[size++] = createInterval(newInterval);
			res[size++] = createInterval(intervals[i]);
			break;
		}
		if (newInterval[0] > intervals[i][1])
			res[size++] = createInterval(intervals[i]);
		else
		{
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
		}
	}
	if (i == intervalsSize)
		res[size++] = createInterval(newInterval);
	else
	{
		while (++i < intervalsSize)
			res[size++] = createInterval(intervals[i]);
	}
	*returnSize = size;
	*returnColumnSizes = createReturnColumn(size);
	return res;
}
