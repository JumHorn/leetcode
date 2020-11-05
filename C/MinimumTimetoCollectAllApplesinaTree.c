#include <stdbool.h>
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
/********end of create graph********/

// no apple return -1,hash apple return time needed
int postorder(GraphNode **graph, int at, int *seen, bool *hasApple)
{
	int res = 0;
	seen[at] = 1;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (seen[to->node] == 1)
			continue;
		int time = postorder(graph, to->node, seen, hasApple);
		if (time >= 0)
			res += time + 2;
	}
	return (!hasApple[at] && res == 0) ? -1 : res;
}

int minTime(int n, int **edges, int edgesSize, int *edgesColSize, bool *hasApple, int hasAppleSize)
{
	GraphNode *graph[n];
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
	int seen[n];
	memset(seen, 0, sizeof(seen));
	int res = postorder(graph, 0, seen, hasApple);
	return res >= 0 ? res : 0;
}