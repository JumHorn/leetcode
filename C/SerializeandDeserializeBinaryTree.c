#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX_LENGTH 100000
#define STACK_SIZE 1000
char data[MAX_LENGTH];
struct TreeNode *stack[STACK_SIZE];

struct TreeNode *createTreeNode()
{
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	memset(root, 0, sizeof(struct TreeNode));
	return root;
}

/** Encodes a tree to a single string. */
char *serialize(struct TreeNode *root)
{
	int top = 0;
	stack[0] = root;
	char *p = data;
	while (top != -1)
	{
		struct TreeNode *node = stack[top--];
		if (node)
		{
			sprintf(p, ",%d", node->val);
			p += strlen(p);
			stack[++top] = node->right;
			stack[++top] = node->left;
		}
		else
		{
			sprintf(p, ",n");
			p += 2;
		}
	}
	return &data[1];
}

struct TreeNode *dodeserialize(char **data)
{
	char *p = *data;
	if (*p == 'n')
	{
		++p;
		if (*p == ',')
			++p;
		*data = p;
		return NULL;
	}
	while (*p != ',')
		++p;
	*p = '\0';
	struct TreeNode *root = createTreeNode();
	root->val = atoi(*data);
	*data = p + 1;
	root->left = dodeserialize(data);
	root->right = dodeserialize(data);
	return root;
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data)
{
	return dodeserialize(&data);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);