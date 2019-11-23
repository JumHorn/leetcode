
#define max(a, b) (((a) > (b)) ? (a) : (b))
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int height(struct TreeNode* root)
{
	if (!root)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
{
	if (!root)
		return root;
	int left = height(root->left);
	int right = height(root->right);
	if (left == right)
		return root;
	if (left > right)
		return subtreeWithAllDeepest(root->left);
	else
		return subtreeWithAllDeepest(root->right);
}

