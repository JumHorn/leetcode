
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
	int sumNumbers(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return preorder(root, 0);
	}

	int preorder(TreeNode *root, int sum)
	{
		if (root->left == nullptr && root->right == nullptr)
			return sum * 10 + root->val;
		int res = 0;
		if (root->left != nullptr)
			res += preorder(root->left, sum * 10 + root->val);
		if (root->right != nullptr)
			res += preorder(root->right, sum * 10 + root->val);
		return res;
	}
};