#include <stdlib.h>
#include <string.h>

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

void preorder(GraphNode **graph, int N, int *nodecount, int from, int at, int *dis)
{
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (from != to->node) //don't go back to parent
		{
			dis[to->node] = dis[at] + N - 2 * nodecount[to->node];
			preorder(graph, N, nodecount, at, to->node, dis);
		}
	}
}

int postorder(GraphNode **graph, int from, int at, int *nodecount)
{
	int res = 0;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (from != to->node) //don't go back to parent
		{
			res += postorder(graph, at, to->node, nodecount);
			nodecount[at] += nodecount[to->node];
			res += nodecount[to->node];
		}
	}
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumOfDistancesInTree(int N, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	GraphNode *graph[N];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < edgesSize; ++i)
	{
		GraphNode *node = createNode(edges[i][1]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		node = createNode(edges[i][0]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
	}

	int nodecount[N];
	for (int i = 0; i < N; ++i)
		nodecount[i] = 1;
	*returnSize = N;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	res[0] = postorder(graph, -1, 0, nodecount);
	preorder(graph, N, nodecount, -1, 0, res);
	return res;
}