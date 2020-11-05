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
		if (layer % 2 == root->val % 2)
			return false;
		if (layer >= (int)height.size())
			height.push_back(root->val);
		else
		{
			if ((layer % 2 == 0 && root->val <= height[layer]) ||
				(layer % 2 != 0 && root->val >= height[layer]))
				return false;
			height[layer] = root->val;
		}
		return preorder(root->left, layer + 1, height) &&
			   preorder(root->right, layer + 1, height);
	}
};