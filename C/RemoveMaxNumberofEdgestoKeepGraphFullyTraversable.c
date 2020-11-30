#include <stdbool.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *createNode(int val)
{
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = val;
	return node;
}

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

int dsu_count(DSU *dsu, int x)
{
	return dsu->rank[dsu_find(dsu, x)];
}

bool fullTraversal(DSU *dsu)
{
	int size = dsu->size - 1;
	return dsu->rank[dsu_find(dsu, 1)] == size;
}
/********end of DSU********/

int maxNumEdgesToRemove(int n, int **edges, int edgesSize, int *edgesColSize)
{
	struct ListNode *type[3] = {NULL};
	for (int i = 0; i < edgesSize; ++i)
	{
		struct ListNode *node = createNode(i);
		node->next = type[edges[i][0] - 1];
		type[edges[i][0] - 1] = node;
	}
	int edgeAdded = 0;
	DSU *alice = dsu_init(n + 1), *bob = dsu_init(n + 1);
	for (struct ListNode *node = type[2]; node; node = node->next)
	{
		if (dsu_union(alice, edges[node->val][1], edges[node->val][2]) | dsu_union(bob, edges[node->val][1], edges[node->val][2]))
			++edgeAdded;
	}
	for (struct ListNode *node = type[0]; node; node = node->next)
	{
		if (dsu_union(alice, edges[node->val][1], edges[node->val][2]))
			++edgeAdded;
	}
	for (struct ListNode *node = type[1]; node; node = node->next)
	{
		if (dsu_union(bob, edges[node->val][1], edges[node->val][2]))
			++edgeAdded;
	}
	return (!fullTraversal(alice) || !fullTraversal(bob)) ? -1 : edgesSize - edgeAdded;
}