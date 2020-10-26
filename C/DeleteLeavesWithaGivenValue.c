
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
	if (!root)
		return root;
	root->left = removeLeafNodes(root->left, target);
	root->right = removeLeafNodes(root->right, target);
	if (!root->left && !root->right && root->val == target)
		return 0;
	return root;
}
