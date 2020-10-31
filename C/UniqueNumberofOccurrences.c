#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

bool uniqueOccurrences(int *arr, int arrSize)
{
	int map[2001] = {0};
	for (int i = 0; i < arrSize; ++i)
		++map[arr[i] + 1000];
	qsort(map, 2001, sizeof(int), cmp);
	for (int i = 1999; i >= 0 && map[i] != 0; --i)
	{
		if (map[i] == map[i + 1])
			return false;
	}
	return true;
}