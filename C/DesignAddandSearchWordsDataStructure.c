#include <stdbool.h>
#include <stdlib.h>

typedef struct WordDictionary
{
	int count; //number of words end with this node
	struct WordDictionary *nodes[26];
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary *wordDictionaryCreate()
{
	WordDictionary *node = (WordDictionary *)malloc(sizeof(WordDictionary));
	memset(node, 0, sizeof(WordDictionary));
	return node;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary *obj, char *word)
{
	while (*word)
	{
		int index = *word++ - 'a';
		if (!obj->nodes[index])
			obj->nodes[index] = wordDictionaryCreate();
		obj = obj->nodes[index];
	}
	++obj->count;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary *obj, char *word)
{
	while (*word)
	{
		if (*word == '.')
		{
			for (int i = 0; i < 26; ++i)
			{
				if (obj->nodes[i] && wordDictionarySearch(obj->nodes[i], word + 1))
					return true;
			}
			return false;
		}
		int index = *word++ - 'a';
		if (!obj->nodes[index])
			return false;
		obj = obj->nodes[index];
	}
	return obj->count > 0;
}

void wordDictionaryFree(WordDictionary *obj)
{
	if (!obj)
		return;
	for (int i = 0; i < 26; ++i)
		wordDictionaryFree(obj->nodes[i]);
	free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/