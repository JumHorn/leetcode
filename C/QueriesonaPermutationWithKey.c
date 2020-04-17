#include <stdlib.h>
#include <string.h>

/*
Fenwick tree based solution
*/

int sum(int *tree, int size, int index)
{
	int res = 0;
	while (index > 0)
	{
		res += tree[index];
		index -= index & -index;
	}
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	while (index < size)
	{
		tree[index] += delta;
		index += index & -index;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *processQueries(int *queries, int queriesSize, int m, int *returnSize)
{
	int map[m + 1];
	for (int i = 1; i <= m; i++)
		map[i] = i + queriesSize;
	int treesize = queriesSize + m + 1, tree[treesize];
	memset(tree, 0, sizeof(tree));
	for (int i = m; i > 0; --i)
		update(tree, treesize, i + queriesSize, 1);

	*returnSize = queriesSize;
	int *res = (int *)malloc(sizeof(int) * queriesSize);
	for (int i = 0; i < queriesSize; i++)
	{
		res[i] = sum(tree, treesize, map[queries[i]]) - 1;
		update(tree, treesize, map[queries[i]], -1);
		map[queries[i]] = queriesSize - i;
		update(tree, treesize, map[queries[i]], 1);
	}
	return res;
}