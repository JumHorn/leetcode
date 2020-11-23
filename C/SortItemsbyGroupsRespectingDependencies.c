#include <stdlib.h>
#include <string.h>

//DynamicArray
typedef struct DynamicArray
{
	int *data;
	int size;
	int capacity;
} DynamicArray;

DynamicArray *arr_init()
{
	DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
	arr->size = 0;
	arr->capacity = 10;
	arr->data = (int *)malloc(sizeof(int) * arr->capacity);
	return arr;
}

void arr_append(DynamicArray *arr, int val)
{
	if (arr->size >= arr->capacity)
	{
		arr->capacity += 1000;
		arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
	}
	arr->data[arr->size++] = val;
}
/********end of DynamicArray********/

// create graph
typedef struct GraphNode
{
	int node;
	struct GraphNode *next;
} GraphNode;

GraphNode *createNode(int val)
{
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->node = val;
	node->next = NULL;
	return node;
}

void dfs(GraphNode **graph, int at, int *seen, int *res, int *resSize)
{
	if (seen[at] == 1)
		return;
	seen[at] = 1;
	for (GraphNode *to = graph[at]; to; to = to->next)
		dfs(graph, to->node, seen, res, resSize);
	res[(*resSize)++] = at;
}

//if items is empty, search all graph
int *topologicalSort(GraphNode **graph, int graphSize, int *indgree, int *items, int itemSize)
{
	int N = itemSize == 0 ? graphSize : itemSize;
	int seen[graphSize];
	memset(seen, 0, sizeof(seen));
	int *res = (int *)malloc(sizeof(int) * N);
	memset(res, -1, sizeof(int) * N);
	int resSize = 0;
	if (itemSize == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			if (indgree[i] == 0)
				dfs(graph, i, seen, res, &resSize);
		}
		return resSize == N ? res : NULL;
	}

	for (int i = 0; i < itemSize; ++i)
	{
		if (indgree[items[i]] == 0)
			dfs(graph, items[i], seen, res, &resSize);
	}
	return resSize == N ? res : NULL;
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

	GraphNode *groupgraph[m];
	memset(groupgraph, 0, sizeof(groupgraph));
	int groupindgree[m];
	memset(groupindgree, 0, sizeof(groupindgree));

	GraphNode *itemgraph[n];
	memset(itemgraph, 0, sizeof(itemgraph));
	int itemindgree[n];
	memset(itemindgree, 0, sizeof(itemindgree));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < beforeItemsColSize[i]; ++j)
		{
			if (group[i] != group[beforeItems[i][j]]) //not in the same group
			{
				GraphNode *node = createNode(group[beforeItems[i][j]]);
				node->next = groupgraph[group[i]];
				groupgraph[group[i]] = node;

				++groupindgree[group[beforeItems[i][j]]];
			}
			else
			{
				GraphNode *node = createNode(beforeItems[i][j]);
				node->next = itemgraph[i];
				itemgraph[i] = node;

				++itemindgree[beforeItems[i][j]];
			}
		}
	}
	int *grouporder = topologicalSort(groupgraph, m, groupindgree, NULL, 0);
	if (!grouporder)
	{
		*returnSize = 0;
		return NULL;
	}

	*returnSize = n;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	DynamicArray *groupitem[m];
	for (int i = 0; i < m; ++i)
		groupitem[i] = arr_init();
	for (int i = 0; i < n; ++i)
		arr_append(groupitem[group[i]], i);

	for (int i = 0, index = 0; i < m; ++i)
	{
		if (groupitem[grouporder[i]]->size == 0)
			continue;
		int *itemorder = topologicalSort(itemgraph, n, itemindgree, groupitem[grouporder[i]]->data, groupitem[grouporder[i]]->size);
		if (!itemorder)
		{
			*returnSize = 0;
			return NULL;
		}
		memcpy(res + index, itemorder, sizeof(int) * groupitem[grouporder[i]]->size);
		index += groupitem[grouporder[i]]->size;
	}
	return res;
}