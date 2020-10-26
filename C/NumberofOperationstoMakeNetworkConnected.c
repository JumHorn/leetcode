#include <stdbool.h>
#include <stdlib.h>

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
	for (int i = 0; i < N; ++i)
	{
		dsu->parent[i] = i;
		dsu->rank[i] = 1;
		dsu->size = N;
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

int dsu_union(DSU *dsu, int x, int y)
{
	int xr = dsu_find(dsu, x), yr = dsu_find(dsu, y);
	if (xr == yr)
		return 1; //redundant connection
	dsu->parent[yr] = xr;
	dsu->rank[xr] += dsu->rank[yr];
	return 0;
}

int dsu_getconnectedgroups(DSU *dsu)
{
	int res = 0;
	for (int i = 0; i < dsu->size; ++i)
	{
		if (dsu->parent[i] == i)
			++res;
	}
	return res;
}
/********end of DSU********/

int makeConnected(int n, int **connections, int connectionsSize, int *connectionsColSize)
{
	int res = 0;
	DSU *dsu = dsu_init(n);
	for (int i = 0; i < connectionsSize; ++i)
		res += dsu_union(dsu, connections[i][0], connections[i][1]);
	int group = dsu_getconnectedgroups(dsu);
	if (group <= 1)
		return 0;
	if (res < group - 1)
		return -1;
	return group - 1;
}