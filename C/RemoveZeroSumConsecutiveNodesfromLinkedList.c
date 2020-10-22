#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	int key;
	struct ListNode *value;
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

HashNode *hash_createNode(int key, struct ListNode *value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void hash_set(int key, struct ListNode *value)
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

struct ListNode *removeZeroSumSublists(struct ListNode *head)
{
	struct ListNode dummy = {0, head};
	hash_init();
	int prefixsum = 0;
	for (struct ListNode *p = &dummy; p; p = p->next)
	{
		prefixsum += p->val;
		hash_set(prefixsum, p);
	}
	prefixsum = 0;
	for (struct ListNode *p = &dummy; p; p = p->next)
	{
		prefixsum += p->val;
		p->next = hash_get(prefixsum)->value->next;
	}
	return dummy.next;
}