#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
topological sort DFS implement
*/

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

bool backTracking(GraphNode **graph, int at, int *seen, int *done)
{
	if (seen[at] == 1)
		return false;
	if (done[at] == 1)
		return true;
	done[at] = seen[at] = 1;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (!backTracking(graph, to->node, seen, done))
			return false;
	}
	seen[at] = 0;
	return true;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
	GraphNode *graph[numCourses];
	memset(graph, 0, sizeof(graph));
	int done[numCourses], seen[numCourses]; //the node which finish search
	memset(done, 0, sizeof(done));
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < prerequisitesSize; ++i)
	{
		GraphNode *node = createNode(prerequisites[i][1]);
		node->next = graph[prerequisites[i][0]];
		graph[prerequisites[i][0]] = node;
	}
	for (int i = 0; i < numCourses; ++i)
	{
		if (done[i] == 0 && !backTracking(graph, i, seen, done))
			return false;
	}
	return true;
}