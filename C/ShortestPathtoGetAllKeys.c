#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	int key;
	char *value;
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

HashNode *hash_createNode(int key, char *value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void hash_set(int key, char *value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key && strcmp(head->value, value) == 0)
			return;
		head = head->next;
	}
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(int key, char *value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key && strcmp(head->value, value) == 0)
			break;
		head = head->next;
	}
	return head;
}

void hash_erase(int key, char *value)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode **head = &HashTable[bucket];
	while (*head)
	{
		if ((*head)->key == key && strcmp((*head)->value, value) == 0)
		{
			*head = (*head)->next;
			break;
		}
		head = &(*head)->next;
	}
}
/********end of HASH********/

void findStartAndTarget(char **grid, int gridSize, int *startx, int *starty, char *target)
{
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; grid[i][j]; ++j)
		{
			if (grid[i][j] == '@')
			{
				*startx = i;
				*starty = j;
			}
			else if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
				target[grid[i][j] - 'a'] = grid[i][j];
		}
	}
}

int shortestPathAllKeys(char **grid, int gridSize)
{
	hash_init();
	int M = gridSize, N = strlen(grid[0]);
	int size = 2000, front = 0, rear = 0;
	HashNode queue[size]; //{position,keys in hand}
	int res = -1, startx = 0, starty = 0;
	char target[] = "......";
	findStartAndTarget(grid, gridSize, &startx, &starty, target);
	queue[rear].key = startx * N + starty;
	queue[rear].value = strdup("......");
	hash_set(queue[rear].key, queue[rear].value);
	rear = (rear - 1 + size) % size; //push back

	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			HashNode *state = &queue[front];
			front = (front - 1 + size) % size; //pop front
			if (strcmp(state->value, target) == 0)
				return res;
			int x = state->key / N, y = state->key % N;
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx < 0 || dx >= M || dy < 0 || dy >= N || grid[dx][dy] == '#')
					continue;

				char str[10];
				strcpy(str, state->value);
				if (grid[dx][dy] >= 'A' && grid[dx][dy] <= 'F' && str[grid[dx][dy] - 'A'] == '.')
					continue;
				if (grid[dx][dy] >= 'a' && grid[dx][dy] <= 'f')
					str[grid[dx][dy] - 'a'] = grid[dx][dy];
				if (hash_get(dx * N + dy, str) != NULL)
					continue;
				queue[rear].key = dx * N + dy;
				queue[rear].value = strdup(str);
				hash_set(queue[rear].key, queue[rear].value);
				rear = (rear - 1 + size) % size; //push back
			}
		}
	}
	return -1;
}