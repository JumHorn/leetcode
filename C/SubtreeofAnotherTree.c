#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool equalTree(struct TreeNode* s, struct TreeNode* t)
{
	if (!s && !t)
		return true;
	if (!s || !t)
		return false;
	return s->val == t->val && equalTree(s->left, t->left) && equalTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (!s)
		return !t;
	if (equalTree(s, t))
		return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
