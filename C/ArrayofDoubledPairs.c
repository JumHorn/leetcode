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
/********end of HASH********/

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

bool doubleCheck(int *arr, int arrSize)
{
	if (arrSize % 2 != 0)
		return false;
	qsort(arr, arrSize, sizeof(int), cmp);
	hash_init();
	for (int i = 0; i < arrSize; ++i)
	{
		HashNode *node = hash_get(arr[i]);
		node == NULL ? hash_set(arr[i], 1) : ++node->value;
	}
	for (int i = 0; i < arrSize; ++i)
	{
		HashNode *node1 = hash_get(arr[i]);
		if (node1->value == 0)
			continue;
		HashNode *node2 = hash_get(arr[i] * 2);
		if (node2 == NULL || node2->value == 0)
			return false;
		--node1->value;
		--node2->value;
	}
	return true;
}

bool canReorderDoubled(int *A, int ASize)
{
	int positive[ASize + 1], positiveSize = 0, negative[ASize + 1], negativeSize = 0;
	for (int i = 0; i < ASize; ++i)
	{
		if (A[i] >= 0)
			positive[positiveSize++] = A[i];
		else
			negative[negativeSize++] = -A[i];
	}
	return doubleCheck(positive, positiveSize) && doubleCheck(negative, negativeSize);
}