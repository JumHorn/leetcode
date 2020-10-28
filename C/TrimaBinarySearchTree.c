
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* trimBST(struct TreeNode* root, int low, int high)
{
	if (!root)
		return root;
	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);
	if (root->val < low)
		return root->right;
	if (root->val > high)
		return root->left;
	return root;
}
