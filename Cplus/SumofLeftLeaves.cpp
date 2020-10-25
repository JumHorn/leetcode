
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
	int sumOfLeftLeaves(TreeNode *root)
	{
		return postorder(root, false);
	}

	int postorder(TreeNode *root, bool flag)
	{
		if (root == nullptr)
			return 0;
		int l = postorder(root->left, true);
		int r = postorder(root->right, false);
		if (root->left == root->right)
			return flag ? root->val : 0;
		return l + r;
	}
};