#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
	int val;
	struct Trie *node[26];
} Trie;

struct Trie *createNode(int val)
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	node->val = val;
	return node;
}

void insert(Trie *root, char *s)
{
	while (*s)
	{
		int index = *s - 'a';
		if (!root->node[index])
			root->node[index] = createNode(0);
		root = root->node[index];
		++s;
	}
	root->val = 1;
}

char **addString(char **res, int size, char *s, int len)
{
	char *tmp = (char *)malloc((len + 1) * sizeof(char));
	strcpy(tmp, s);
	res = (char **)realloc(res, size * sizeof(char *));
	res[size - 1] = tmp;
	return res;
}

void dfs(Trie *root, Trie *node, char *s, char *buff, int index, int *size, char ***res)
{
	if (!*s)
	{
		if (node && node->val == 1)
		{
			buff[index] = '\0';
			*res = addString(*res, ++(*size), buff, index);
		}
		return;
	}
	if (!node)
		return;
	if (node->val == 1)
	{
		buff[index] = ' ';
		dfs(root, root, s, buff, index + 1, size, res);
	}
	buff[index] = *s;
	int tmp = *s - 'a';
	dfs(root, node->node[tmp], s + 1, buff, index + 1, size, res);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize)
{
	//create Trie
	Trie *root = createNode(0);
	for (int i = 0; i < wordDictSize; i++)
		insert(root, wordDict[i]);
	*returnSize = 0;
	char buff[1000];
	char **res = 0;
	dfs(root, root, s, buff, 0, returnSize, &res);
	return res;
}