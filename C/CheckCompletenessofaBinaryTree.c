#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int getHeight(struct TreeNode *root)
{
	if (!root)
		return 0;
	return getHeight(root->left) + 1;
}

bool preorder(struct TreeNode *root, int layer, int *height, bool *flag)
{
	if (!root)
	{
		if (layer == *height)
			return true;
		if (layer + 1 == *height && *flag)
		{
			*flag = false;
			--*height;
			return true;
		}
		return false;
	}
	if (layer > *height)
		return false;
	if (!preorder(root->left, layer + 1, height, flag))
		return false;
	return preorder(root->right, layer + 1, height, flag);
}

bool isCompleteTree(struct TreeNode *root)
{
	int height = getHeight(root);
	bool flag = true;
	return preorder(root, 0, &height, &flag);
}