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
	TreeNode *lcaDeepestLeaves(TreeNode *root)
	{
		return postorder(root).second;
	}

	pair<int, TreeNode *> postorder(TreeNode *root)
	{
		if (root == nullptr)
			return {0, nullptr};
		auto l = postorder(root->left);
		auto r = postorder(root->right);
		pair<int, TreeNode *> res;
		res.first = max(l.first, r.first) + 1;
		if (l.first == r.first)
			res.second = root;
		else
			res.second = (l.first > r.first) ? l.second : r.second;
		return res;
	}
};