#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	int x;
	int y;
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

HashNode *hash_createNode(int x, int y)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->x = x;
	node->y = y;
	node->next = NULL;
	return node;
}

void hash_set(int x, int y)
{
	int bucket = (abs(x) & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->x == x && head->y == y)
			return;
		head = head->next;
	}
	head = hash_createNode(x, y);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(int x, int y)
{
	int bucket = (abs(x) & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->x == x && head->y == y)
			break;
		head = head->next;
	}
	return head;
}

void hash_erase(int x, int y)
{
	int bucket = (abs(x) & (HASH_TABLE_SIZE - 1));
	HashNode **head = &HashTable[bucket];
	while (*head)
	{
		if ((*head)->x == x && (*head)->y == y)
		{
			*head = (*head)->next;
			break;
		}
		head = &(*head)->next;
	}
}
/********end of HASH********/

bool isPathCrossing(char *path)
{
	hash_init();
	int x = 0, y = 0;
	hash_set(x, y);
	for (int i = 0; path[i]; ++i)
	{
		if (path[i] == 'N')
			++y;
		else if (path[i] == 'S')
			--y;
		else if (path[i] == 'E')
			++x;
		else
			--x;
		if (hash_get(x, y))
			return true;
		hash_set(x, y);
	}
	return false;
}