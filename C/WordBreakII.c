#include <stdbool.h>
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

char **addString(char **res, int *size, char *s, int len)
{
	char *data = (char *)malloc((len + 1) * sizeof(char));
	strcpy(data, s);
	res = (char **)realloc(res, sizeof(char *) * (*size + 1));
	res[*size] = data;
	++*size;
	return res;
}

void dfs(Trie *root, Trie *node, char *s, char *buff, int index, int *size, char ***res)
{
	if (!*s)
	{
		if (node && node->val == 1)
		{
			buff[index] = '\0';
			*res = addString(*res, size, buff, index);
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

bool canBreak(char *s, char **wordDict, int wordDictSize)
{
	int N = strlen(s);
	bool dp[N + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j >= 0 && !dp[i + 1]; --j)
		{
			for (int k = 0; k < wordDictSize; ++k)
			{
				if (strncmp(wordDict[k], s + j, i - j + 1) == 0)
					dp[i + 1] = dp[j];
			}
		}
	}
	return dp[N];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize)
{
	*returnSize = 0;
	if (!canBreak(s, wordDict, wordDictSize))
		return NULL;
	//create Trie
	Trie *root = createNode(0);
	for (int i = 0; i < wordDictSize; i++)
		insert(root, wordDict[i]);
	char buff[1000];
	char **res = 0;
	dfs(root, root, s, buff, 0, returnSize, &res);
	return res;
}