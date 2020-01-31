#include <stdlib.h>

int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

bool uniqueOccurrences(int* arr, int arrSize)
{
	int map[2001] = {0};
	for (int i = 0; i < arrSize; i++)
		++map[arr[i] + 1000];
	qsort(map, 2001, sizeof(int), cmp);
	int i = 1;
	while (map[i] == 0)
		i++;
	for (; i < 2001; i++)
		if (map[i] == map[i - 1])
			return false;
	return true;
}
