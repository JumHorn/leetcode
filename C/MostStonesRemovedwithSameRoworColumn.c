#include <stdbool.h>
#include <stdlib.h>

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

int removeStones(int **stones, int stonesSize, int *stonesColSize)
{
	DSU *dsu = dsu_init(20000);
	//for each point, union two indexes.
	for (int i = 0; i < stonesSize; ++i)
		dsu_union(dsu, stones[i][0], stones[i][1] + 10000);
	int seen[10000] = {0}, seenSize = 0;
	for (int i = 0; i < stonesSize; ++i)
	{
		int p = dsu_find(dsu, stones[i][0]);
		if (seen[p] == 0)
		{
			seen[p] = 1;
			++seenSize;
		}
	}
	return stonesSize - seenSize;
}