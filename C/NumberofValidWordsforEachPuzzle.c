#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 16)
typedef struct HashNode
{
	int key;
	int value;
	struct HashNode *next;
} HashNode;

HashNode *HashTable[HASH_TABLE_SIZE];

void hash_init()
{
	memset(HashTable, 0, sizeof(HashTable));
}

void hash_release()
{
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		HashNode *node = HashTable[i];
		while (node)
		{
			HashNode *deletenode = node;
			node = node->next;
			free(deletenode);
		}
	}
}

HashNode *hash_createNode(int key, int value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void hash_set(int key, int value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key)
		{
			head->value = value;
			return;
		}
		head = head->next;
	}
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			break;
		head = head->next;
	}
	return head;
}

void hash_erase(int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode **head = &HashTable[bucket];
	while (*head)
	{
		if ((*head)->key == key)
		{
			*head = (*head)->next;
			break;
		}
		head = &(*head)->next;
	}
}
/********end of HASH********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findNumOfValidWords(char **words, int wordsSize, char **puzzles, int puzzlesSize, int *returnSize)
{
	int N = puzzlesSize;
	*returnSize = N;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	hash_init(); //{mask,count}
	for (int i = 0; i < wordsSize; ++i)
	{
		int mask = 0;
		for (int j = 0; words[i][j]; ++j)
			mask |= (1 << (words[i][j] - 'a'));
		HashNode *node = hash_get(mask);
		node ? ++node->value : hash_set(mask, 1);
	}
	for (int i = 0; i < N; ++i)
	{
		int mask = 0;
		for (int j = 0; j < puzzles[i][j]; ++j)
			mask |= (1 << (puzzles[i][j] - 'a'));
		for (int submask = mask; submask != 0; submask = ((submask - 1) & mask)) //loop for all submask
		{
			if ((submask & (1 << (puzzles[i][0] - 'a'))) != 0)
			{
				HashNode *node = hash_get(submask);
				if (node)
					res[i] += node->value;
			}
		}
	}
	return res;
}