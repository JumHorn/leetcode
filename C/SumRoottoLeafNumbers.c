
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumNumbers(struct TreeNode *root)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return root->val;
	int res = 0;
	if (root->left)
	{
		root->left->val += root->val * 10;
		res += sumNumbers(root->left);
	}
	if (root->right)
	{
		root->right->val += root->val * 10;
		res += sumNumbers(root->right);
	}
	return res;
}
