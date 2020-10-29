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
	int longestUnivaluePath(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	pair<int, int> postorder(TreeNode *root, int &longestpath) //{value,length}
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left, longestpath);
		auto r = postorder(root->right, longestpath);
		pair<int, int> res;
		res.first = root->val;
		res.second = 1 + max(root->val == l.first ? l.second : 0, root->val == r.first ? r.second : 0);
		longestpath = max(longestpath, (root->val == l.first ? l.second : 0) + (root->val == r.first ? r.second : 0));
		return res;
	}
};