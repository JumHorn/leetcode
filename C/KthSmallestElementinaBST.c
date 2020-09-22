
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int inorder(struct TreeNode *root, int *k)
{
	if (!root)
		return -1;
	int res = -1;
	res = inorder(root->left, k);
	if (res != -1)
		return res;
	if (--*k == 0)
		return root->val;
	return inorder(root->right, k);
}

int kthSmallest(struct TreeNode *root, int k)
{
	return inorder(root, &k);
}
