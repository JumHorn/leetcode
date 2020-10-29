#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 7)
typedef struct HashNode
{
	char *key;
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
	int bucket = (key[0] & (HASH_TABLE_SIZE - 1));
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **subdomainVisits(char **cpdomains, int cpdomainsSize, int *returnSize)
{
	hash_init();
	for (int i = 0; i < cpdomainsSize; ++i)
	{
		int count;
		sscanf(cpdomains[i], "%d", &count);
		strtok(cpdomains[i], " ");
		char *domain = strtok(NULL, " ");
		HashNode *node = hash_get(domain);
		node ? node->value += count : hash_set(domain, count);
		for (int i = 0; domain[i]; ++i)
		{
			if (domain[i] == '.')
			{
				HashNode *node = hash_get(&domain[i + 1]);
				node ? node->value += count : hash_set(&domain[i + 1], count);
			}
		}
	}
	char **res = (char **)malloc(sizeof(char *) * 300);
	*returnSize = 0;
	char data[200];
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		for (HashNode *head = HashTable[i]; head; head = head->next)
		{
			sprintf(data, "%d %s", head->value, head->key);
			res[(*returnSize)++] = strdup(data);
		}
	}
	return res;
}