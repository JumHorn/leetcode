#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[1] != r[1])
		return l[1] < r[1] ? -1 : 1;
	return r[0] - l[0];
}

int intersectionSizeTwo(int **intervals, int intervalsSize, int *intervalsColSize)
{
	qsort(intervals, intervalsSize, sizeof(int *), cmp);
	int arr[2 * intervalsSize], size = 2;
	arr[0] = intervals[0][1] - 1;
	arr[1] = intervals[0][1];
	for (int i = 1; i < intervalsSize; ++i)
	{
		if (intervals[i][0] > arr[size - 2])
		{
			if (intervals[i][0] > arr[size - 1])
				arr[size++] = intervals[i][1] - 1;
			arr[size++] = intervals[i][1];
		}
	}
	return size;
}