#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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