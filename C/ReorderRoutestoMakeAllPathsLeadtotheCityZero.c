#include <stdlib.h>
#include <string.h>

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

int dfs(GraphNode **graph, int *seen, int at)
{
	int res = 0;
	seen[at] = 1;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (seen[abs(to->node)] == 0)
			res += dfs(graph, seen, abs(to->node)) + (to->node > 0 ? 1 : 0);
	}
	return res;
}

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize)
{
	GraphNode *graph[n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < connectionsSize; ++i)
	{
		GraphNode *node = createNode(connections[i][1]); //real edge
		node->next = graph[connections[i][0]];
		graph[connections[i][0]] = node;
		node = createNode(-connections[i][0]); //virtual edge
		node->next = graph[connections[i][1]];
		graph[connections[i][1]] = node;
	}
	int seen[n];
	memset(seen, 0, sizeof(seen));
	return dfs(graph, seen, 0);
}