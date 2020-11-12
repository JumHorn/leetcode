#include <climits>
using namespace std;

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
	bool isValidBST(TreeNode *root)
	{
		long preval = INT_MIN - 1L;
		return inorder(root, preval);
	}

	bool inorder(TreeNode *root, long &preval)
	{
		if (root == nullptr)
			return true;
		if (!inorder(root->left, preval))
			return false;
		if (root->val <= preval)
			return false;
		preval = root->val;
		if (!inorder(root->right, preval))
			return false;
		return true;
	}
};