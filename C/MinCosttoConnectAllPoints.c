#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
Kruskal's algorithm
minimum spanning tree
find edge
*/

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
	for (int i = 0; i < N; ++i)
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
/********end of DSU********/

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int minCostConnectPoints(int **points, int pointsSize, int *pointsColSize)
{
	int N = pointsSize, edges[N * (N + 1) / 2][3], edgesSize = 0; //{distance,i,j}
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			edges[edgesSize][0] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			edges[edgesSize][1] = i;
			edges[edgesSize][2] = j;
			++edgesSize;
		}
	}
	qsort(edges, edgesSize, sizeof(edges[0]), cmp);
	DSU *dsu = dsu_init(N);
	int res = 0;
	for (int i = 0, edgeCount = 0; edgeCount < N - 1; ++i)
	{
		if (dsu_union(dsu, edges[i][1], edges[i][2]))
		{
			++edgeCount;
			res += edges[i][0];
		}
	}
	return res;
}