#include <stdbool.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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