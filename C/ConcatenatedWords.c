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

void insert(Trie *root, char *s, int index)
{
	while (*s)
	{
		int index = *s - 'a';
		if (!root->node[index])
			root->node[index] = createNode(-1);
		root = root->node[index];
		++s;
	}
	root->val = index;
}

char **addString(char **res, int size, char *s)
{
	res = (char **)realloc(res, size * sizeof(char *));
	res[size - 1] = strdup(s);
	return res;
}

bool backTracking(Trie *root, Trie *node, char *s, int index, int first)
{
	if (!s[first])
		return node->val != -1 && node->val != index;
	Trie *tmp = node->node[s[first] - 'a'];
	if (!tmp)
		return false;
	if (tmp->val != -1 && backTracking(root, root, s, index, first + 1))
		return true;
	return backTracking(root, tmp, s, index, first + 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findAllConcatenatedWordsInADict(char **words, int wordsSize, int *returnSize)
{
	//create Trie
	Trie *root = createNode(-1);
	for (int i = 0; i < wordsSize; ++i)
	{
		if (*words[i])
			insert(root, words[i], i);
	}
	*returnSize = 0;
	char **res = NULL;
	for (int i = 0; i < wordsSize; ++i)
	{
		if (backTracking(root, root, words[i], i, 0))
			res = addString(res, ++*returnSize, words[i]);
	}
	return res;
}