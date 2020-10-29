
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
	int sumRootToLeaf(TreeNode *root)
	{
		int res = 0;
		preorder(root, 0, res);
		return res;
	}

	void preorder(TreeNode *root, int val, int &res)
	{
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr)
			res += (val << 1) | root->val;
		preorder(root->left, (val << 1) | root->val, res);
		preorder(root->right, (val << 1) | root->val, res);
	}
};