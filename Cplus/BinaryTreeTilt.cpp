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
	int findTilt(TreeNode *root)
	{
		return postorder(root).first;
	}

	pair<int, int> postorder(TreeNode *root) //{res,sum of all node}
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left);
		auto r = postorder(root->right);
		return {l.first + r.first + abs(l.second - r.second), l.second + r.second + root->val};
	}
};