#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

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

bool hash_set(int key, int value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key && head->value == value)
			return false;
		head = head->next;
	}
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
	return true;
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

void hash_erase(int key, int value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode **head = &HashTable[bucket];
	while (*head)
	{
		if ((*head)->key == key && (*head)->value == value)
		{
			*head = (*head)->next;
			break;
		}
		head = &(*head)->next;
	}
}
/********end of HASH********/

bool isRectangleCover(int **rectangles, int rectanglesSize, int *rectanglesColSize)
{
	int bottom = INT_MAX, left = INT_MAX, top = INT_MIN, right = INT_MIN, area = 0, size = 0;
	hash_init();
	for (int i = 0; i < rectanglesSize; ++i)
	{
		bottom = min(rectangles[i][0], bottom);
		left = min(rectangles[i][1], left);
		top = max(rectangles[i][2], top);
		right = max(rectangles[i][3], right);
		area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);

		if (!hash_set(rectangles[i][0], rectangles[i][1]))
		{
			hash_erase(rectangles[i][0], rectangles[i][1]);
			--size;
		}
		else
			++size;
		if (!hash_set(rectangles[i][0], rectangles[i][3]))
		{
			hash_erase(rectangles[i][0], rectangles[i][3]);
			--size;
		}
		else
			++size;
		if (!hash_set(rectangles[i][2], rectangles[i][1]))
		{
			hash_erase(rectangles[i][2], rectangles[i][1]);
			--size;
		}
		else
			++size;
		if (!hash_set(rectangles[i][2], rectangles[i][3]))
		{
			hash_erase(rectangles[i][2], rectangles[i][3]);
			--size;
		}
		else
			++size;
	}
	if (size != 4 ||
		hash_set(bottom, left) ||
		hash_set(bottom, right) ||
		hash_set(top, left) ||
		hash_set(top, right))
		return false;
	return area == (top - bottom) * (right - left);
}