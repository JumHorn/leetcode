#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	int path;
	int depth;
} pair;

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

int getNode(int mask)
{
	int res = 0;
	while ((mask & (1 << res)) == 0)
		++res;
	return res;
}

//return {longest path,depth}
pair getHeight(GraphNode **graph, int at, int *seen)
{
	*seen |= (1 << at);
	int longestpath = 0, depth1 = 0, depth2 = 0;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if ((*seen & (1 << to->node)) == 0)
		{
			pair node = getHeight(graph, to->node, seen);
			longestpath = max(longestpath, node.path);
			if (depth1 < node.depth)
			{
				depth2 = depth1;
				depth1 = node.depth;
			}
			else if (depth2 < node.depth)
				depth2 = node.depth;
		}
	}
	pair res = {max(depth1 + depth2, longestpath), depth1 + 1};
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countSubgraphsForEachDiameter(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	GraphNode *graph[n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < edgesSize; ++i)
	{
		GraphNode *node = createNode(edges[i][1] - 1);
		node->next = graph[edges[i][0] - 1];
		graph[edges[i][0] - 1] = node;
		node = createNode(edges[i][0] - 1);
		node->next = graph[edges[i][1] - 1];
		graph[edges[i][1] - 1] = node;
	}

	*returnSize = n - 1;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		int seen = ~mask;
		pair node = getHeight(graph, getNode(mask), &seen);
		if (node.path > 0 && seen == -1) //ensure all nodes traversed
			++res[node.path - 1];
	}
	return res;
}