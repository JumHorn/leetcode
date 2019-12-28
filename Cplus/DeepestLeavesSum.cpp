#include <vector>
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
	int deepestLeavesSum(TreeNode *root)
	{
		return preorder(root).first;
	}

	pair<int, int> preorder(TreeNode *root)
	{
		if (root == NULL)
			return {0, 0};
		auto left = preorder(root->left);
		auto right = preorder(root->right);
		if (left.second == 0 && right.second == 0)
			return {root->val, 1};
		if (left.second > right.second)
			return {left.first, left.second + 1};
		if (left.second < right.second)
			return {right.first, right.second + 1};
		return {left.first + right.first, left.second + 1};
	}
};
