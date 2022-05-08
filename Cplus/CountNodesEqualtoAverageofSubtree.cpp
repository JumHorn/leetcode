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
	int averageOfSubtree(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	//{sum,count}
	pair<int, int> postorder(TreeNode *root, int &res)
	{
		if (root == nullptr)
			return {0, 0};
		auto l = postorder(root->left, res);
		auto r = postorder(root->right, res);
		int sum = root->val + l.first + r.first;
		int count = 1 + l.second + r.second;
		if (sum / count == root->val)
			++res;
		return {sum, count};
	}
};