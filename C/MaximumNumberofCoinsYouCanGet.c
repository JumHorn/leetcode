#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int maxCoins(int *piles, int pilesSize)
{
	qsort(piles, pilesSize, sizeof(int), cmp);
	int res = 0;
	for (int i = pilesSize - 1; i > pilesSize / 3; i -= 2)
		res += piles[i - 1];
	return res;
}