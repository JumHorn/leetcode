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

double backTracking(GraphNode **graph, int *graphColSize, int from, int at, int t, int target)
{
	int N = graphColSize[at];
	if (from != -1) //can not jump to previouse positon
		--N;
	if (t == 0 || N == 0)
		return at == target ? 1 : 0;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (to->node != from)
		{
			double res = 1.0 / N * backTracking(graph, graphColSize, at, to->node, t - 1, target);
			if (res != 0)
				return res;
		}
	}
	return 0;
}

double frogPosition(int n, int **edges, int edgesSize, int *edgesColSize, int t, int target)
{
	GraphNode *graph[n + 1];
	memset(graph, 0, sizeof(graph));
	int graphColSize[n + 1];
	memset(graphColSize, 0, sizeof(graphColSize));
	for (int i = 0; i < edgesSize; ++i)
	{
		GraphNode *node = createNode(edges[i][1]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		++graphColSize[edges[i][0]];

		node = createNode(edges[i][0]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
		++graphColSize[edges[i][1]];
	}
	return backTracking(graph, graphColSize, -1, 1, t, target);
}