#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cmp(const void* lhs, const void* rhs)
{
	return *(int*)rhs - *(int*)lhs;
}

int hIndex(int* citations, int citationsSize)
{
	qsort(citations, citationsSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0; i < citationsSize; i++)
		res = max(res, min(citations[i], i + 1));
	return res;
}

