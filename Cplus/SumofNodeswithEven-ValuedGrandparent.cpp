
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
	int sumEvenGrandparent(TreeNode *root)
	{
		int res = 0;
		preorder(root, res);
		return res;
	}

	void preorder(TreeNode *root, int &res)
	{
		if (root == nullptr)
			return;
		if (root->val % 2 == 0)
			res += nodeSum(root->left) + nodeSum(root->right);
		preorder(root->left, res);
		preorder(root->right, res);
	}

	int nodeSum(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int res = 0;
		if (root->left != nullptr)
			res += root->left->val;
		if (root->right != nullptr)
			res += root->right->val;
		return res;
	}
};