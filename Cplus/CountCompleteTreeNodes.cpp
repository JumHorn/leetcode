
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
	int countNodes(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int l = heght(root->left);
		int r = heght(root->right);
		return (r < l) ? (1 << r) + countNodes(root->left) : (1 << l) + countNodes(root->right);
	}

	int heght(TreeNode *root)
	{
		int res = 0;
		while (root != nullptr)
		{
			++res;
			root = root->left;
		}
		return res;
	}
};