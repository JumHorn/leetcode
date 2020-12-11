#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
	int index;
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
	res[*size - 1] = strdup(word);
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
	root->index = index + 1;
}

void dfs(char **board, int M, int N, int row, int col, Trie *root, char **words, char ***res, int *size)
{
	if (row < 0 || row >= M || col < 0 || col >= N || board[row][col] == ' ')
		return;
	root = root->node[board[row][col] - 'a'];
	if (!root)
		return;
	if (root->index != 0)
	{ //add result
		++(*size);
		*res = addString(*res, size, words[root->index - 1]);
		root->index = 0; //avoid duplicate
	}
	char old = board[row][col];
	board[row][col] = ' ';
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
	{
		int dx = row + path[k], dy = col + path[k + 1];
		dfs(board, M, N, dx, dy, root, words, res, size);
	}
	board[row][col] = old;
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