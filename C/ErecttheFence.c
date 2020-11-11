#include <limits.h>
#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] < r[0] ? -1 : 1;
	return l[1] - r[1];
}

int crossProduct(int *pointA, int *pointB, int *pointC)
{
	int x1 = pointB[0] - pointA[0];
	int y1 = pointB[1] - pointA[1];
	int x2 = pointC[0] - pointA[0];
	int y2 = pointC[1] - pointA[1];
	return x1 * y2 - x2 * y1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **outerTrees(int **points, int pointsSize, int *pointsColSize, int *returnSize, int **returnColumnSizes)
{
	int stack[pointsSize], top = -1, seen[pointsSize];
	qsort(points, pointsSize, sizeof(int *), cmp);
	*returnSize = 0;
	memset(seen, 0, sizeof(seen));
	// left to right
	for (int i = 0; i < pointsSize; ++i)
	{
		while (top >= 1 && crossProduct(points[stack[top]], points[i], points[stack[top - 1]]) < 0)
			--top;
		stack[++top] = i;
	}
	while (top >= 0)
	{
		if (seen[stack[top]] == 0)
		{
			seen[stack[top]] = 1;
			++*returnSize;
		}
		--top;
	}
	// right to left
	for (int i = pointsSize - 1; i >= 0; --i)
	{
		while (top >= 1 && crossProduct(points[stack[top]], points[i], points[stack[top - 1]]) < 0)
			--top;
		stack[++top] = i;
	}
	while (top >= 0)
	{
		if (seen[stack[top]] == 0)
		{
			seen[stack[top]] = 1;
			++*returnSize;
		}
		--top;
	}
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < pointsSize; ++i)
	{
		if (seen[i] == 1)
		{
			res[++top] = (int *)malloc(sizeof(int) * 2);
			memcpy(res[top], points[i], sizeof(int) * 2);
		}
	}
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}