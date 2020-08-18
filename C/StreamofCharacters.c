#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
	int val;
	struct Trie *node[26];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

void insert(Trie *root, char *s)
{
	int len = strlen(s);
	for (int i = len - 1; i >= 0; --i)
	{
		int index = s[i] - 'a';
		if (!root->node[index])
			root->node[index] = createNode();
		root = root->node[index];
	}
	root->val = 1;
}

typedef struct StreamChecker
{
	char query[40001];
	int size;
	Trie *root;
} StreamChecker;

StreamChecker *createChecker()
{
	StreamChecker *node = (StreamChecker *)malloc(sizeof(StreamChecker));
	memset(node, 0, sizeof(StreamChecker));
	node->root = createNode();
	return node;
}

StreamChecker *streamCheckerCreate(char **words, int wordsSize)
{
	StreamChecker *node = createChecker();
	for (int i = 0; i < wordsSize; ++i)
		insert(node->root, words[i]);
	return node;
}

bool streamCheckerQuery(StreamChecker *obj, char letter)
{
	obj->query[obj->size++] = letter;
	Trie *node = obj->root;
	for (int i = obj->size - 1; i >= 0; --i)
	{
		node = node->node[obj->query[i] - 'a'];
		if (node == NULL)
			return false;
		if (node->val == 1)
			return true;
	}
	return false;
}

void streamCheckerFree(StreamChecker *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your StreamChecker struct will be instantiated and called as such:
 * StreamChecker* obj = streamCheckerCreate(words, wordsSize);
 * bool param_1 = streamCheckerQuery(obj, letter);

 * streamCheckerFree(obj);
*/