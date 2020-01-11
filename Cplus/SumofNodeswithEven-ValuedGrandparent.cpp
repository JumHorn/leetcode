#include <iostream>
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int sumEvenGrandparent(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	void postorder(TreeNode *root, int &res)
	{
		if (root == NULL)
			return;
		postorder(root->left, res);
		postorder(root->right, res);
		if (root->val % 2 == 0)
			res += sumGrandparent(root);
	}

	int sumGrandparent(TreeNode *root)
	{
		int res = 0;
		if (root->left != NULL)
			res += sumNode(root->left);
		if (root->right != NULL)
			res += sumNode(root->right);
		return res;
	}

	int sumNode(TreeNode *root)
	{
		int res = 0;
		if (root->left != NULL)
		{
			res += root->left->val;
			root->left->val = 0;
		}
		if (root->right != NULL)
		{
			res += root->right->val;
			root->right->val = 0;
		}
		return res;
	}
};
