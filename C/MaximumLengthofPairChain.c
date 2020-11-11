#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int findLongestChain(int **pairs, int pairsSize, int *pairsColSize)
{
	if (pairsSize == 0)
		return 0;
	qsort(pairs, pairsSize, sizeof(int *), cmp);
	int res = 1;
	for (int i = 1, j = 0; i < pairsSize; ++i)
	{
		if (pairs[i][0] > pairs[j][1])
		{
			++res;
			j = i;
		}
	}
	return res;
}