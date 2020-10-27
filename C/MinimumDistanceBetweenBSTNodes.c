#include <limits.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define min(a, b) (((a) < (b)) ? (a) : (b))

void inorder(struct TreeNode *root, long *pre, long *res)
{
	if (!root)
		return;
	inorder(root->left, pre, res);
	*res = min(*res, root->val - *pre);
	*pre = root->val;
	inorder(root->right, pre, res);
}

int minDiffInBST(struct TreeNode *root)
{
	long res = INT_MAX, pre = INT_MIN;
	inorder(root, &pre, &res);
	return res;
}