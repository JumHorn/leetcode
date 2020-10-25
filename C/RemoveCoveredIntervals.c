#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return r[1] - l[1];
}

int removeCoveredIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
	int res = 0;
	qsort(intervals, intervalsSize, sizeof(int *), cmp);
	for (int i = 1, j = 0; i < intervalsSize; ++i)
	{
		if (intervals[j][1] >= intervals[i][1])
			++res;
		else
			j = i;
	}
	return intervalsSize - res;
}
