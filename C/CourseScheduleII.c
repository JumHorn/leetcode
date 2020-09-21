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

bool backTracking(CourseNode **graph, int at, int *seen, int *done, int *stack, int *top)
{
	if (seen[at] == 1)
		return false;
	if (done[at] == 1)
		return true;
	done[at] = seen[at] = 1;
	for (CourseNode *p = graph[at]; p; p = p->next)
	{
		if (!backTracking(graph, p->course, seen, done, stack, top))
			return false;
	}
	stack[++*top] = at;
	seen[at] = 0;
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
	int stack[numCourses], top = -1;
	CourseNode *graph[numCourses];
	memset(graph, 0, sizeof(graph));
	int done[numCourses], seen[numCourses]; //the node which finish search
	memset(done, 0, sizeof(done));
	memset(seen, 0, sizeof(seen));
	*returnSize = 0;
	for (int i = 0; i < prerequisitesSize; ++i)
	{
		CourseNode *node = createNode(prerequisites[i][1]);
		node->next = graph[prerequisites[i][0]];
		graph[prerequisites[i][0]] = node;
	}
	for (int i = 0; i < numCourses; ++i)
	{
		if (done[i] == 0 && !backTracking(graph, i, seen, done, stack, &top))
			return NULL;
	}
	*returnSize = numCourses;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, stack, sizeof(int) * (*returnSize));
	return res;
}