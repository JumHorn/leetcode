
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int preorder(struct TreeNode *root, int mask)
{
	if (!root)
		return 0;
	mask ^= 1 << root->val;
	if (!root->left && !root->right)
		return bitCount(mask) < 2 ? 1 : 0;
	int res = 0;
	res += preorder(root->left, mask);
	res += preorder(root->right, mask);
	return res;
}

int pseudoPalindromicPaths(struct TreeNode *root)
{
	return preorder(root, 0);
}
