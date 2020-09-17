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

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
	if (postorderSize == 0)
		return NULL;
	struct TreeNode *root = createNode(postorder[postorderSize - 1]);
	if (postorderSize == 1)
		return root;
	int mi;
	for (mi = 0; mi < inorderSize; ++mi)
	{
		if (postorder[postorderSize - 1] == inorder[mi])
			break;
	}
	root->left = buildTree(inorder, mi, postorder, mi);
	root->right = buildTree(inorder + mi + 1, inorderSize - mi - 1, postorder + mi, postorderSize - mi - 1);
	return root;
}