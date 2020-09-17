#include <limits.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool preorder(struct TreeNode *root, long minval, long maxval)
{
	if (!root)
		return true;
	if (root->val <= minval || root->val >= maxval)
		return false;
	return preorder(root->left, minval, root->val) && preorder(root->right, root->val, maxval);
}

bool isValidBST(struct TreeNode *root)
{
	return preorder(root, INT_MIN - 1L, INT_MAX + 1L);
}
