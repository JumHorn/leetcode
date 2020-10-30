
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
	TreeNode *increasingBST(TreeNode *root)
	{
		TreeNode dummy, *d = &dummy;
		inorder(root, &d);
		return dummy.right;
	}

	void inorder(TreeNode *root, struct TreeNode **pre)
	{
		if (root == nullptr)
			return;
		inorder(root->left, pre);
		(*pre)->right = root;
		*pre = root;
		(*pre)->left = nullptr;
		inorder(root->right, pre);
	}
};