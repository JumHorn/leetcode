#include <stdlib.h>
#include <string.h>

//Definition for a Node.
struct Node
{
	int val;
	int numNeighbors;
	struct Node** neighbors;
};

struct Node* createNode(int val)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * 101);
	memset(node->neighbors, 0, sizeof(struct Node*) * 101);
	node->numNeighbors = 0;
	node->val = val;
	return node;
}

void dfs(struct Node* s, struct Node* copy, struct Node** seen)
{
	if (!s)
		return;
	copy->numNeighbors = s->numNeighbors;
	for (int i = 0; i < s->numNeighbors; ++i)
	{
		int index = s->neighbors[i]->val;
		if (seen[index] == 0)
		{
			seen[index] = createNode(index);
			copy->neighbors[i] = seen[index];
			dfs(s->neighbors[i], copy->neighbors[i], seen);
		}
		else
			copy->neighbors[i] = seen[index];
	}
}

struct Node* cloneGraph(struct Node* s)
{
	if (!s)
		return NULL;
	struct Node* nodes[101];
	memset(nodes, 0, sizeof(nodes));
	struct Node* root = createNode(s->val);
	nodes[root->val] = root;
	dfs(s, root, nodes);
	return root;
}
