#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAXNODE 500

struct TreeNode *createNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

/** Encodes a tree to a single string. */
char *serialize(struct TreeNode *root)
{
	struct TreeNode *stack[MAXNODE];
	int top = -1, size = 0;
	if (!root)
		return NULL;
	char *res = (char *)malloc(sizeof(char) * 100000);
	stack[++top] = root;
	while (top != -1)
	{
		struct TreeNode *node = stack[top--];
		if (!node) //NULL
			size += sprintf(&res[size], "N,");
		else
		{
			size += sprintf(&res[size], "%d,", node->val);
			stack[++top] = node->right;
			stack[++top] = node->left;
		}
	}
	return res;
}

struct TreeNode *doDeserialize(char **data)
{
	if (!*data || (*data)[0] == 'N')
	{
		*data += 2;
		return NULL;
	}
	int val;
	sscanf(*data, "%d", &val);
	while (**data != ',')
		++*data;
	++*data;
	struct TreeNode *root = createNode(val);
	root->left = doDeserialize(data);
	root->right = doDeserialize(data);
	return root;
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data)
{
	return doDeserialize(&data);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);