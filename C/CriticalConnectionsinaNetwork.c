#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct LinkedList
{
	int val;
	struct LinkedList *next;
} LinkedList;

LinkedList *createNode(int v)
{
	LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
	node->val = v;
	node->next = NULL;
	return node;
}

int **addOneConnection(int **res, int *size, int a, int b)
{
	++*size;
	res = (int **)realloc(res, *size * sizeof(int *));
	res[*size - 1] = (int *)malloc(sizeof(int) * 2);
	res[*size - 1][0] = a;
	res[*size - 1][1] = b;
	return res;
}

void dfs(LinkedList **graph, int *dsc, int *low, int parent, int at, int *time, int ***res, int *size)
{
	if (dsc[at] != 0)
		return;
	dsc[at] = low[at] = ++*time;
	for (LinkedList *to = graph[at]; to; to = to->next)
	{
		if (dsc[to->val] == 0)
		{
			dfs(graph, dsc, low, at, to->val, time, res, size);
			low[at] = min(low[at], low[to->val]);
			if (low[to->val] > dsc[at])
				*res = addOneConnection(*res, size, at, to->val);
		}
		else if (parent != to->val)
			low[at] = min(low[at], dsc[to->val]);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **criticalConnections(int n, int **connections, int connectionsSize, int *connectionsColSize, int *returnSize, int **returnColumnSizes)
{
	LinkedList *graph[n];
	memset(graph, 0, n * sizeof(LinkedList *));
	for (int i = 0; i < connectionsSize; ++i)
	{
		LinkedList *node = createNode(connections[i][0]);
		node->next = graph[connections[i][1]];
		graph[connections[i][1]] = node;

		node = createNode(connections[i][1]);
		node->next = graph[connections[i][0]];
		graph[connections[i][0]] = node;
	}
	int **res = NULL, size = 0, time = 0;
	int dsc[n], low[n];
	memset(dsc, 0, sizeof(dsc));
	memset(low, 0, sizeof(low));
	dfs(graph, dsc, low, -1, 0, &time, &res, &size);
	*returnSize = size;
	*returnColumnSizes = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}