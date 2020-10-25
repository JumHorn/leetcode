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
	int deepestLeavesSum(TreeNode *root)
	{
		return postorder(root).first;
	}

	pair<int, int> postorder(TreeNode *root)
	{
		if (root == nullptr)
			return {0, 0};
		auto left = postorder(root->left);
		auto right = postorder(root->right);
		if (left.second == 0 && right.second == 0)
			return {root->val, 1};
		if (left.second > right.second)
			return {left.first, left.second + 1};
		if (left.second < right.second)
			return {right.first, right.second + 1};
		return {left.first + right.first, left.second + 1};
	}
};