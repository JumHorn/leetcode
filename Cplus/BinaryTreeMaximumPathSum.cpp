#include <algorithm>
#include <climits>
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
	int maxPathSum(TreeNode *root)
	{
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;
	}

	int maxPathSum(TreeNode *root, int &res)
	{
		if (root == NULL)
			return 0;
		int leftmaxv = maxPathSum(root->left, res);
		if (leftmaxv < 0)
			leftmaxv = 0;
		int rightmaxv = maxPathSum(root->right, res);
		if (rightmaxv < 0)
			rightmaxv = 0;
		res = max(res, leftmaxv + rightmaxv + root->val);
		return root->val + max(leftmaxv, rightmaxv);
	}
};