#include <cmath>

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
	int distributeCoins(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = distributeCoins(root->left);
		int right = distributeCoins(root->right);
		--root->val;
		if (root->left)
			root->val += root->left->val;
		if (root->right)
			root->val += root->right->val;
		return left + right + abs(root->val);
	}
};