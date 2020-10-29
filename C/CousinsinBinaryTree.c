#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct tuple
{
	int xparent;
	int xdepth;
	int yparent;
	int ydepth;
} tuple;

void preorder(struct TreeNode *root, int parent, int layer, int x, int y, tuple *data)
{
	if (!root)
		return;
	if (root->val == x)
	{
		data->xdepth = layer;
		data->xparent = parent;
	}
	else if (root->val == y)
	{
		data->ydepth = layer;
		data->yparent = parent;
	}
	preorder(root->left, root->val, layer + 1, x, y, data);
	preorder(root->right, root->val, layer + 1, x, y, data);
}

bool isCousins(struct TreeNode *root, int x, int y)
{
	tuple data = {0, 0, 1, 1}; //init different
	preorder(root, -1, 0, x, y, &data);
	return data.xdepth == data.ydepth && data.xparent != data.yparent;
}