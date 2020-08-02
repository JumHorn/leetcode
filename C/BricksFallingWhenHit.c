#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

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

int dsu_count(DSU *dsu, int x)
{
	return dsu->rank[dsu_find(dsu, x)];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *hitBricks(int **grid, int gridSize, int *gridColSize, int **hits, int hitsSize, int *hitsColSize, int *returnSize)
{
	int M = gridSize, N = *gridColSize;
	int old_grid[M][N];
	for (int i = 0; i < M; ++i)
		memcpy(old_grid[i], grid[i], sizeof(int) * N);
	DSU *dsu = dsu_init(M * N + 1);
	for (int i = 0; i < hitsSize; ++i)
		grid[hits[i][0]][hits[i][1]] = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				int index = i * N + j;
				if (i == 0)
					dsu_union(dsu, index, M * N);
				if (i > 0 && grid[i - 1][j] == 1)
					dsu_union(dsu, index, (i - 1) * N + j);
				if (j > 0 && grid[i][j - 1] == 1)
					dsu_union(dsu, index, i * N + j - 1);
			}
		}
	}

	*returnSize = hitsSize;
	int *res = (int *)malloc(sizeof(int) * hitsSize);
	memset(res, 0, sizeof(int) * hitsSize);
	for (int i = hitsSize - 1; i >= 0; --i)
	{
		int r = hits[i][0];
		int c = hits[i][1];
		int pre = dsu_count(dsu, M * N);
		if (old_grid[r][c] != 0)
		{
			int index = r * N + c;
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int k = 0; k < 4; ++k)
			{
				int dr = r + path[k], dc = c + path[k + 1];
				if (dr >= 0 && dr < M && dc >= 0 && dc < N && grid[dr][dc] == 1)
					dsu_union(dsu, index, dr * N + dc);
			}
			if (r == 0)
				dsu_union(dsu, index, M * N);
			grid[r][c] = 1;
			int val = dsu_count(dsu, M * N) - pre - 1;
			res[i] = max(0, val);
		}
	}
	return res;
}