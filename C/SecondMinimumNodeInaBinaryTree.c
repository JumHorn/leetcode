#include <limits.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, long *first, long *second)
{
	if (!root || root->val >= *second)
		return;
	if (root->val > *first)
		*second = root->val;
	preorder(root->left, first, second);
	preorder(root->right, first, second);
}

int findSecondMinimumValue(struct TreeNode *root)
{
	long first = root->val, second = INT_MAX + 1u;
	preorder(root, &first, &second);
	return second > INT_MAX ? -1 : second;
}
