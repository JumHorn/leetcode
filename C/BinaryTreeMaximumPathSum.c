#include <limits.h>
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

int postorder(struct TreeNode *root, int *res)
{
	if (!root)
		return INT_MIN / 5;	 //a minimal val less than all the node val
	int left = postorder(root->left, res);
	int right = postorder(root->right, res);
	int sum = INT_MIN;
	sum = max(sum, root->val);
	sum = max(sum, root->val + left);
	sum = max(sum, root->val + right);
	*res = max(*res, root->val + left + right);
	*res = max(*res, sum);
	return sum;
}

int maxPathSum(struct TreeNode *root)
{
	int res = INT_MIN;
	postorder(root, &res);
	return res;
}
