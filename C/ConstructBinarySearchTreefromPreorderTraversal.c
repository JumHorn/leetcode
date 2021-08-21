#include <limits.h>
#include <stdlib.h>

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

struct TreeNode *preOrder(int *data, int dataSize, int *index, int rootval)
{
	if (*index >= dataSize || data[*index] > rootval)
		return NULL;
	struct TreeNode *root = createNode(data[(*index)++]);
	root->left = preOrder(data, dataSize, index, root->val);
	root->right = preOrder(data, dataSize, index, rootval);
	return root;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
	int index = 0;
	return preOrder(preorder, preorderSize, &index, INT_MAX);
}