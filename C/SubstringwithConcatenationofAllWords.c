#include <stdlib.h>
#include <string.h>

//definition of Trie
struct Trie
{
	int index; //index of words,default to -1
	struct Trie *node[26];
};

//create a new node
struct Trie *createNode(int index)
{
	struct Trie *root = (struct Trie *)malloc(sizeof(struct Trie));
	memset((void *)root, 0, sizeof(struct Trie));
	root->index = index;
	return root;
}

//insert word to the trie and find the same word at the same time
void insert(struct Trie *root, char *word, int index, int *seen)
{
	while (*word)
	{
		int tmp = *word - 'a';
		if (!root->node[tmp])
			root->node[tmp] = createNode(-1);
		root = root->node[tmp];
		++word;
	}
	if (root->index == -1)
		root->index = index;
	++seen[root->index];
}

//result 0 success -1 failure
int search(struct Trie *root, char *s, int *seen, int size)
{
	struct Trie *head = root;
	while (*s)
	{
		int tmp = *s - 'a';
		if (!head->node[tmp])
			return -1;
		head = head->node[tmp];
		if (head->index >= 0)
		{
			if (--seen[head->index] < 0)
				return -1;
			if (--size == 0)
				return 0;
			head = root;
		}
		++s;
	}
	return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
	*returnSize = 0;
	int *res = (int *)malloc(sizeof(int) * 100);
	if (wordsSize == 0)
		return res;

	struct Trie *trie = createNode(-1);
	//build trie
	int seen[wordsSize]; //0 not found 1 found
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < wordsSize; ++i)
		insert(trie, words[i], i, seen);
	//malloc for the result
	int size = strlen(words[0]) * wordsSize; //sum of all words size
	int slen = strlen(s);					 //length of string s
	for (int i = 0; i <= slen - size; ++i)
	{
		int tmp[wordsSize];
		memcpy(tmp, seen, sizeof(tmp));
		if (search(trie, s + i, tmp, wordsSize) == 0)
			res[(*returnSize)++] = i;
	}
	return res;
}
