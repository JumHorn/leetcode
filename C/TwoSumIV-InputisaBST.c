#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool binarySearch(struct TreeNode *root, struct TreeNode *cur, int val)
{
	if (!root)
		return false;
	return ((root->val == val) && (root != cur)) ||
		   ((root->val < val) && binarySearch(root->right, cur, val)) ||
		   ((root->val > val) && binarySearch(root->left, cur, val));
}

bool preorder(struct TreeNode *root, struct TreeNode *cur, int k)
{
	if (!cur)
		return false;
	return binarySearch(root, cur, k - cur->val) ||
		   preorder(root, cur->left, k) ||
		   preorder(root, cur->right, k);
}

bool findTarget(struct TreeNode *root, int k)
{
	return preorder(root, root, k);
}
