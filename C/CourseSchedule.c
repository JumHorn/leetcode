#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct CourseNode
{
	int course;
	struct CourseNode *next;
} CourseNode;

CourseNode *createNode(int c)
{
	CourseNode *node = (CourseNode *)malloc(sizeof(CourseNode));
	node->next = NULL;
	node->course = c;
	return node;
}

bool backTracking(CourseNode **graph, int at, int *seen, int *done)
{
	if (seen[at] == 1)
		return false;
	if (done[at] == 1)
		return true;
	done[at] = seen[at] = 1;
	for (CourseNode *p = graph[at]; p; p = p->next)
	{
		if (!backTracking(graph, p->course, seen, done))
			return false;
	}
	seen[at] = 0;
	return true;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
	CourseNode *graph[numCourses];
	memset(graph, 0, sizeof(graph));
	int done[numCourses], seen[numCourses]; //the node which finish search
	memset(done, 0, sizeof(done));
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < prerequisitesSize; ++i)
	{
		CourseNode *node = createNode(prerequisites[i][1]);
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