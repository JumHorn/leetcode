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
/********end of HASH********/

int maxNumberOfFamilies(int n, int **reservedSeats, int reservedSeatsSize, int *reservedSeatsColSize)
{
	int res = n * 2;
	hash_init();
	for (int i = 0; i < reservedSeatsSize; ++i)
	{
		HashNode *node = hash_get(reservedSeats[i][0]);
		if (node)
			node->value |= (1 << (reservedSeats[i][1] - 1));
		else
			hash_set(reservedSeats[i][0], (1 << (reservedSeats[i][1] - 1)));
	}
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		for (HashNode *head = HashTable[i]; head; head = head->next)
		{
			if ((head->value & 0b0111111110) == 0)
				continue;
			if ((head->value & 0b0001111000) == 0)
				--res;
			else if ((head->value & 0b0111100000) == 0)
				--res;
			else if ((head->value & 0b0000011110) == 0)
				--res;
			else
				res -= 2;
		}
	}
	return res;
}