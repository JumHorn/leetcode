
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, int layer, int *depth, int *value)
{
	if (!root)
		return;
	if (layer > *depth)
	{
		*value = root->val;
		*depth = layer;
	}
	preorder(root->left, layer + 1, depth, value);
	preorder(root->right, layer + 1, depth, value);
}

int findBottomLeftValue(struct TreeNode *root)
{
	int res = 0, depth = 0;
	preorder(root, 1, &depth, &res);
	return res;
}
