#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int maxCoins(int *piles, int pilesSize)
{
	qsort(piles, pilesSize, sizeof(int), cmp);
	int res = 0;
	for (int i = pilesSize - 1; i > pilesSize / 3; i -= 2)
		res += piles[i - 1];
	return res;
}
