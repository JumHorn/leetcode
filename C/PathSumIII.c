
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int preorder(struct TreeNode *root, int sum)
{
	if (!root)
		return 0;
	int res = (root->val == sum ? 1 : 0);
	res += preorder(root->left, sum - root->val);
	res += preorder(root->right, sum - root->val);
	return res;
}

int pathSum(struct TreeNode *root, int sum)
{
	if (!root)
		return 0;
	int res = preorder(root, sum);
	res += pathSum(root->left, sum);
	res += pathSum(root->right, sum);
	return res;
}
