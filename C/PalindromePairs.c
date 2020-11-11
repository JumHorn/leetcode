#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int index;
	struct Trie *nodes[26];
} Trie;

Trie *createNode(int val)
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	node->index = val;
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
	root->index = index;
}

bool isPalindrome(char *s, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		if (s[first] != s[last])
			return false;
	}
	return true;
}

int **addPair(int **res, int *resSize, int i, int j)
{
	++(*resSize);
	res = (int **)realloc(res, sizeof(int *) * (*resSize));
	res[*resSize - 1] = (int *)malloc(sizeof(int) * 2);
	res[*resSize - 1][0] = i;
	res[*resSize - 1][1] = j;
	return res;
}

void search(Trie *root, char **words, int *wordsColSize, int index, int ***res, int *resSize)
{
	if (!root)
		return;
	if (root->index >= 0 && wordsColSize[index] != wordsColSize[root->index] &&
		isPalindrome(words[root->index], wordsColSize[index], wordsColSize[root->index] - 1))
		*res = addPair(*res, resSize, root->index, index);
	for (int i = 0; i < 26; ++i)
		search(root->nodes[i], words, wordsColSize, index, res, resSize);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **palindromePairs(char **words, int wordsSize, int *returnSize, int **returnColumnSizes)
{
	Trie *trie = createNode(-1);
	for (int i = 0; i < wordsSize; ++i)
		insert(trie, words[i], i);
	int wordsColSize[wordsSize];
	for (int i = 0; i < wordsSize; ++i)
		wordsColSize[i] = strlen(words[i]);
	*returnSize = 0;
	int **res = NULL;
	for (int i = 0; i < wordsSize; ++i)
	{
		//exist empty string
		if (trie->index >= 0 && trie->index != i &&
			isPalindrome(words[i], 0, wordsColSize[i] - 1))
			res = addPair(res, returnSize, trie->index, i);
		Trie *node = trie;
		for (int j = wordsColSize[i] - 1; j >= 0; --j)
		{
			node = node->nodes[words[i][j] - 'a'];
			if (!node)
				break;
			if (node->index >= 0 && node->index != i && isPalindrome(words[i], 0, j - 1))
				res = addPair(res, returnSize, node->index, i);
		}
		search(node, words, wordsColSize, i, &res, returnSize);
	}
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}