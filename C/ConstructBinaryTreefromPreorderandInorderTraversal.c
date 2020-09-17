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

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (preorderSize == 0)
		return NULL;
	struct TreeNode *root = createNode(*preorder);
	if (preorderSize == 1)
		return root;
	int mi;
	for (mi = 0; mi < inorderSize; ++mi)
	{
		if (inorder[mi] == *preorder)
			break;
	}
	root->left = buildTree(preorder + 1, mi, inorder, mi);
	root->right = buildTree(preorder + 1 + mi, preorderSize - mi - 1, inorder + mi + 1, inorderSize - mi - 1);
	return root;
}