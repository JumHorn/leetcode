
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* sufficientSubset(struct TreeNode* root, int limit)
{
	if (root->left == root->right)  //root->left==NULL && root->right==NULL
		return root->val < limit ? 0 : root;
	if (root->left)
		root->left = sufficientSubset(root->left, limit - root->val);
	if (root->right)
		root->right = sufficientSubset(root->right, limit - root->val);
	return root->left == root->right ? 0 : root;
}
