#include <algorithm>
#include <cmath>
#include <string>
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
	vector<vector<string>> printTree(TreeNode *root)
	{
		int layer = getTreeHeight(root);
		int len = pow(2, layer) - 1;
		vector<vector<string>> res(layer, vector<string>(len));
		preorder(root, 0, len, 0, res);
		return res;
	}

	void preorder(TreeNode *root, int left, int right, int height, vector<vector<string>> &res)
	{
		if (root == nullptr)
			return;
		int mid = (right - left) / 2 + left;
		res[height][mid] = to_string(root->val);
		preorder(root->left, left, mid, height + 1, res);
		preorder(root->right, mid, right, height + 1, res);
	}

	int getTreeHeight(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
	}
};