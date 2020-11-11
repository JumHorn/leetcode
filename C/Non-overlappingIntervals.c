#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
	qsort(intervals, intervalsSize, sizeof(int *), cmp);
	if (intervalsSize == 0)
		return 0;
	int res = 1, maxright = intervals[0][1];
	for (int i = 1; i < intervalsSize; ++i)
	{
		if (intervals[i][0] >= maxright)
		{
			++res;
			maxright = intervals[i][1];
		}
	}
	return intervalsSize - res;
}