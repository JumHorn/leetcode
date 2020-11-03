#include <stdbool.h>
#include <stdlib.h>

typedef struct DSU
{
	int *parent;
	int size;
} DSU;

DSU *dsu_init(int N)
{
	DSU *dsu = (DSU *)malloc(sizeof(DSU));
	dsu->parent = (int *)malloc(sizeof(int) * N);
	dsu->size = N;
	for (int i = 0; i < N; ++i)
		dsu->parent[i] = i;
	return dsu;
}

void dsu_release(DSU *dsu)
{
	if (dsu)
	{
		if (dsu->parent)
			free(dsu->parent);
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
	--dsu->size;
	dsu->parent[yr] = xr;
	return true;
}

bool strDiff(char *lhs, char *rhs)
{
	int res = 0;
	while (*lhs)
	{
		if (*lhs != *rhs)
			++res;
		++lhs;
		++rhs;
	}
	return res == 0 || res == 2;
}

int numSimilarGroups(char **A, int ASize)
{
	DSU *dsu = dsu_init(ASize);
	for (int i = 0; i < ASize - 1; ++i)
	{
		for (int j = i + 1; j < ASize; ++j)
		{
			if (strDiff(A[i], A[j]))
				dsu_union(dsu, i, j);
		}
	}
	return dsu->size;
}
