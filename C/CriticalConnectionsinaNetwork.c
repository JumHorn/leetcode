#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

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

void addOneConnection(int a, int b, int **res, int *resSize)
{
	res[*resSize] = (int *)malloc(sizeof(int) * 2);
	res[*resSize][0] = a;
	res[*resSize][1] = b;
	++*resSize;
}

void dfs(GraphNode **graph, int *dsc, int *low, int from, int at, int *time, int **res, int *resSize)
{
	if (dsc[at] != 0)
		return;
	dsc[at] = low[at] = ++*time;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (dsc[to->node] == 0)
		{
			dfs(graph, dsc, low, at, to->node, time, res, resSize);
			low[at] = min(low[at], low[to->node]);
			if (low[to->node] > dsc[at])
				addOneConnection(at, to->node, res, resSize);
		}
		else if (from != to->node)
			low[at] = min(low[at], dsc[to->node]);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **criticalConnections(int n, int **connections, int connectionsSize, int *connectionsColSize, int *returnSize, int **returnColumnSizes)
{
	GraphNode *graph[n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < connectionsSize; ++i)
	{
		GraphNode *node = createNode(connections[i][1]);
		node->next = graph[connections[i][0]];
		graph[connections[i][0]] = node;
		node = createNode(connections[i][0]);
		node->next = graph[connections[i][1]];
		graph[connections[i][1]] = node;
	}

	int **res = (int **)malloc(sizeof(int *) * 100000);
	int time = 0;
	int dsc[n], low[n];
	memset(dsc, 0, sizeof(dsc));
	memset(low, 0, sizeof(low));
	*returnSize = 0;
	dfs(graph, dsc, low, -1, 0, &time, res, returnSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}