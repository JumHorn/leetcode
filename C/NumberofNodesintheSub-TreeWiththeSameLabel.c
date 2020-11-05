#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector
{
	int data[26];
} vector;

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
vector postorder(GraphNode **graph, int at, char *labels, int *seen, int *nodeCount)
{
	vector res;
	memset(res.data, 0, sizeof(res.data));
	seen[at] = 1;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (seen[to->node] == 1)
			continue;
		vector count = postorder(graph, to->node, labels, seen, nodeCount);
		for (int i = 0; i < 26; ++i)
			res.data[i] += count.data[i];
	}
	nodeCount[at] = ++res.data[labels[at] - 'a'];
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countSubTrees(int n, int **edges, int edgesSize, int *edgesColSize, char *labels, int *returnSize)
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
	*returnSize = n;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	postorder(graph, 0, labels, seen, res);
	return res;
}