#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define trimax(a, b, c) (max(max(a, b), c)) //the maximum of a,b,c
#define trimin(a, b, c) (min(min(a, b), c)) //the minimum of a,b,c

// all ready defined in stdlib.h
#define abs(x) (((x) < 0) ? (-(x)) : (x))

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))
// avoid the above macro same address bug using the following version
// void swap(int *lhs, int *rhs)
// {
// 	int tmp = *lhs;
// 	*lhs = *rhs;
// 	*rhs = tmp;
// }

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

// Bit Twidding Hacks
// Detect if two integers have opposite signs
// bool f = ((x ^ y) < 0);

//frequently used items
#include <stdlib.h>
#include <string.h>

//board dfs direction
int path[5] = {-1, 0, 1, 0, -1};

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

void reverse(int *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		int tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int combination(int n, int m)
{
	int res = 1;
	for (int i = 1; i <= m; ++i)
		res = res * (n - m + i) / i;
	return res;
}

//circle queue for monoqueue queue
/*
//front stores data and rear not
int size, deque[size], front = 0, rear = 0;
front = (front + 1) % size;			 //push front
front = (front - 1 + size) % size;   //pop front
rear = (rear - 1 + size) % size;	 //push back
rear = (rear + 1) % size;			 //pop back
qsize = (front - rear + size) % size; //size
(front + 1) % size == rear;			 //is full
front == rear;						 //is empty
*/
/********end of circle queue********/

//prefix tree
typedef struct Trie
{
	int count; //number of words end with this node
	struct Trie *nodes[26];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

void insert(Trie *root, char *str)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			root->nodes[index] = createNode();
		root = root->nodes[index];
	}
	++root->count;
}

Trie *searchNode(Trie *root, char *str)
{
	while (*str)
	{
		int index = *str++ - 'a';
		if (!root->nodes[index])
			return NULL;
		root = root->nodes[index];
	}
	return root;
}
/********end of prefix tree********/

//max heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(int *ptr, int size)
{
	if (size <= 0)
		return;
	int val = *ptr, non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1] > ptr[i])
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = ptr[size - 1];
	push_heap(ptr, hole + 1);
	ptr[size - 1] = val;
}

void make_heap(int *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

//divide and conquer
void merge(int *arr, int *dup, int first, int mid, int last)
{
	for (int i = first, j = mid, d = 0; i < mid || j < last;)
	{
		if (i == mid)
			dup[d++] = arr[j++];
		else if (j == last)
			dup[d++] = arr[i++];
		else
			dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
	}
	memcpy(arr + first, dup, sizeof(int) * (last - first));
}

void divide(int *arr, int *dup, int first, int last)
{
	if (last - first < 2)
		return;
	int mid = (last - first) / 2 + first;
	divide(arr, dup, first, mid);
	divide(arr, dup, mid, last);
	//to do
	merge(arr, dup, first, mid, last);
}
/********end of divide and conquer********/

// cross product
int crossProduct(int *pointA, int *pointB, int *pointC)
{
	int x1 = pointB[0] - pointA[0];
	int y1 = pointB[1] - pointA[1];
	int x2 = pointC[0] - pointA[0];
	int y2 = pointC[1] - pointA[1];
	return x1 * y2 - x2 * y1;
}
/********end of cross product********/

//kmp next array
void createKMP(char *pattern)
{
	int N = strlen(pattern);
	int next[N];
	next[0] = 0;
	for (int i = 1, j = 0; i < N; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		if (pattern[i] == pattern[j])
			++j;
		next[i] = j;
	}
}
/********end of kmp next array********/

// DSU
typedef struct DSU
{
	int *parent;
	int *rank;
} DSU;

DSU *dsu_init(int N)
{
	DSU *dsu = (DSU *)malloc(sizeof(DSU));
	dsu->parent = (int *)malloc(sizeof(int) * N);
	dsu->rank = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		dsu->parent[i] = i;
		dsu->rank[i] = 1;
	}
	return dsu;
}

void dsu_release(DSU *dsu)
{
	if (dsu)
	{
		if (dsu->parent)
			free(dsu->parent);
		if (dsu->rank)
			free(dsu->rank);
		free(dsu);
	}
}

int dsu_find(DSU *dsu, int x)
{
	if (x != dsu->parent[x])
		dsu->parent[x] = dsu_find(dsu, dsu->parent[x]);
	return dsu->parent[x];
}

bool dsu_union(DSU *dsu, int x, int y)
{
	int xr = dsu_find(dsu, x), yr = dsu_find(dsu, y);
	if (xr == yr)
		return false;
	dsu->parent[yr] = xr;
	dsu->rank[xr] += dsu->rank[yr];
	return true;
}
/********end of DSU********/

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

//Fenwick tree(BIT)
int sum(int *tree, int size, int index)
{
	int res = 0;
	for (++index; index > 0; index -= index & -index)
		res += tree[index];
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	for (++index; index < size; index += index & -index)
		tree[index] += delta;
}
/********end of Fenwick tree(BIT)********/

// create graph
typedef struct GraphNode
{
	int node;
	struct GraphNode *next;
} GraphNode;

GraphNode *createNode(int val)
{
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->node = val;
	node->next = NULL;
	return node;
}

void createGraph(int N, int **edges, int edgesSize)
{
	GraphNode *graph[N];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < edgesSize; ++i)
	{
		GraphNode *node = createNode(edges[i][1]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		node = createNode(edges[i][0]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
	}
}
/********end of create graph********/

//DynamicArray
typedef struct DynamicArray
{
	int *data;
	int size;
	int capacity;
} DynamicArray;

DynamicArray *arr_init()
{
	DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
	arr->size = 0;
	arr->capacity = 4;
	arr->data = (int *)malloc(sizeof(int) * arr->capacity);
	return arr;
}

void arr_append(DynamicArray *arr, int val)
{
	if (arr->size >= arr->capacity)
	{
		arr->capacity <<= 1;
		arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
	}
	arr->data[arr->size++] = val;
}
/********end of DynamicArray********/

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********end of malloc result********/