#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 16)
typedef struct HashNode
{
	char *key;
	int value;
	struct HashNode *next;
} HashNode;

HashNode *HashTable[HASH_TABLE_SIZE];

int hash_str(char *key)
{
	unsigned long hash = 5381;
	int c;

	while (c = *key++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
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

bool hash_set(char *key, int value)
{
	int bucket = (hash_str(key) & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			head->value = value;
			return false;
		}
		head = head->next;
	}
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
	return true;
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

int distinctEchoSubstrings(char *text)
{
	hash_init();
	int substrSize = 0, N = strlen(text), res = 0;
	int dp[N + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int j = N - 1; j > 0; --j)
	{
		for (int i = j - 1; i >= 0; --i)
		{
			dp[i][j] = text[i] == text[j] ? dp[i + 1][j + 1] + 1 : 0;
			if (dp[i][j] >= j - i)
			{
				char *str = strndup(&text[i], j - i);
				if (hash_set(str, 0))
					++res;
			}
		}
	}
	return res;
}