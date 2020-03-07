#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int maxSumBST(TreeNode* root)
	{
	}

	bool isBST(TreeNode* root)
	{
	}

	int sum(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return root->val + sum(root->left) + sum(root->right);
	}
};
