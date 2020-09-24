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
	int rob(TreeNode *root)
	{
		auto res = postorder(root);
		return max(res.first, res.second);
	}

	pair<int, int> postorder(TreeNode *root) //{rob,not rob}
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left);
		auto r = postorder(root->right);
		return {l.second + r.second + root->val, max(l.first, l.second) + max(r.first, r.second)};
	}
};