#include <limits.h>

//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (!root)
		return 0;
	if (root->left == root->right)
		return 1;
	int l = minDepth(root->left);
	int r = minDepth(root->right);
	if (l == 0)
		return r + 1;
	if (r == 0)
		return l + 1;
	return 1 + (l < r ? l : r);
}