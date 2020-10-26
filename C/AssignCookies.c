#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
	qsort(g, gSize, sizeof(int), cmp);
	qsort(s, sSize, sizeof(int), cmp);
	int res = 0;
	for (int i = gSize - 1, j = sSize - 1; i >= 0 && j >= 0; --i)
	{
		if (s[j] >= g[i])
		{
			++res;
			--j;
		}
	}
	return res;
}
