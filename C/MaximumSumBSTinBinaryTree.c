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

typedef struct pair
{
	bool isBST;
	int sum;
	int minval;
	int maxval;
} pair;

pair postorder(struct TreeNode *root, int *maxsum)
{
	if (!root)
	{
		pair res = {true, 0, INT_MAX, INT_MIN};
		return res;
	}
	pair l = postorder(root->left, maxsum);
	pair r = postorder(root->right, maxsum);
	if (l.isBST && r.isBST)
	{
		if (root->val > l.maxval && root->val < r.minval)
		{
			pair res = {true, root->val + l.sum + r.sum, l.minval, r.maxval};
			if (!root->left)
				res.minval = root->val;
			if (!root->right)
				res.maxval = root->val;
			*maxsum = max(*maxsum, res.sum);
			return res;
		}
	}
	pair res = {false, 0, 0, 0};
	return res;
}

int maxSumBST(struct TreeNode *root)
{
	int res = 0;
	postorder(root, &res);
	return res;
}