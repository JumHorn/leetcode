#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int val)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

struct TreeNode* addOneRow(struct TreeNode* root, int v, int d)
{
	if (d <= 1)
	{
		struct TreeNode* res = createNode(v);
		if (d == 1)
			res->left = root;
		else
			res->right = root;
		return res;
	}
	if (!root)
		return root;
	root->left = addOneRow(root->left, v, d - 1);
	root->right = addOneRow(root->right, v, d == 2 ? 0 : d - 1);
	return root;
}
