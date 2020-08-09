#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// DSU
typedef struct DSU
{
	int *parent;
	int *rank;
	int size;
} DSU;

DSU *dsu_init(int N)
{
	DSU *dsu = (DSU *)malloc(sizeof(DSU));
	dsu->parent = (int *)malloc(sizeof(int) * N);
	dsu->rank = (int *)malloc(sizeof(int) * N);
	dsu->size = N;
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

int dsu_getMaxCluster(DSU *dsu)
{
	int res = 1;
	for (int i = 0; i < dsu->size; ++i)
	{
		if (dsu->parent[i] == i && dsu->rank[i] > res)
			res = dsu->rank[i];
	}
	return res;
}

int largestComponentSize(int *A, int ASize)
{
	DSU *dsu = dsu_init(ASize);
	int factor[100001];
	memset(factor, -1, sizeof(factor));
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 2; j * j <= A[i]; ++j)
		{
			if (A[i] % j == 0)
			{
				if (factor[j] == -1)
					factor[j] = i;
				else
					dsu_union(dsu, i, factor[j]);

				if (factor[A[i] / j] == -1)
					factor[A[i] / j] = i;
				else
					dsu_union(dsu, i, factor[A[i] / j]);
			}
		}
		if (factor[A[i]] == -1)
			factor[A[i]] = i;
		else
			dsu_union(dsu, i, factor[A[i]]);
	}
	return dsu_getMaxCluster(dsu);
}