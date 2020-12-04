#include <stdlib.h>

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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes)
{
	int size = 0;
	int **res = (int **)malloc(sizeof(int *) * (intervalsSize + 1));
	for (int i = 0; i <= intervalsSize; ++i)
	{
		if (i == intervalsSize || newInterval[1] < intervals[i][0])
		{
			res[size++] = createInterval(newInterval);
			for (; i < intervalsSize; ++i)
				res[size++] = createInterval(intervals[i]);
		}
		else
		{
			if (newInterval[0] > intervals[i][1])
				res[size++] = createInterval(intervals[i]);
			else
			{
				newInterval[0] = min(newInterval[0], intervals[i][0]);
				newInterval[1] = max(newInterval[1], intervals[i][1]);
			}
		}
	}

	*returnSize = size;
	*returnColumnSizes = createReturnColumn(size);
	return res;
}