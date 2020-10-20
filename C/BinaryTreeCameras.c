#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int postOrder(struct TreeNode *root, int *res)
{
	if (!root)
		return 2;
	int left = postOrder(root->left, res);
	int right = postOrder(root->right, res);
	if (left == 0 || right == 0)
	{
		*res += 1;
		root->val = 1;
		return 1;
	}
	if (left == 1 || right == 1)
		return 2;
	return 0;
}

int minCameraCover(struct TreeNode *root)
{
	int res = 0;
	postOrder(root, &res);
	if (root && root->val == 0)
	{
		bool flag = true;
		if (root->left && root->left->val == 1)
			flag = false;
		if (root->right && root->right->val == 1)
			flag = false;
		if (flag)
			res += 1;
	}
	return res;
}