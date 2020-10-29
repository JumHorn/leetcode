
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void preorder(struct TreeNode *root, int val, int *res)
{
	if (!root)
		return;
	if (!root->left && !root->right)
		*res += (val << 1) | root->val;
	preorder(root->left, (val << 1) | root->val, res);
	preorder(root->right, (val << 1) | root->val, res);
}

int sumRootToLeaf(struct TreeNode *root)
{
	int res = 0;
	preorder(root, 0, &res);
	return res;
}