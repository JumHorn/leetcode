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

bool equationsPossible(char **equations, int equationsSize)
{
	DSU *dsu = dsu_init(26);
	for (int i = 0; i < equationsSize; ++i)
	{
		int a = equations[i][0] - 'a', b = equations[i][3] - 'a';
		if (equations[i][1] == '=')
			dsu_union(dsu, a, b);
	}
	for (int i = 0; i < equationsSize; ++i)
	{
		int a = equations[i][0] - 'a', b = equations[i][3] - 'a';
		if (equations[i][1] == '!' && dsu_find(dsu, a) == dsu_find(dsu, b))
			return false;
	}
	return true;
}