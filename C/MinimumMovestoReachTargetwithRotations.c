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
		if (head->key == key && head->value == value)
			return;
		head = head->next;
	}
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(int key, int value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key && head->value == value)
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

void tryMoveToPos(int x, int y, int (*queue)[2], int size, int *rear)
{
	HashNode *node = hash_get(x, y);
	if (!node)
	{
		hash_set(x, y);
		queue[*rear][0] = x;
		queue[*rear][1] = y;
		*rear = (*rear - 1 + size) % size; //push back
	}
}

int minimumMoves(int **grid, int gridSize, int *gridColSize)
{
	int N = gridSize, size = N * N, front = 0, rear = 0, queue[N * N][2]; //{head pos,tail pos}
	hash_init();
	queue[rear][0] = 0;
	queue[rear][1] = 1;
	rear = (rear - 1 + size) % size; //push back
	hash_set(0, 1);
	int res = -1;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int *at = queue[front];
			front = (front - 1 + size) % size; //pop front
			if (at[0] == N * (N - 1) + N - 2 && at[1] == N * (N - 1) + N - 1)
				return res;
			int tailrow = at[0] / N, tailcol = at[0] % N, headrow = at[1] / N, headcol = at[1] % N;
			if (tailrow == headrow)
			{
				//right
				if (headcol + 1 < N && grid[headrow][headcol + 1] == 0)
					tryMoveToPos(at[1], at[1] + 1, queue, size, &rear);
				//down
				if (headrow + 1 < N && grid[headrow + 1][headcol] == 0 && grid[tailrow + 1][tailcol] == 0)
				{
					tryMoveToPos(at[0] + N, at[1] + N, queue, size, &rear);
					//clockwise
					tryMoveToPos(at[0], at[0] + N, queue, size, &rear);
				}
			}
			else
			{
				//down
				if (headrow + 1 < N && grid[headrow + 1][headcol] == 0)
					tryMoveToPos(at[1], at[1] + N, queue, size, &rear);
				//right
				if (headcol + 1 < N && grid[headrow][headcol + 1] == 0 && grid[tailrow][tailcol + 1] == 0)
				{
					tryMoveToPos(at[0] + 1, at[1] + 1, queue, size, &rear);
					//counter-clockwise
					tryMoveToPos(at[0], at[0] + 1, queue, size, &rear);
				}
			}
		}
	}
	return -1;
}