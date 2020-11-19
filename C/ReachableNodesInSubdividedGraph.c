#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// create graph
typedef struct GraphNode
{
	int node;
	int weight;
	struct GraphNode *next;
} GraphNode;

GraphNode *createNode(int val, int weight)
{
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->node = val;
	node->weight = weight;
	node->next = NULL;
	return node;
}

//max heap function series
void push_heap(GraphNode *ptr, int size)
{
	if (size <= 1)
		return;
	GraphNode val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.weight > ptr[i].weight; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(GraphNode *ptr, int size)
{
	if (size <= 0)
		return;
	GraphNode val = *ptr;
	int non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1].weight > ptr[i].weight)
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

void make_heap(GraphNode *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

int reachableNodes(int **edges, int edgesSize, int *edgesColSize, int M, int N)
{
	GraphNode *graph[N];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < edgesSize; ++i)
	{
		GraphNode *node = createNode(edges[i][1], edges[i][2]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		node = createNode(edges[i][0], edges[i][2]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
	}

	int dist[N][N], seen[N];
	memset(dist, 0, sizeof(dist));
	memset(seen, -1, sizeof(seen));

	int res = 0, heapSize = 0;
	//dijkstra
	GraphNode heap[10000]; //{weight,node}
	heap[heapSize].weight = M;
	heap[heapSize].node = 0;
	push_heap(heap, ++heapSize);
	while (heapSize > 0)
	{
		int weight = heap[0].weight;
		int node = heap[0].node;
		pop_heap(heap, heapSize--);
		if (weight <= seen[node])
			continue;
		seen[node] = weight;
		++res;
		for (GraphNode *to = graph[node]; to; to = to->next)
		{
			if (weight > to->weight)
			{
				dist[node][to->node] = to->weight;
				if (weight - to->weight - 1 > seen[to->node])
				{
					heap[heapSize].weight = weight - to->weight - 1;
					heap[heapSize].node = to->node;
					push_heap(heap, ++heapSize);
				}
			}
			else
				dist[node][to->node] = max(dist[node][to->node], weight);
		}
	}

	for (int k = 0; k < edgesSize; ++k)
	{
		int i = edges[k][0], j = edges[k][1], w = edges[k][2];
		res += min(w, dist[i][j] + dist[j][i]);
	}
	return res;
}