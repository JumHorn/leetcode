#include <algorithm>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	string smallestFromLeaf(TreeNode *root)
	{
		auto res = postorder(root);
		return res.first;
	}

	pair<string, int> postorder(TreeNode *root)
	{
		if (root == NULL)
			return {"", -1};
		auto left = postorder(root->left);
		auto right = postorder(root->right);
		if (left.first.empty())
			return {right.first + char('a' + root->val), -1};
		if (right.first.empty())
			return {left.first + char('a' + root->val), -1};
	}
};
