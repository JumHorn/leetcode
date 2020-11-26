#include <limits.h>
#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tuple
{
	bool isBST;
	int sum;
	int minval;
	int maxval;
} tuple;

tuple postorder(struct TreeNode *root, int *maxsum)
{
	if (!root)
	{
		tuple res = {true, 0, INT_MAX, INT_MIN};
		return res;
	}
	tuple l = postorder(root->left, maxsum);
	tuple r = postorder(root->right, maxsum);
	if (l.isBST && r.isBST)
	{
		if (root->val > l.maxval && root->val < r.minval)
		{
			tuple res = {true, root->val + l.sum + r.sum, l.minval, r.maxval};
			if (!root->left)
				res.minval = root->val;
			if (!root->right)
				res.maxval = root->val;
			*maxsum = max(*maxsum, res.sum);
			return res;
		}
	}
	tuple res = {false, 0, 0, 0};
	return res;
}

int maxSumBST(struct TreeNode *root)
{
	int res = 0;
	postorder(root, &res);
	return res;
}