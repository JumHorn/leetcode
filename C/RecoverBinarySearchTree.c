#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool inorder(struct TreeNode *root, struct TreeNode **pre)
{
	if (!root)
		return false;
	bool res = inorder(root->left, pre);
	if (res)
		return res;
	if (*pre && root->val < (*pre)->val)
		return true;
	*pre = root;
	return inorder(root->right, pre);
}

bool reverseInorder(struct TreeNode *root, struct TreeNode **pre)
{
	if (!root)
		return false;
	bool res = reverseInorder(root->right, pre);
	if (res)
		return res;
	if (*pre && root->val > (*pre)->val)
		return true;
	*pre = root;
	return reverseInorder(root->left, pre);
}

void recoverTree(struct TreeNode *root)
{
	struct TreeNode *left = 0, *right = 0;
	inorder(root, &left);
	reverseInorder(root, &right);
	int tmp = left->val;
	left->val = right->val;
	right->val = tmp;
}