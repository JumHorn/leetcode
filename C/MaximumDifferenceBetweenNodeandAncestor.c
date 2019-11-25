#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(a, b) ((((a) - (b)) >= 0) ? ((a) - (b)) : ((b) - (a)))

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int postorder(struct TreeNode* root, int* big, int* small)
{
	if (!root)
		return 0;
	int res = 0, lmax = INT_MIN, lmin = INT_MAX, rmax = INT_MIN, rmin = INT_MAX;
	int resl = postorder(root->left, &lmax, &lmin);
	int resr = postorder(root->right, &rmax, &rmin);
	*big = max(lmax, rmax);
	*small = min(lmin, rmin);
	if (*big != INT_MIN)
		res = max(res, abs(*big, root->val));
	if (*small != INT_MAX)
		res = max(res, abs(*small, root->val));
	*big = max(*big, root->val);
	*small = min(*small, root->val);
	res = max(res, max(resl, resr));
	return res;
}

int maxAncestorDiff(struct TreeNode* root)
{
	int big = INT_MIN, small = INT_MAX;
	return postorder(root, &big, &small);
}

