#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
	if (preorderSize == 0)
		return NULL;
	struct TreeNode *root = createNode(*preorder);
	int i;
	for (i = 1; i < preorderSize; ++i)
	{
		if (preorder[0] < preorder[i])
			break;
	}
	root->left = bstFromPreorder(preorder + 1, i - 1);
	root->right = bstFromPreorder(preorder + i, preorderSize - i);
	return root;
}