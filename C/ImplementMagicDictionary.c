#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int count;  //number of words end with this node
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

bool search(Trie *root, char *str, int change)
{
	if (!root)
		return false;
	if (!*str)
		return change == 0 && root->count > 0;
	if (change > 0)
	{
		for (int i = 0; i < 26; ++i)
		{
			if (search(root->nodes[i], str + 1, *str - 'a' != i ? 0 : 1))
				return true;
		}
	}
	else
	{
		if (search(root->nodes[*str - 'a'], str + 1, 0))
			return true;
	}
	return false;
}
/********end of prefix tree********/

typedef struct
{
	Trie *root;
} MagicDictionary;

/** Initialize your data structure here. */

MagicDictionary *magicDictionaryCreate()
{
	MagicDictionary *res = (MagicDictionary *)malloc(sizeof(MagicDictionary));
	res->root = createNode();
	return res;
}

void magicDictionaryBuildDict(MagicDictionary *obj, char **dictionary, int dictionarySize)
{
	for (int i = 0; i < dictionarySize; ++i)
		insert(obj->root, dictionary[i]);
}

bool magicDictionarySearch(MagicDictionary *obj, char *searchWord)
{
	return search(obj->root, searchWord, 1);
}

void magicDictionaryFree(MagicDictionary *obj)
{
	if (obj)
	{
		if (obj->root)
			free(obj->root);
		free(obj);
	}
}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dictionary, dictionarySize);
 
 * bool param_2 = magicDictionarySearch(obj, searchWord);
 
 * magicDictionaryFree(obj);
*/
