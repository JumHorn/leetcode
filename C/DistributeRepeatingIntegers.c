#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
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

bool canDistribute(int *nums, int numsSize, int *quantity, int quantitySize)
{
	hash_init(); //{value,count}
	for (int i = 0; i < numsSize; ++i)
	{
		HashNode *node = hash_get(nums[i]);
		node ? ++node->value : hash_set(nums[i], 1);
	}
	int count[50], countSize = 0;
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		for (HashNode *head = HashTable[i]; head; head = head->next)
			count[countSize++] = head->value;
	}

	int N = quantitySize;
	int quantity_mask_count[1 << N];
	memset(quantity_mask_count, 0, sizeof(quantity_mask_count));
	for (int mask = 0; mask < 1 << N; ++mask)
	{
		for (int bit = 0; bit < N; ++bit)
		{
			if ((mask >> bit) & 1)
				quantity_mask_count[mask] += quantity[bit];
		}
	}

	bool dp[1 << N];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for (int n = 0; n < countSize; ++n)
	{
		for (int i = (1 << N) - 1; i >= 0; --i)
		{
			if (!dp[i])
				continue;
			int mask = i ^ ((1 << N) - 1);
			for (int j = mask; j > 0; j = (j - 1) & mask)
			{
				if (count[n] >= quantity_mask_count[j])
					dp[i | j] = true;
			}
		}
	}
	return dp[(1 << N) - 1];
}