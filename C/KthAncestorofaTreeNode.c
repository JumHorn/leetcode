#include <stdlib.h>
#include <string.h>

typedef struct
{
	int** parent;
	int size;
} TreeAncestor;

TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize)
{
	TreeAncestor* obj = (TreeAncestor*)malloc(sizeof(TreeAncestor));
	obj->parent = (int**)malloc(sizeof(int*) * n);
	obj->size = parentSize;
	for (int i = 0; i < n; ++i)
		obj->parent[i] = (int*)malloc(sizeof(int) * 21);
	//init
	for (int i = 0; i < n; ++i)
		obj->parent[i][0] = parent[i];
	for (int j = 0; j < 20; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (obj->parent[i][j] == -1)
				obj->parent[i][j + 1] = -1;
			else
				obj->parent[i][j + 1] = obj->parent[obj->parent[i][j]][j];
		}
	}
	return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k)
{
	for (int i = 0; i < 21; ++i)
	{
		if ((k >> i) & 1)
		{
			node = obj->parent[node][i];
			if (node == -1)
				return -1;
		}
	}
	return node;
}

void treeAncestorFree(TreeAncestor* obj)
{
	for (int i = 0; i < obj->size; ++i)
		free(obj->parent[i]);
	free(obj->parent);
	free(obj);
}

/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/
