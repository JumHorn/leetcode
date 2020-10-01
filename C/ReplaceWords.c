#include <stdbool.h>
#include <stdio.h>
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

bool search(Trie *root, char *str, char *out)
{
	while (*str)
	{
		*out++ = *str;
		*out = '\0';
		int index = *str++ - 'a';
		if (!root->nodes[index])
			return false;
		root = root->nodes[index];
		if (root->count > 0)
			return true;
	}
	return true;
}
/********end of prefix tree********/

char *replaceWords(char **dictionary, int dictionarySize, char *sentence)
{
	Trie *trie = createNode();
	for (int i = 0; i < dictionarySize; ++i)
		insert(trie, dictionary[i]);
	char token[1001], prefix[1001], *p = sentence, *q = sentence;
	while (sscanf(p, "%s", token) != EOF)
	{
		while (*p && *p != ' ')
			++p;
		if (*p)
			++p;
		if (search(trie, token, prefix))
			strcpy(q, prefix);
		else
			strcpy(q, token);
		while (*q)
			++q;
		*q++ = ' ';
	}
	*(q - 1) = '\0';
	return sentence;
}