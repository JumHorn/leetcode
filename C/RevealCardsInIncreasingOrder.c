#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize)
{
	*returnSize = deckSize;
	int *res = (int *)malloc(sizeof(int) * deckSize);
	memset(res, 0, sizeof(int) * deckSize);
	qsort(deck, deckSize, sizeof(int), cmp);
	int count = 0, index = 0;
	while (true)
	{
		res[index] = deck[count++];
		if (count >= deckSize)
			break;
		while (res[index] != 0)
			index = (index + 1) % deckSize;
		index = (index + 1) % deckSize;
		while (res[index] != 0)
			index = (index + 1) % deckSize;
	}
	return res;
}