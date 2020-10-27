
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

void preorder(struct TreeNode *root, int *sum, long *res)
{
	if (!root)
		return;
	*res = max(*res, (long)root->val * (*sum - root->val));
	preorder(root->left, sum, res);
	preorder(root->right, sum, res);
}

int postorder(struct TreeNode *root)
{
	if (!root)
		return 0;
	int left = postorder(root->left);
	int right = postorder(root->right);
	root->val += left + right;
	return root->val;
}

int maxProduct(struct TreeNode *root)
{
	static const int MOD = 1e9 + 7;
	if (!root)
		return 0;
	long sum = postorder(root), res = 0;
	preorder(root, &sum, &res);
	return res % MOD;
}
