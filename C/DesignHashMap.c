#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE (1 << 10)

typedef struct HashNode
{
	int key;
	int value;
	struct HashNode *next;
} HashNode;

HashNode *hash_createNode(int key, int value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

typedef struct
{
	HashNode *HashTable[HASH_TABLE_SIZE];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap *myHashMapCreate()
{
	MyHashMap *hashmap = (MyHashMap *)malloc(sizeof(MyHashMap));
	memset(hashmap->HashTable, 0, sizeof(HashNode *) * HASH_TABLE_SIZE);
	return hashmap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap *obj, int key, int value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = obj->HashTable[bucket];
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
	head->next = obj->HashTable[bucket];
	obj->HashTable[bucket] = head;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap *obj, int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = obj->HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			break;
		head = head->next;
	}
	return head ? head->value : -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap *obj, int key)
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

void myHashMapFree(MyHashMap *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/