#include <stdlib.h>

// Definition for a binary tree node.
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

void inorder(struct TreeNode *root, int *data, int *dataSize)
{
	if (!root)
		return;
	inorder(root->left, data, dataSize);
	data[(*dataSize)++] = root->val;
	inorder(root->right, data, dataSize);
}

struct TreeNode *buildTree(int *data, int dataSize)
{
	if (dataSize == 0)
		return NULL;
	struct TreeNode *root = createNode(data[dataSize / 2]);
	root->left = buildTree(data, dataSize / 2);
	root->right = buildTree(data + dataSize / 2 + 1, dataSize - dataSize / 2 - 1);
	return root;
}

struct TreeNode *balanceBST(struct TreeNode *root)
{
	int data[10000], dataSize = 0;
	inorder(root, data, &dataSize);
	return buildTree(data, dataSize);
}