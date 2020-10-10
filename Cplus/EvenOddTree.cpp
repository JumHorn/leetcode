#include <vector>
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
	bool isEvenOddTree(TreeNode *root)
	{
		vector<int> height;
		return preorder(root, 0, height);
	}

	bool preorder(TreeNode *root, int layer, vector<int> &height)
	{
		if (root == nullptr)
			return true;
		if (layer >= (int)height.size())
		{
			if (layer % 2 == 0)
			{
				if (root->val % 2 == 0)
					return false;
			}
			else
			{
				if (root->val % 2 != 0)
					return false;
			}
			height.push_back(root->val);
		}
		else
		{
			if (layer % 2 == 0)
			{
				if (root->val <= height[layer] || root->val % 2 == 0)
					return false;
			}
			else
			{
				if (root->val >= height[layer] || root->val % 2 != 0)
					return false;
			}
			height[layer] = root->val;
		}
		if (!preorder(root->left, layer + 1, height))
			return false;
		if (!preorder(root->right, layer + 1, height))
			return false;
		return true;
	}
};