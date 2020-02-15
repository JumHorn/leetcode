
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

bool dfs(struct TreeNode *root, int layer, int *height, bool *flag)
{
	if (!root)
	{
		if (layer == *height)
			return true;
		if (layer + 1 == *height)
		{
			if (*flag)
			{
				*flag = false;
				--*height;
				return true;
			}
		}
		return false;
	}
	if (layer > *height)
		return false;
	if (!dfs(root->left, layer + 1, height, flag))
		return false;
	return dfs(root->right, layer + 1, height, flag);
}

bool isCompleteTree(struct TreeNode *root)
{
	int height = getHeight(root);
	bool flag = true;
	return dfs(root, 0, &height, &flag);
}

