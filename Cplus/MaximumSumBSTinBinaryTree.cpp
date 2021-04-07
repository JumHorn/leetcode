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
private:
	struct BST
	{
		int max;
		int min;
		int sum;
	};

public:
	int maxSumBST(TreeNode *root)
	{
		int res = 0;
		postorder(root, res);
		return res;
	}

	BST postorder(TreeNode *root, int &res)
	{
		if (root == nullptr)
			return {INT_MIN, INT_MAX, 0};
		BST left = postorder(root->left, res);
		BST right = postorder(root->right, res);
		if (left.sum != INT_MAX && right.sum != INT_MAX)
		{
			if (root->val > left.max && root->val < right.min)
			{
				res = max(res, root->val + left.sum + right.sum);
				return {max(right.max, root->val), min(left.min, root->val), root->val + left.sum + right.sum};
			}
		}
		return {0, 0, INT_MAX};
	}
};