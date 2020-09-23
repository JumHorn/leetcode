#include <stdlib.h>
#include <string.h>

typedef struct GraphNode
{
	int node;
	struct GraphNode *next;
} GraphNode;

struct GraphNode *createNode(int val)
{
	struct GraphNode *node = (struct GraphNode *)malloc(sizeof(struct GraphNode));
	node->node = val;
	node->next = 0;
	return node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findMinHeightTrees(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	if (n == 1)
	{
		*returnSize = 1;
		int *res = (int *)malloc(sizeof(int) * (*returnSize));
		res[0] = 0;
		return res;
	}

	struct GraphNode *graph[n];
	int indgree[n];
	memset(graph, 0, sizeof(graph));
	memset(indgree, 0, sizeof(indgree));
	for (int i = 0; i < edgesSize; ++i)
	{
		struct GraphNode *node = createNode(edges[i][1]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		node = createNode(edges[i][0]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
		++indgree[edges[i][0]];
		++indgree[edges[i][1]];
	}
	int leavenode[n], leavenodesize = 0;
	for (int i = 0; i < n; ++i)
	{
		if (indgree[i] == 1)
			leavenode[leavenodesize++] = i;
	}

	for (int m = n; m > 2;)
	{
		int next[n], nextsize = 0;
		m -= leavenodesize;
		for (int i = 0; i < leavenodesize; ++i)
		{
			int node = leavenode[i];
			for (struct GraphNode *p = graph[node]; p; p = p->next)
			{
				if (--indgree[p->node] == 1)
					next[nextsize++] = p->node;
			}
		}
		leavenodesize = nextsize;
		memcpy(leavenode, next, sizeof(int) * nextsize);
	}
	*returnSize = leavenodesize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, leavenode, sizeof(int) * (*returnSize));
	return res;
}