#include <algorithm>
#include <cmath>
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
	bool isBalanced(TreeNode *root)
	{
		return postorder(root).first;
	}

	pair<bool, int> postorder(TreeNode *root)
	{
		if (root == nullptr)
			return {true, 0};
		auto l = postorder(root->left);
		if (!l.first)
			return l;
		auto r = postorder(root->right);
		if (!r.first)
			return r;
		if (abs(l.second - r.second) > 1)
			return {false, 0};
		return {true, max(l.second, r.second) + 1};
	}
};