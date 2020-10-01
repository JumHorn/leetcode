
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
	TreeNode *addOneRow(TreeNode *root, int v, int d)
	{
		if (d == 1 && root != nullptr)
		{
			TreeNode *res = new TreeNode(v);
			res->left = root;
			return res;
		}
		return preorder(root, nullptr, v, d);
	}

	TreeNode *preorder(TreeNode *root, TreeNode *parent, int v, int d)
	{
		if (d == 1)
		{
			TreeNode *res = new TreeNode(v);
			if (parent->left == root)
				res->left = root;
			else
				res->right = root;
			return res;
		}
		if (root == nullptr)
			return nullptr;
		root->left = preorder(root->left, root, v, d - 1);
		root->right = preorder(root->right, root, v, d - 1);
		return root;
	}
};