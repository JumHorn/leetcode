#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int count; //number of words end with this node
	int value;
	struct Trie *nodes[26];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

void insert(Trie *root, char *str, int value)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			root->nodes[index] = createNode();
		root = root->nodes[index];
	}
	++root->count;
	root->value = value;
}

Trie *searchNode(Trie *root, char *str)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			return NULL;
		root = root->nodes[index];
	}
	return root;
}

int dfs(Trie *root)
{
	if (!root)
		return 0;
	int res = root->value;
	for (int i = 0; i < 26; ++i)
		res += dfs(root->nodes[i]);
	return res;
}

int prefixsum(Trie *root, char *str)
{
	root = searchNode(root, str);
	return dfs(root);
}
/********end of prefix tree********/

typedef struct
{
	Trie *root;
} MapSum;

/** Initialize your data structure here. */

MapSum *mapSumCreate()
{
	MapSum *res = (MapSum *)malloc(sizeof(MapSum));
	res->root = createNode();
	return res;
}

void mapSumInsert(MapSum *obj, char *key, int val)
{
	insert(obj->root, key, val);
}

int mapSumSum(MapSum *obj, char *prefix)
{
	return prefixsum(obj->root, prefix);
}

void mapSumFree(MapSum *obj)
{
	if (obj)
	{
		if (obj->root)
			free(obj->root);
		free(obj);
	}
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);

 * int param_2 = mapSumSum(obj, prefix);

 * mapSumFree(obj);
*/