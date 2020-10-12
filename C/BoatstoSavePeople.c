#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int numRescueBoats(int *people, int peopleSize, int limit)
{
	qsort(people, peopleSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0, j = peopleSize - 1; i <= j; --j)
	{
		if (people[i] + people[j] <= limit)
			++i;
		++res;
	}
	return res;
}
