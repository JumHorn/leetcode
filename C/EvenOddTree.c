#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool preorder(struct TreeNode *root, int layer, int *height, int *heightSize)
{
	if (!root)
		return true;
	if (layer % 2 == root->val % 2)
		return false;
	if (layer >= *heightSize)
		height[(*heightSize)++] = root->val;
	else
	{
		if ((layer % 2 == 0 && root->val <= height[layer]) ||
			(layer % 2 != 0 && root->val >= height[layer]))
			return false;
		height[layer] = root->val;
	}
	return preorder(root->left, layer + 1, height, heightSize) &&
		   preorder(root->right, layer + 1, height, heightSize);
}

bool isEvenOddTree(struct TreeNode *root)
{
	int height[100000], heightSize = 0;
	return preorder(root, 0, height, &heightSize);
}
