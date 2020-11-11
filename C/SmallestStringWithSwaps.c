#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

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

void dfs(GraphNode **graph, int *seen, int at, int *arr, int *arrSize)
{
	seen[at] = 1;
	arr[(*arrSize)++] = at;
	for (GraphNode *to = graph[at]; to; to = to->next)
	{
		if (seen[to->node] == 0)
			dfs(graph, seen, to->node, arr, arrSize);
	}
}

char *smallestStringWithSwaps(char *s, int **pairs, int pairsSize, int *pairsColSize)
{
	int N = strlen(s);
	GraphNode *graph[N];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < pairsSize; ++i)
	{
		GraphNode *node = createNode(pairs[i][1]);
		node->next = graph[pairs[i][0]];
		graph[pairs[i][0]] = node;
		node = createNode(pairs[i][0]);
		node->next = graph[pairs[i][1]];
		graph[pairs[i][1]] = node;
	}
	int seen[N];
	memset(seen, 0, sizeof(seen));
	int index[N], indexSize = 0; //{char,index}
	for (int i = 0; i < N; ++i)
	{
		indexSize = 0;
		if (seen[i] == 0)
		{
			dfs(graph, seen, i, index, &indexSize);
			int count[26] = {0};
			for (int j = 0; j < indexSize; ++j)
				++count[s[index[j]] - 'a'];
			qsort(index, indexSize, sizeof(int), cmp);
			for (int j = 0, c = 0; j < indexSize; ++j)
			{
				while (count[c] == 0)
					++c;
				--count[c];
				s[index[j]] = c + 'a';
			}
		}
	}
	return s;
}