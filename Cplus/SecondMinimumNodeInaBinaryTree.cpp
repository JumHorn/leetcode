#include <climits>

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
	int findSecondMinimumValue(TreeNode *root)
	{
		long first = root->val, second = INT_MAX + 1u;
		preorder(root, first, second);
		return second > INT_MAX ? -1 : second;
	}

	void preorder(TreeNode *root, long &first, long &second)
	{
		if (root == nullptr || root->val >= second)
			return;
		if (root->val > first)
			second = root->val;
		preorder(root->left, first, second);
		preorder(root->right, first, second);
	}
};