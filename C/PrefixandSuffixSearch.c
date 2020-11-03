#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int val;
	struct Trie *node[26];
} Trie;

Trie *createNode(int val)
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	node->val = val;
	return node;
}

void insert(Trie *root, char *word, int weight)
{
	while (*word)
	{
		int index = *word - 'a';
		if (root->node[index] == NULL)
			root->node[index] = createNode(-1);
		root = root->node[index];
		++word;
	}
	root->val = weight;
}

Trie *search(Trie *root, char *prefix)
{
	while (*prefix)
	{
		int index = *prefix - 'a';
		if (root->node[index] == NULL)
			return NULL;
		root = root->node[index];
		++prefix;
	}
	return root;
}

typedef struct
{
	Trie *root;
	char **words;
	int wordsSize;
} WordFilter;

bool ends_with(char *s, char *suffix)
{
	int n = strlen(s), m = strlen(suffix);
	if (m == 0)
		return true;
	int i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0)
	{
		if (s[i] != suffix[j])
			return false;
		--i;
		--j;
	}
	return j == -1;
}

void dfs(Trie *root, char *suffix, char **words, int *res)
{
	if (!root)
		return;
	if (root->val >= 0 && root->val > *res)
	{
		if (ends_with(words[root->val], suffix))
			*res = root->val;
	}
	for (int i = 0; i < 26; ++i)
		dfs(root->node[i], suffix, words, res);
}

WordFilter *wordFilterCreate(char **words, int wordsSize)
{
	WordFilter *obj = (WordFilter *)malloc(sizeof(WordFilter));
	obj->words = words;
	obj->wordsSize = wordsSize;
	obj->root = createNode(-1);
	for (int i = 0; i < wordsSize; ++i)
		insert(obj->root, words[i], i);
	return obj;
}

int wordFilterF(WordFilter *obj, char *prefix, char *suffix)
{
	int res = -1;
	Trie *prefixroot = search(obj->root, prefix);
	dfs(prefixroot, suffix, obj->words, &res);
	return res;
}

void wordFilterFree(WordFilter *obj)
{
	//Trie not freed yet
	if (obj)
		free(obj);
}

/**
 * Your WordFilter struct will be instantiated and called as such:
 * WordFilter* obj = wordFilterCreate(words, wordsSize);
 * int param_1 = wordFilterF(obj, prefix, suffix);

 * wordFilterFree(obj);
*/