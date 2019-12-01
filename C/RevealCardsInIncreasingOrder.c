#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
{
	*returnSize = deckSize;
	int* res = (int*)malloc(sizeof(int) * deckSize);
	memset(res, 0, sizeof(int) * deckSize);
	qsort(deck, deckSize, sizeof(int), cmp);
	int count = 0, index = -1;
	while (count < deckSize)
	{
		while (true)
		{
			index = (index + 1) % deckSize;
			if (res[index] == 0)
			{
				res[index] = deck[count++];
				break;
			}
		}
		if (count >= deckSize)
			break;
		while (true)
		{
			index = (index + 1) % deckSize;
			if (res[index] == 0)
				break;
		}
	}
	return res;
}

