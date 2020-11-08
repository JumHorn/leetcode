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
	int maxPathSum(TreeNode *root)
	{
		int res = INT_MIN;
		postorder(root, res);
		return res;
	}

	int postorder(TreeNode *root, int &res)
	{
		if (root == nullptr)
			return 0;
		int leftmaxv = max(postorder(root->left, res), 0);
		int rightmaxv = max(postorder(root->right, res), 0);
		res = max(res, leftmaxv + rightmaxv + root->val);
		return root->val + max(leftmaxv, rightmaxv);
	}
};