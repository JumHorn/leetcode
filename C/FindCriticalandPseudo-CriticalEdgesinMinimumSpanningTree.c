#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// DSU
typedef struct DSU
{
	int *parent;
	int *rank;
} DSU;

DSU *dsu_init(int N)
{
	DSU *dsu = (DSU *)malloc(sizeof(DSU));
	dsu->parent = (int *)malloc(sizeof(int) * N);
	dsu->rank = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		dsu->parent[i] = i;
		dsu->rank[i] = 1;
	}
	return dsu;
}

void dsu_release(DSU *dsu)
{
	if (dsu)
	{
		if (dsu->parent)
			free(dsu->parent);
		if (dsu->rank)
			free(dsu->rank);
		free(dsu);
	}
}

int dsu_find(DSU *dsu, int x)
{
	if (x != dsu->parent[x])
		dsu->parent[x] = dsu_find(dsu, dsu->parent[x]);
	return dsu->parent[x];
}

bool dsu_union(DSU *dsu, int x, int y)
{
	int xr = dsu_find(dsu, x), yr = dsu_find(dsu, y);
	if (xr == yr)
		return false;
	dsu->parent[yr] = xr;
	dsu->rank[xr] += dsu->rank[yr];
	return true;
}

typedef struct EDGES
{
	int from;
	int to;
	int weight;
	int index;
} EDGES;

int cmp(const void *lhs, const void *rhs)
{
	return ((EDGES *)lhs)->weight - ((EDGES *)rhs)->weight;
}

int mimimumSpanningTree(int n, EDGES *edges, int edgesSize, int pre_edge, int block_edge) //kruskal algorithm
{
	DSU *dsu = dsu_init(n);
	int res = 0, count = 0;
	if (pre_edge != -1)
	{
		dsu_union(dsu, edges[pre_edge].from, edges[pre_edge].to);
		res += edges[pre_edge].weight;
		++count;
	}
	for (int i = 0; i < edgesSize && count < n - 1; ++i) //choose n-1 edges
	{
		if (pre_edge == i || block_edge == i)
			continue;
		if (dsu_union(dsu, edges[i].from, edges[i].to))
		{
			res += edges[i].weight;
			++count;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (dsu_find(dsu, i) != dsu_find(dsu, 0))
			return INT_MAX;
	}
	return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findCriticalAndPseudoCriticalEdges(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
	EDGES edge[edgesSize];
	for (int i = 0; i < edgesSize; ++i)
	{
		edge[i].from = edges[i][0];
		edge[i].to = edges[i][1];
		edge[i].weight = edges[i][2];
		edge[i].index = i;
	}
	qsort(edge, edgesSize, sizeof(EDGES), cmp);
	int mst = mimimumSpanningTree(n, edge, edgesSize, -1, -1);
	*returnSize = 2;
	*returnColumnSizes = (int *)malloc(sizeof(int) * 2);
	int **res = (int **)malloc(sizeof(int *) * 2);
	for (int i = 0; i < 2; ++i)
		res[i] = (int *)malloc(sizeof(int) * edgesSize);
	int critical = 0, pseudo = 0;
	for (int i = 0; i < edgesSize; ++i)
	{
		if (mimimumSpanningTree(n, edge, edgesSize, -1, i) > mst)
			res[0][critical++] = edge[i].index;
		else if (mimimumSpanningTree(n, edge, edgesSize, i, -1) == mst)
			res[1][pseudo++] = edge[i].index;
	}
	(*returnColumnSizes)[0] = critical;
	(*returnColumnSizes)[1] = pseudo;
	return res;
}