#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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