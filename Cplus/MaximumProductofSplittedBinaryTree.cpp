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
	int maxProduct(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		long sum = postorder(root), res = 0;
		preorder(root, sum, res);
		return res % MOD;
	}

	void preorder(TreeNode *root, int sum, long &res)
	{
		if (root == nullptr)
			return;
		res = max(res, (long)root->val * (sum - root->val));
		preorder(root->left, sum, res);
		preorder(root->right, sum, res);
	}

	int postorder(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = postorder(root->left);
		int right = postorder(root->right);
		root->val += left + right;
		return root->val;
	}

private:
	static const int MOD = 1e9 + 7;
};