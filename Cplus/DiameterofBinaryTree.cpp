#include <algorithm>
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
	int diameterOfBinaryTree(TreeNode *root)
	{
		return postorder(root).first;
	}

	pair<int, int> postorder(TreeNode *root) //{diameter,height}
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left);
		auto r = postorder(root->right);
		return {max({l.first, r.first, l.second + r.second}), 1 + max(l.second, r.second)};
	}
};