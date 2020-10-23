#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	int key;
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

HashNode *hash_createNode(int key)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->next = NULL;
	return node;
}

bool hash_set(int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			return false;
		head = head->next;
	}
	head = hash_createNode(key);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
	return true;
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
/********end of HASH********/

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	if (++k > numsSize)
		k = numsSize;
	hash_init();
	for (int i = 0; i < k; ++i)
	{
		if (!hash_set(nums[i]))
			return true;
	}
	for (int i = k; i < numsSize; ++i)
	{
		hash_erase(nums[i - k]);
		if (!hash_set(nums[i]))
			return true;
	}
	return false;
}