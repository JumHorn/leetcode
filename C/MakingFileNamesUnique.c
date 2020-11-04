#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	char *key;
	int value;
	struct HashNode *next;
} HashNode;

HashNode *HashTable[HASH_TABLE_SIZE];

int hash_str(char *key)
{
	int p = 1, res = 0;
	for (int i = 0; key[i]; ++i)
	{
		p = ((p * 31) & (HASH_TABLE_SIZE - 1));
		res = ((res + p * key[i]) & (HASH_TABLE_SIZE - 1));
	}
	return res;
}

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

HashNode *hash_createNode(char *key, int value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void hash_set(char *key, int value)
{
	int bucket = (hash_str(key) & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
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

HashNode *hash_get(char *key)
{
	int bucket = (hash_str(key) & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
			break;
		head = head->next;
	}
	return head;
}

void hash_erase(char *key)
{
	int bucket = (hash_str(key) & (HASH_TABLE_SIZE - 1));
	HashNode **head = &HashTable[bucket];
	while (*head)
	{
		if (strcmp((*head)->key, key) == 0)
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
char **getFolderNames(char **names, int namesSize, int *returnSize)
{
	hash_init();
	*returnSize = 0;
	char name[50];
	char **res = (char **)malloc(sizeof(char *) * namesSize);
	for (int i = 0; i < namesSize; ++i)
	{
		HashNode *node = hash_get(names[i]);
		if (!node)
		{
			res[(*returnSize)++] = strdup(names[i]);
			hash_set(names[i], 1);
		}
		else
		{
			int n = node->value;
			sprintf(name, "%s(%d)", node->key, n);
			while (hash_get(name) != NULL)
				sprintf(name, "%s(%d)", node->key, ++n);
			res[(*returnSize)++] = strdup(name);
			hash_set(res[(*returnSize) - 1], 1);
			hash_set(node->key, n + 1);
		}
	}
	return res;
}