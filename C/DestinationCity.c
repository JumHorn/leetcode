#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 7)
typedef struct HashNode
{
	char *key;
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

HashNode *hash_createNode(char *key)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->next = NULL;
	return node;
}

void hash_set(char *key)
{
	int bucket = (key[0] & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return;
		head = head->next;
	}
	head = hash_createNode(key);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(char *key)
{
	int bucket = (key[0] & (HASH_TABLE_SIZE - 1));
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
	int bucket = (key[0] & (HASH_TABLE_SIZE - 1));
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

char *destCity(char ***paths, int pathsSize, int *pathsColSize)
{
	hash_init();
	for (int i = 0; i < pathsSize; ++i)
		hash_set(paths[i][1]);
	for (int i = 0; i < pathsSize; ++i)
		hash_erase(paths[i][0]);
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		for (HashNode *head = HashTable[i]; head; head = head->next)
		{
			return head->key;
		}
	}
	return "";
}