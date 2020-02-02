#include <algorithm>
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
	int maxProduct(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		long long sum = getSum(root), res = 0;
		preOrder(root, sum, res);
		return res % MOD;
	}

	void preOrder(TreeNode *root, int sum, long long &res)
	{
		if (root == NULL)
			return;
		long long val = root->val;
		res = max(res, val * (sum - val));
		preOrder(root->left, sum, res);
		preOrder(root->right, sum, res);
	}

	int getSum(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left = getSum(root->left);
		int right = getSum(root->right);
		root->val = left + right + root->val;
		return root->val;
	}

private:
	static const int MOD = 1e9 + 7;
};

