#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// all ready defined in math.h
#define abs(x) (((x) < 0) ? (-(x)) : (x))

// linux kernel swap version
// #define swap(a, b) \
// 	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define trimax(a, b, c) (max(max(a, b), c)) //the maximum of a,b,c
#define trimin(a, b, c) (min(min(a, b), c)) //the minimum of a,b,c

//frequently used items
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

//board dfs direction
int path[5] = {-1, 0, 1, 0, -1};

//circle queue for monoqueue queue
/*
//front stores data and rear not
int size, deque[size], front = 0, rear = 0;
front = (front + 1) % size;			 //push front
front = (front - 1 + size) % size;   //pop front
rear = (rear - 1 + size) % size;	 //push back
rear = (rear + 1) % size;			 //pop back
size = (front - rear + size) % size; //size
(front + 1) % size == rear;			 //is full
front == rear;						 //is empty
*/
/********end of circle queue********/

//prefix tree
typedef struct Trie
{
	int val;
	struct Trie *node[26];
} Trie;

Trie *createNode(int val)
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	node->val = val;
	return node;
}

void insert(Trie *root, char *s)
{
	while (*s)
	{
		int index = *s - 'a';
		if (!root->node[index])
			root->node[index] = createNode(0);
		root = root->node[index];
		++s;
	}
	root->val = 1;
}
/********end of prefix tree********/

//max heap function series
void push_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = ptr[size - 1], hole = size - 1;
		for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
		{
			ptr[hole] = ptr[i];
			hole = i;
		}
		ptr[hole] = val;
	}
}

//for internal usage
void _adjust_heap(int *ptr, int size, int hole, int val)
{
	int non_leaf = (size - 1) >> 1, i = hole;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i] < ptr[i - 1])
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = val;
	push_heap(ptr, hole + 1);
}

void make_heap(int *ptr, int size)
{
	for (int hole = (size - 1) >> 1; hole >= 0; --hole)
		_adjust_heap(ptr, size, hole, ptr[hole]);
}

void pop_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = *ptr;
		_adjust_heap(ptr, size, 0, ptr[size - 1]);
		ptr[size - 1] = val;
	}
}
/********end of max heap********/

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
	for (int i = 0; i < N; i++)
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

//Fenwick tree(BIT)
int sum(int *tree, int size, int index)
{
	int res = 0;
	while (index > 0)
	{
		res += tree[index];
		index -= index & -index;
	}
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	while (index < size)
	{
		tree[index] += delta;
		index += index & -index;
	}
}
/********end of Fenwick tree(BIT)********/

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
/********malloc result********/