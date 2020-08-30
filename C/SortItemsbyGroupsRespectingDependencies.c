#include <stdlib.h>
#include <string.h>

void dfs(int **graph, int graphSize, int *graphColSize, int at, int *res, int *size, int *seen)
{
	if (seen[at] == 1)
		return;
	seen[at] = 1;
	for (int i = 0; i < graphColSize[at]; ++i)
		dfs(graph, graphSize, graphColSize, graph[at][i], res, size, seen);
	res[*size] = at;
	++(*size);
}

//if items is empty, search all graph
int *topologicalSort(int **graph, int graphSize, int *graphColSize, int *indgree, int *items, int itemSize)
{
	int seen[graphSize];
	memset(seen, 0, sizeof(seen));
	int *res = (int *)malloc(sizeof(int) * graphSize);
	memset(res, -1, sizeof(int) * graphSize);
	int resSize = 0;
	if (itemSize == 0)
	{
		for (int i = 0; i < graphSize; ++i)
		{
			if (indgree[i] == 0)
				dfs(graph, graphSize, graphColSize, i, res, &resSize, seen);
		}
		return resSize == graphSize ? res : NULL;
	}

	for (int i = 0; i < itemSize; ++i)
	{
		if (indgree[items[i]] == 0)
			dfs(graph, graphSize, graphColSize, items[i], res, &resSize, seen);
	}
	return resSize == itemSize ? res : NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortItems(int n, int m, int *group, int groupSize, int **beforeItems, int beforeItemsSize, int *beforeItemsColSize, int *returnSize)
{
	for (int i = 0; i < n; ++i)
	{
		if (group[i] == -1)
			group[i] = m++;
	}

	int **groupgraph = (int **)malloc(sizeof(int *) * m);
	for (int i = 0; i < m; ++i)
		groupgraph[i] = (int *)malloc(sizeof(int) * n);
	int groupgraphcolsize[m];
	memset(groupgraphcolsize, 0, sizeof(groupgraphcolsize));
	int groupindgree[m];
	memset(groupindgree, 0, sizeof(groupindgree));

	int **itemgraph = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; ++i)
		itemgraph[i] = (int *)malloc(sizeof(int) * n);
	int itemgraphcolsize[n];
	memset(itemgraphcolsize, 0, sizeof(itemgraphcolsize));
	int itemindgree[n];
	memset(itemindgree, 0, sizeof(itemindgree));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < beforeItemsColSize[i]; ++j)
		{
			if (group[i] != group[beforeItems[i][j]]) //not in the same group
			{
				groupgraph[group[i]][groupgraphcolsize[group[i]]++] = group[beforeItems[i][j]];
				++groupindgree[group[beforeItems[i][j]]];
			}
			else
			{
				itemgraph[i][itemgraphcolsize[i]++] = beforeItems[i][j];
				++itemindgree[beforeItems[i][j]];
			}
		}
	}
	int *grouporder = topologicalSort(groupgraph, m, groupgraphcolsize, groupindgree, NULL, 0);
	if (!grouporder)
	{
		*returnSize = 0;
		return NULL;
	}
	int *res = (int *)malloc(sizeof(int) * n);
	int **groupitem = (int **)malloc(sizeof(int *) * m);
	for (int i = 0; i < m; ++i)
		groupitem[i] = (int *)malloc(sizeof(int) * n);
	int groupitemcolsize[m];
	memset(groupitemcolsize, 0, sizeof(groupitemcolsize));
	for (int i = 0; i < n; ++i)
		groupitem[group[i]][groupitemcolsize[group[i]]++] = i;
	for (int i = 0, index = 0; i < m; ++i)
	{
		if (groupitemcolsize[grouporder[i]] == 0)
			continue;
		int *itemorder = topologicalSort(itemgraph, n, itemgraphcolsize, itemindgree, groupitem[grouporder[i]], groupitemcolsize[grouporder[i]]);
		if (!itemorder)
		{
			*returnSize = 0;
			return NULL;
		}
		memcpy(res + index, itemorder, sizeof(int) * groupitemcolsize[grouporder[i]]);
		index += groupitemcolsize[grouporder[i]];
	}
	*returnSize = n;
	return res;
}