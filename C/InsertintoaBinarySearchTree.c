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

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
	if (root == NULL)
		return createNode(val);
	if (root->val > val)
		root->left = insertIntoBST(root->left, val);
	else
		root->right = insertIntoBST(root->right, val);
	return root;
}