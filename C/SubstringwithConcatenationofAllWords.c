#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int index; //index of words,default to -1
	struct Trie *node[26];
} Trie;

//create a new node
Trie *createNode(int index)
{
	Trie *root = (Trie *)malloc(sizeof(Trie));
	memset((void *)root, 0, sizeof(Trie));
	root->index = index;
	return root;
}

//insert word to the trie and find the same word at the same time
void insert(Trie *root, char *word, int index, int *seen)
{
	while (*word)
	{
		int index = *word++ - 'a';
		if (!root->node[index])
			root->node[index] = createNode(-1);
		root = root->node[index];
	}
	if (root->index == -1)
		root->index = index;
	++seen[root->index];
}

//result 0 success -1 failure
int search(Trie *root, char *s, int *seen, int size)
{
	Trie *head = root;
	while (*s)
	{
		int index = *s++ - 'a';
		if (!head->node[index])
			return -1;
		head = head->node[index];
		if (head->index >= 0)
		{
			if (--seen[head->index] < 0)
				return -1;
			if (--size == 0)
				return 0;
			head = root;
		}
	}
	return -1;
}
/********end of prefix tree********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
	*returnSize = 0;
	int *res = (int *)malloc(sizeof(int) * 100);
	Trie *trie = createNode(-1);
	//build trie
	int count[wordsSize];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < wordsSize; ++i)
		insert(trie, words[i], i, count);
	int size = strlen(words[0]) * wordsSize; //sum of all words size
	int slen = strlen(s);					 //length of string s
	for (int i = 0; i <= slen - size; ++i)
	{
		int wordCountCopy[wordsSize];
		memcpy(wordCountCopy, count, sizeof(count));
		if (search(trie, s + i, wordCountCopy, wordsSize) == 0)
			res[(*returnSize)++] = i;
	}
	return res;
}