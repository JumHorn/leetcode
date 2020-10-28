#include <stdbool.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE (1 << 10)

typedef struct HashNode
{
	int key;
	struct HashNode *next;
} HashNode;

HashNode *hash_createNode(int key)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->next = NULL;
	return node;
}

typedef struct
{
	HashNode *HashTable[HASH_TABLE_SIZE];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet *myHashSetCreate()
{
	MyHashSet *hashset = (MyHashSet *)malloc(sizeof(MyHashSet));
	memset(hashset->HashTable, 0, sizeof(HashNode *) * HASH_TABLE_SIZE);
	return hashset;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = obj->HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			return;
		head = head->next;
	}
	head = hash_createNode(key);
	head->next = obj->HashTable[bucket];
	obj->HashTable[bucket] = head;
}

void myHashSetRemove(MyHashSet *obj, int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode **head = &obj->HashTable[bucket];
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

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet *obj, int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = obj->HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			return true;
		head = head->next;
	}
	return false;
}

void myHashSetFree(MyHashSet *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/