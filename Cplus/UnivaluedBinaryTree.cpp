
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isUnivalTree(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return preorder(root, root->val);
	}

	bool preorder(TreeNode *root, int val)
	{
		if (root == nullptr)
			return true;
		return root->val == val && preorder(root->left, val) && preorder(root->right, val);
	}
};