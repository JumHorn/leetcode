#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

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

void dfs(char *s, int index, int size, int *res)
{
	char data[20] = {0};
	if (!s[index])
		*res = max(*res, size);
	for (int i = index; s[i]; ++i)
	{
		strncpy(data, &s[index], i - index + 1);
		HashNode *node = hash_get(data);
		if (!node)
		{
			hash_set(strdup(data));
			dfs(s, i + 1, size + 1, res);
			hash_erase(data);
		}
	}
}

int maxUniqueSplit(char *s)
{
	hash_init();
	int res = 0;
	dfs(s, 0, 0, &res);
	return res;
}