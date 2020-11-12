#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int val;
	struct Trie *nodes[26];
} Trie;

Trie *createNode(int val)
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	node->val = val;
	return node;
}

void insert(Trie *root, char *str, int index)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			root->nodes[index] = createNode(-1);
		root = root->nodes[index];
	}
	root->val = index;
}

char **addString(char **res, int size, char *s)
{
	res = (char **)realloc(res, size * sizeof(char *));
	res[size - 1] = strdup(s);
	return res;
}

bool backTracking(Trie *root, Trie *node, char *s, int index, int indexOfWords)
{
	if (!s[index])
		return node->val != -1 && node->val != indexOfWords;
	Trie *cur = node->nodes[s[index] - 'a'];
	if (!cur)
		return false;
	return (cur->val != -1 && backTracking(root, root, s, index + 1, indexOfWords)) ||
		   backTracking(root, cur, s, index + 1, indexOfWords);
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
		if (backTracking(root, root, words[i], 0, i))
			res = addString(res, ++*returnSize, words[i]);
	}
	return res;
}