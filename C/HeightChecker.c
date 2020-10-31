#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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