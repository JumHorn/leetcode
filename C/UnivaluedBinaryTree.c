#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool preorder(struct TreeNode *root, int val)
{
	if (!root)
		return true;
	return root->val == val && preorder(root->left, val) && preorder(root->right, val);
}

bool isUnivalTree(struct TreeNode *root)
{
	if (!root)
		return true;
	return preorder(root, root->val);
}