#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *avoidFlood(int *rains, int rainsSize, int *returnSize)
{
	*returnSize = rainsSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int dryDay[rainsSize], dryDaySize = 0; //index
	hash_init();						   //{lake,index}
	for (int i = 0; i < rainsSize; ++i)
	{
		if (rains[i] == 0)
		{
			res[i] = 1;
			dryDay[dryDaySize++] = i;
		}
		else
		{
			res[i] = -1;
			HashNode *node = hash_get(rains[i]);
			if (node)
			{
				if (dryDaySize == 0 || dryDay[dryDaySize - 1] < node->value)
				{
					*returnSize = 0;
					return NULL;
				}
				int dry = dryDay[dryDaySize - 1];
				for (int i = dryDaySize - 2; i >= 0 && dryDay[i] >= node->value; --i)
					swap(dry, dryDay[i]);
				--dryDaySize;
				res[dry] = rains[i];
			}
			hash_set(rains[i], i);
		}
	}
	return res;
}