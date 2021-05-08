#include <stdbool.h>
#include <stdlib.h>

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
	int randaccess[10000];
	int randaccessSize;
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet *randomizedSetCreate()
{
	hash_init();
	RandomizedSet *res = (RandomizedSet *)malloc(sizeof(RandomizedSet));
	res->randaccessSize = 0;
	return res;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet *obj, int val)
{
	HashNode *node = hash_get(val);
	if (node)
		return false;
	hash_set(val, obj->randaccessSize);
	obj->randaccess[obj->randaccessSize++] = val;
	return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet *obj, int val)
{
	HashNode *node = hash_get(val);
	if (!node)
		return false;
	hash_set(obj->randaccess[obj->randaccessSize - 1], node->value);
	obj->randaccess[node->value] = obj->randaccess[--obj->randaccessSize];
	hash_erase(val);
	return true;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet *obj)
{
	return obj->randaccess[rand() % obj->randaccessSize];
}

void randomizedSetFree(RandomizedSet *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/