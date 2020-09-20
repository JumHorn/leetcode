#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
	int count; //number of words end with this node
	struct Trie *nodes[26];
} Trie;

/** Initialize your data structure here. */

Trie *trieCreate()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

/** Inserts a word into the trie. */
void trieInsert(Trie *obj, char *word)
{
	while (*word)
	{
		int index = *word++ - 'a';
		if (!obj->nodes[index])
			obj->nodes[index] = trieCreate();
		obj = obj->nodes[index];
	}
	++obj->count;
}

/** search a end node of str from the trie. for internal use */
static Trie *searchNode(Trie *obj, char *str)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!obj->nodes[index])
			return NULL;
		obj = obj->nodes[index];
	}
	return obj;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie *obj, char *word)
{
	obj = searchNode(obj, word);
	return obj && obj->count > 0;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie *obj, char *prefix)
{
	obj = searchNode(obj, prefix);
	return obj;
}

/** post order free from leaf node to root. */
void trieFree(Trie *obj)
{
	if (!obj)
		return;
	for (int i = 0; i < 26; ++i)
		trieFree(obj->nodes[i]);
	free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/