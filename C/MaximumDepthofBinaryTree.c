
//definition for a binary tree
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
	if (!root)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return 1 + (l < r ? r : l);
}