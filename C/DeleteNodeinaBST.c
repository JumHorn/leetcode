
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
	if (!root)
		return root;
	if (root->val == key)
	{
		if (!root->right)
			root = root->left;
		else
		{
			struct TreeNode* node = root->right;
			while (node->left)
				node = node->left;
			swap(root->val, node->val);
			root->right = deleteNode(root->right, key);
		}
	}
	else if (root->val > key)
		root->left = deleteNode(root->left, key);
	else
		root->right = deleteNode(root->right, key);
	return root;
}
