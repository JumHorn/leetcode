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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *areConnected(int n, int threshold, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
	*returnSize = queriesSize;
	bool *res = (bool *)malloc(sizeof(bool) * (*returnSize));
	if (threshold == 0)
	{
		for (int i = 0; i < *returnSize; ++i)
			res[i] = true;
		return res;
	}
	DSU *dsu = dsu_init(n + 1);
	for (int i = threshold + 1; i <= n; ++i)
	{
		for (int j = i * 2, k = 2; j <= n; j = i * (++k))
			dsu_union(dsu, i, j);
	}

	for (int i = 0; i < queriesSize; ++i)
		res[i] = (dsu_find(dsu, queries[i][0]) == dsu_find(dsu, queries[i][1]));
	return res;
}