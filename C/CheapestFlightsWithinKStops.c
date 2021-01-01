#include <stdlib.h>

// create graph
typedef struct GraphNode
{
	int val;
	int node;
	struct GraphNode *next;
} GraphNode;

GraphNode *createNode(int n, int val)
{
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->node = n;
	node->val = val;
	node->next = NULL;
	return node;
}
/********end of create graph********/

//min heap function series
typedef struct tuple
{
	int price;
	int pos;
	int stops;
} tuple;

void push_heap(tuple *ptr, int size)
{
	if (size <= 1)
		return;
	tuple val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.price < ptr[i].price; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(tuple *ptr, int size)
{
	if (size <= 0)
		return;
	tuple val = *ptr;
	int non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1].price < ptr[i].price)
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

void make_heap(tuple *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of min heap********/

int findCheapestPrice(int n, int **flights, int flightsSize, int *flightsColSize, int src, int dst, int K)
{
	GraphNode *graph[n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < flightsSize; ++i)
	{
		GraphNode *node = createNode(flights[i][1], flights[i][2]);
		node->next = graph[flights[i][0]];
		graph[flights[i][0]] = node;
	}
	tuple heap[50000];
	int heapSize = 1;
	heap[0].price = 0;
	heap[0].pos = src;
	heap[0].stops = K + 1;
	while (heapSize != 0)
	{
		int price = heap[0].price, pos = heap[0].pos, stops = heap[0].stops;
		pop_heap(heap, heapSize--);
		if (pos == dst)
			return price;
		if (stops == 0)
			continue;
		for (GraphNode *node = graph[pos]; node; node = node->next)
		{
			heap[heapSize].price = price + node->val;
			heap[heapSize].pos = node->node;
			heap[heapSize].stops = stops - 1;
			push_heap(heap, ++heapSize);
		}
	}
	return -1;
}