#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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
	int size = deckSize, queue[size], front = 0, rear = 0;
	for (int i = 0; i < deckSize; ++i)
	{
		queue[rear] = i;
		rear = (rear - 1 + size) % size; //push back
	}
	for (int i = 0; i < deckSize; ++i)
	{
		res[queue[front]] = deck[i];
		front = (front - 1 + size) % size; //pop front
		queue[rear] = queue[front];
		rear = (rear - 1 + size) % size;   //push back
		front = (front - 1 + size) % size; //pop front
	}
	return res;
}