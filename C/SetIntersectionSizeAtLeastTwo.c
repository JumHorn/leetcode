#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return (*(int**)lhs)[1] - (*(int**)rhs)[1];
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize)
{
	qsort(intervals, intervalsSize, sizeof(int*), cmp);
	int arr[2 * intervalsSize], size = 2;
	arr[0] = intervals[0][1] - 1;
	arr[1] = intervals[0][1];
	for (int i = 1; i < intervalsSize; i++)
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
