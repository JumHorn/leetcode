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
	struct TreeNode *stack[1000];
	char data[100000];
	stack[0] = root;
	int top = 0, dataSize = 0;
	//preorder
	while (top != -1)
	{
		struct TreeNode *node = stack[top--];
		if (node)
		{
			dataSize += sprintf(&data[dataSize], ",%d", node->val);
			stack[++top] = node->right;
			stack[++top] = node->left;
		}
		else
			dataSize += sprintf(&data[dataSize], ",n");
	}
	return strdup(&data[1]);
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data)
{
	struct TreeNode **stack[1000];
	if (!data || data[0] == 'n')
		return NULL;
	struct TreeNode *res = NULL;
	stack[0] = &res;
	int top = 0;
	for (char *token = strtok(data, ","); token; token = strtok(NULL, ","))
	{
		if (token[0] == 'n')
			--top;
		else
		{
			struct TreeNode *node = createNode(atoi(token));
			*stack[top--] = node;
			stack[++top] = &node->right;
			stack[++top] = &node->left;
		}
	}
	return res;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);