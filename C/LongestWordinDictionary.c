#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int count; //number of words end with this node
	struct Trie *nodes[26];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

void insert(Trie *root, char *str)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			root->nodes[index] = createNode();
		root = root->nodes[index];
	}
	++root->count;
}

void search(Trie *root, char *str, int strSize, char *res, int *resSize)
{
	if (!root || root->count == 0)
		return;
	if (strSize > *resSize)
	{
		strcpy(res, str);
		*resSize = strSize;
	}
	for (int i = 0; i < 26; ++i)
	{
		str[strSize] = i + 'a';
		search(root->nodes[i], str, strSize + 1, res, resSize);
	}
}
/********end of prefix tree********/

char *longestWord(char **words, int wordsSize)
{
	Trie *trie = createNode();
	trie->count = 1;
	for (int i = 0; i < wordsSize; ++i)
		insert(trie, words[i]);
	char instance[1000] = {0}, res[1000] = {0};
	int instanceSize = 0, resSize = 0;
	search(trie, instance, instanceSize, res, &resSize);
	return strdup(res);
}