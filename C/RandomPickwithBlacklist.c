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

typedef struct
{
	int size;
} Solution;

Solution *solutionCreate(int N, int *blacklist, int blacklistSize)
{
	hash_init();
	Solution *solution = (Solution *)malloc(sizeof(Solution));
	for (int i = 0; i < blacklistSize; ++i)
		hash_set(blacklist[i], blacklist[i]);
	solution->size = N - blacklistSize;
	--N;
	for (int i = 0; i < blacklistSize; ++i)
	{
		if (blacklist[i] < solution->size)
		{
			for (HashNode *node = hash_get(N); node; node = hash_get(N))
				--N;
			hash_set(blacklist[i], N--);
		}
	}
	return solution;
}

int solutionPick(Solution *obj)
{
	int res = rand() % obj->size;
	HashNode *node = hash_get(res);
	return node ? node->value : res;
}

void solutionFree(Solution *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(N, blacklist, blacklistSize);
 * int param_1 = solutionPick(obj);

 * solutionFree(obj);
*/