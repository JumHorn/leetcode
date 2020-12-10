#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int heightChecker(int *heights, int heightsSize)
{
	int people[heightsSize];
	memcpy(people, heights, sizeof(people));
	qsort(people, heightsSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0; i < heightsSize; ++i)
	{
		if (people[i] != heights[i])
			++res;
	}
	return res;
}