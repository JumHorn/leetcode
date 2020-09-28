
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
	int findBottomLeftValue(TreeNode *root)
	{
		int res = 0, depth = 0;
		preorder(root, 1, depth, res);
		return res;
	}

	void preorder(TreeNode *root, int layer, int &depth, int &value)
	{
		if (root == nullptr)
			return;
		if (layer > depth)
		{
			value = root->val;
			depth = layer;
		}
		preorder(root->left, layer + 1, depth, value);
		preorder(root->right, layer + 1, depth, value);
	}
};