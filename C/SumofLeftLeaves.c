
//definition for a binary tree node
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode *root)
{
	if (!root)
		return 0;
	int res = 0;
	if (root->left && root->left->left == root->left->right)
		res += root->left->val;
	res += sumOfLeftLeaves(root->left);
	res += sumOfLeftLeaves(root->right);
	return res;
}