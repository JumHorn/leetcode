#include <stdbool.h>
#include <stdlib.h>

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 */
// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedIntegerIsInteger(struct NestedInteger *);

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedIntegerGetInteger(struct NestedInteger *);

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);

// Return the nested list's size that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
int NestedIntegerGetListSize(struct NestedInteger *);

struct NestedIterator
{
	int data[20000];
	int size;
	int index;
};

void dfs(struct NestedInteger **nestedList, int nestedListSize, struct NestedIterator *iter)
{
	for (int i = 0; i < nestedListSize; ++i)
	{
		if (NestedIntegerIsInteger(nestedList[i]))
			iter->data[iter->size++] = NestedIntegerGetInteger(nestedList[i]);
		else
			dfs(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), iter);
	}
}

struct NestedIterator *nestedIterCreate(struct NestedInteger **nestedList, int nestedListSize)
{
	struct NestedIterator *iter = (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
	iter->index = iter->size = 0;
	dfs(nestedList, nestedListSize, iter);
	return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter)
{
	return iter->index < iter->size;
}

int nestedIterNext(struct NestedIterator *iter)
{
	return iter->data[iter->index++];
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter)
{
	if (iter)
		free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */