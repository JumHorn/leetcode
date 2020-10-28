#include <algorithm>
#include <vector>
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
	int longestZigZag(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	pair<int, int> postorder(TreeNode *root, int &res) //{left zag,right zag}
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left, res);
		auto r = postorder(root->right, res);
		res = max({res, l.second, r.first});
		return {1 + l.second, 1 + r.first};
	}
};