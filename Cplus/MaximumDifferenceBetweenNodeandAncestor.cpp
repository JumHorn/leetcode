#include <algorithm>
#include <climits>
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
	int maxAncestorDiff(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	pair<int, int> postorder(struct TreeNode *root, int &diff)
	{
		if (root == nullptr)
			return {INT_MIN, INT_MAX};
		auto l = postorder(root->left, diff);
		auto r = postorder(root->right, diff);
		pair<int, int> res = {max(l.first, r.first), min(l.second, r.second)};
		if (res.first >= res.second)
			diff = max(diff, abs(res.first - root->val));
		if (res.first >= res.second)
			diff = max(diff, abs(res.second - root->val));
		res.first = max(res.first, root->val);
		res.second = min(res.second, root->val);
		return res;
	}
};