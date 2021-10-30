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
		preorder(root, root->val, root->val, res);
		return res;
	}

	void preorder(TreeNode *root, int maxval, int minval, int &diff)
	{
		if (root == nullptr)
			return;
		diff = max(diff, abs(root->val - maxval));
		diff = max(diff, abs(root->val - minval));
		maxval = max(maxval, root->val);
		minval = min(minval, root->val);
		preorder(root->left, maxval, minval, diff);
		preorder(root->right, maxval, minval, diff);
	}
};