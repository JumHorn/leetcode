#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
	int count;
	struct Trie *node[26];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

char **addString(char **res, int *size, char *word)
{
	res = (char **)realloc(res, *size * sizeof(char *));
	int len = strlen(word);
	res[*size - 1] = (char *)malloc((len + 1) * sizeof(char));
	strcpy(res[*size - 1], word);
	return res;
}

void insert(Trie *root, char *word, int index)
{
	while (*word)
	{
		int index = *word - 'a';
		if (!root->node[index])
			root->node[index] = createNode();
		root = root->node[index];
		++word;
	}
	root->count = index + 1;
}

void dfs(char **board, int m, int n, int i, int j, Trie *root, char **words, char ***res, int *size)
{
	if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == ' ')
		return;
	root = root->node[board[i][j] - 'a'];
	if (!root)
		return;
	if (root->count != 0)
	{ //add result
		++(*size);
		*res = addString(*res, size, words[root->count - 1]);
		root->count = 0;
	}
	char tmp = board[i][j];
	board[i][j] = ' ';
	int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int k = 0; k < 4; k++)
	{
		int dx = i + path[k][0], dy = j + path[k][1];
		dfs(board, m, n, dx, dy, root, words, res, size);
	}
	board[i][j] = tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize)
{
	Trie *root = createNode();
	for (int i = 0; i < wordsSize; ++i)
		insert(root, words[i], i);
	char **res = NULL;
	*returnSize = 0;
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < *boardColSize; ++j)
			dfs(board, boardSize, *boardColSize, i, j, root, words, &res, returnSize);
	}
	return res;
}
