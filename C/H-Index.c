#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int hIndex(int *citations, int citationsSize)
{
	qsort(citations, citationsSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0; i < citationsSize; ++i)
		res = max(res, min(citations[i], i + 1));
	return res;
}