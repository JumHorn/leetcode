#include <limits.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int preorder(struct TreeNode *root, int maxval)
{
	if (!root)
		return 0;
	int res = 0;
	if (root->val >= maxval)
	{
		res = 1;
		maxval = root->val;
	}
	res += preorder(root->left, maxval);
	res += preorder(root->right, maxval);
	return res;
}

int goodNodes(struct TreeNode *root)
{
	return preorder(root, INT_MIN);
}
