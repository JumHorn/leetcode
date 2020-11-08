#include <limits.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

int postorder(struct TreeNode *root, int *res)
{
	if (!root)
		return INT_MIN / 5; //a minimal val less than all the node val
	int left = postorder(root->left, res);
	left = max(left, 0);
	int right = postorder(root->right, res);
	right = max(right, 0);
	*res = max(*res, root->val + left + right);
	return root->val + max(left, right);
}

int maxPathSum(struct TreeNode *root)
{
	int res = INT_MIN;
	postorder(root, &res);
	return res;
}