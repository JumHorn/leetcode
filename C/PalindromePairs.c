#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Trie
{
	int index;
	struct Trie *node[26];
};

struct Trie *creataNode(int v)
{
	struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie));
	memset(node, 0, sizeof(struct Trie));
	node->index = v;
	return node;
}

void insert(struct Trie *root, char *s, int index)
{
	if (!*s)
	{
		root->index = index;
		return;
	}
	while (*s)
	{
		if (!root->node[*s - 'a'])
			root->node[*s - 'a'] = creataNode(-1);
		root = root->node[*s - 'a'];
		++s;
	}
	root->index = index;
}

bool isPalindrome(char *s, int start, int end)
{
	--end;
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

int **addPair(int **res, int *size, int i, int j)
{
	++(*size);
	res = (int **)realloc(res, sizeof(int *) * (*size));
	res[*size - 1] = (int *)malloc(sizeof(int) * 2);
	res[*size - 1][0] = i;
	res[*size - 1][1] = j;
	return res;
}

void search(struct Trie *root, int index, char **words, int *len, int ***res, int *size)
{
	if (!root)
		return;
	if (root->index >= 0 && len[index] != len[root->index] && isPalindrome(words[root->index], len[index], len[root->index]))
		*res = addPair(*res, size, root->index, index);
	for (int i = 0; i < 26; ++i)
		search(root->node[i], index, words, len, res, size);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **palindromePairs(char **words, int wordsSize, int *returnSize, int **returnColumnSizes)
{
	struct Trie *root = creataNode(-1);
	for (int i = 0; i < wordsSize; ++i)
		insert(root, words[i], i);
	int len[wordsSize];
	for (int i = 0; i < wordsSize; ++i)
		len[i] = strlen(words[i]);
	*returnSize = 0;
	int **res = NULL;
	for (int i = 0; i < wordsSize; ++i)
	{
		//exist empty string
		if (root->index >= 0 && root->index != i && isPalindrome(words[i], 0, len[i]))
			res = addPair(res, returnSize, root->index, i);
		struct Trie *tmp = root;
		for (int j = len[i] - 1; j >= 0; --j)
		{
			tmp = tmp->node[words[i][j] - 'a'];
			if (!tmp)
				break;
			if (tmp->index >= 0 && tmp->index != i && isPalindrome(words[i], 0, j))
				res = addPair(res, returnSize, tmp->index, i);
		}
		search(tmp, i, words, len, &res, returnSize);
	}
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}