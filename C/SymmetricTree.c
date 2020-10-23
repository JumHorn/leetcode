#include <stdbool.h>

//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool doSymmetricCheck(struct TreeNode *left, struct TreeNode *right)
{
	if (left == right) //left==NULL && right== NULL
		return true;
	if (!left || !right)
		return false;
	if (left->val != right->val)
		return false;
	return doSymmetricCheck(left->left, right->right) && doSymmetricCheck(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
	if (!root)
		return true;
	return doSymmetricCheck(root->left, root->right);
}