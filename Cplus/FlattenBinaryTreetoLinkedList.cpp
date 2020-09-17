
//Definition for a binary tree node.
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
	void flatten(TreeNode *root)
	{
		TreeNode dummy, *d = &dummy;
		return preorder(root, d);
	}

	void preorder(TreeNode *root, TreeNode *&pre)
	{
		if (root == nullptr)
			return;
		TreeNode *left = root->left, *right = root->right;
		root->left = nullptr;
		pre->right = root;
		pre = root;
		preorder(left, pre);
		preorder(right, pre);
	}
};